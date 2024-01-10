-- CREAZIONE TABELLE
CREATE TABLE AUTO (
    Targa VARCHAR(20) PRIMARY KEY,
    Marca VARCHAR(50),
    Cilindrata INT,
    Potenza INT,
    CodF VARCHAR(20) REFERENCES PROPRIETARI(CodF),
    CodAss VARCHAR(20) REFERENCES ASSICURAZIONI(CodAss)
);

CREATE TABLE PROPRIETARI (
    CodF VARCHAR(20) PRIMARY KEY,
    Nome VARCHAR(50),
    Residenza VARCHAR(100)
);

CREATE TABLE ASSICURAZIONI (
    CodAss VARCHAR(20) PRIMARY KEY,
    Nome VARCHAR(50),
    Sede VARCHAR(100)
);

CREATE TABLE SINISTRO (
    CodS VARCHAR(20) PRIMARY KEY,
    Localita VARCHAR(100),
    Data DATE
);

CREATE TABLE AUTOCOINVOLTE (
    CodS VARCHAR(20) REFERENCES SINISTRO(CodS),
    Targa VARCHAR(20) REFERENCES AUTO(Targa),
    ImportoDelDanno DECIMAL(10, 2),
    PRIMARY KEY (CodS, Targa)
);

--1. Targa e Marca delle auto di cilindrata superiore a 2000 cc o di potenza superiore a 120 CV:
SELECT Targa, Marca
FROM AUTO
WHERE Cilindrata > 2000 OR Potenza > 120;

--2. Nome del proprietario e Targa delle auto di cilindrata superiore a 2000 cc oppure di potenza superiore a 120 CV:
SELECT P.Nome, A.Targa
FROM PROPRIETARI P
JOIN AUTO A ON P.CodF = A.CodF
WHERE A.Cilindrata > 2000 OR A.Potenza > 120;

--3. Targa e Nome del proprietario delle auto di cilindrata superiore a 2000 cc oppure di potenza superiore a 120 CV, assicurate presso la “SARA”:
SELECT A.Targa, P.Nome
FROM AUTO A
JOIN PROPRIETARI P ON A.CodF = P.CodF
JOIN ASSICURAZIONI ASU ON A.CodAss = ASU.CodAss
WHERE (A.Cilindrata > 2000 OR A.Potenza > 120) AND ASU.Nome = 'SARA';

--4. Targa e Nome del proprietario delle auto assicurate presso la “SARA” e coinvolte in sinistri il 20/01/02:
SELECT A.Targa, P.Nome
FROM AUTO A
JOIN PROPRIETARI P ON A.CodF = P.CodF
JOIN ASSICURAZIONI ASU ON A.CodAss = ASU.CodAss
JOIN AUTOCOINVOLTE AC ON A.Targa = AC.Targa
JOIN SINISTRO S ON AC.CodS = S.CodS
WHERE ASU.Nome = 'SARA' AND S.Data = '2002-01-20';

--5. Per ciascuna Assicurazione, il nome, la sede ed il numero di auto assicurate:
SELECT ASU.Nome, ASU.Sede, COUNT(A.Targa) AS NumeroAutoAssicurate
FROM ASSICURAZIONI ASU
LEFT JOIN AUTO A ON ASU.CodAss = A.CodAss
GROUP BY ASU.Nome, ASU.Sede;

--6. Per ciascuna auto “Fiat”, la targa dell’auto ed il numero di sinistri in cui è stata coinvolta:
SELECT A.Targa, COUNT(AC.CodS) AS NumeroSinistri
FROM AUTO A
LEFT JOIN AUTOCOINVOLTE AC ON A.Targa = AC.Targa
WHERE A.Marca = 'Fiat'
GROUP BY A.Targa;

--7. Per ciascuna auto coinvolta in più di un sinistro, la targa dell’auto, il nome dell’Assicurazione ed il totale dei danni riportati:
SELECT A.Targa, ASU.Nome, SUM(AC.ImportoDelDanno) AS TotaleDanni
FROM AUTO A
JOIN AUTOCOINVOLTE AC ON A.Targa = AC.Targa
JOIN SINISTRO S ON AC.CodS = S.CodS
JOIN ASSICURAZIONI ASU ON A.CodAss = ASU.CodAss
GROUP BY A.Targa, ASU.Nome
HAVING COUNT(AC.CodS) > 1;

--8. CodF e Nome di coloro che possiedono più di un’auto:
SELECT P.CodF, P.Nome
FROM PROPRIETARI P
JOIN AUTO A ON P.CodF = A.CodF
GROUP BY P.CodF, P.Nome
HAVING COUNT(A.Targa) > 1;

--9.La targa delle auto che non sono state coinvolte in sinistri dopo il 20/01/01:
SELECT A.Targa
FROM AUTO A
WHERE NOT EXISTS (
    SELECT 1
    FROM AUTOCOINVOLTE AC
    JOIN SINISTRO S ON AC.CodS = S.CodS
    WHERE A.Targa = AC.Targa AND S.Data > '2001-01-20'
);

--10. Il codice dei sinistri in cui non sono state coinvolte auto con cilindrata inferiore a 2000 cc:
SELECT S.CodS
FROM SINISTRO S
LEFT JOIN AUTOCOINVOLTE AC ON S.CodS = AC.CodS
LEFT JOIN AUTO A ON AC.Targa = A.Targa
WHERE A.Cilindrata < 2000 OR A.Targa IS NULL;
