-- CREAZIONE TABELLE
CREATE TABLE ROMANZI (
    CodiceR INT PRIMARY KEY,
    Titolo VARCHAR(255),
    NomeAut VARCHAR(255) REFERENCES AUTORI(NomeAut),
    Anno INT
);

CREATE TABLE PERSONAGGI (
    NomeP VARCHAR(255) PRIMARY KEY,
    CodiceR INT REFERENCES ROMANZI(CodiceR),
    Sesso VARCHAR(1),
    Ruolo VARCHAR(255)
);

CREATE TABLE AUTORI (
    NomeAut VARCHAR(255) PRIMARY KEY,
    AnnoN INT,
    AnnoM INT,
    Nazione VARCHAR(255)
);

CREATE TABLE FILM (
    CodiceF INT PRIMARY KEY,
    Titolo VARCHAR(255),
    Regista VARCHAR(255),
    Produttore VARCHAR(255),
    Anno INT,
    CodiceR INT REFERENCES ROMANZI(CodiceR)
);

-- 1. Il titolo dei romanzi del 19° secolo:
SELECT Titolo
FROM ROMANZI
WHERE Anno BETWEEN 1800 AND 1899;

--2. Il titolo, l'autore e l'anno di pubblicazione dei romanzi di autori russi, ordinati per autore e, per lo stesso autore, ordinati per anno di pubblicazione:
SELECT r.Titolo, a.NomeAut, r.Anno
FROM ROMANZI r
JOIN AUTORI a ON r.NomeAut = a.NomeAut
WHERE a.Nazione = 'Russia'
ORDER BY a.NomeAut, r.Anno;

--3. I personaggi principali (ruolo="P") dei romanzi di autori viventi:
SELECT p.NomeP
FROM PERSONAGGI p
JOIN ROMANZI r ON p.CodiceR = r.CodiceR
JOIN AUTORI a ON r.NomeAut = a.NomeAut
WHERE a.AnnoM IS NULL;

--4. I romanzi dai quali è stato tratto un film con lo stesso titolo del romanzo:
SELECT r.Titolo
FROM ROMANZI r
JOIN FILM f ON r.CodiceR = f.CodiceR
WHERE r.Titolo = f.Titolo;

--5. Il titolo, il regista e l'anno dei film tratti dal romanzo "Robin Hood":
SELECT f.Titolo, f.Regista, f.Anno
FROM ROMANZI r
JOIN FILM f ON r.CodiceR = f.CodiceR
WHERE r.Titolo = 'Robin Hood';

--6. Per ogni autore italiano, l'anno del primo e dell'ultimo romanzo:
SELECT a.NomeAut, MIN(r.Anno) AS AnnoPrimoRomanzo, MAX(r.Anno) AS AnnoUltimoRomanzo
FROM AUTORI a
JOIN ROMANZI r ON a.NomeAut = r.NomeAut
WHERE a.Nazione = 'Italia'
GROUP BY a.NomeAut;

--7. I nomi dei personaggi che compaiono in più di un romanzo, ed il numero dei romanzi nei quali compaiono:
SELECT p.NomeP, COUNT(p.NomeP) AS NumeroRomanzi
FROM PERSONAGGI p
GROUP BY p.NomeP
HAVING COUNT(p.NomeP) > 1;

--8. I romanzi di autori italiani dai quali è stato tratto più di un film:
SELECT r.Titolo, a.NomeAut, COUNT(f.CodiceF) AS NumeroFilm
FROM ROMANZI r
JOIN AUTORI a ON r.NomeAut = a.NomeAut
JOIN FILM f ON r.CodiceR = f.CodiceR
WHERE a.Nazione = 'Italia'
GROUP BY r.Titolo, a.NomeAut
HAVING COUNT(f.CodiceF) > 1;

--9. Il titolo dei romanzi dai quali non è stato tratto un film:
SELECT r.Titolo
FROM ROMANZI r
LEFT JOIN FILM f ON r.CodiceR = f.CodiceR
WHERE f.CodiceF IS NULL;

--10. Il titolo dei romanzi i cui personaggi principali sono tutti femminili:
SELECT r.Titolo
FROM ROMANZI r
JOIN PERSONAGGI p ON r.CodiceR = p.CodiceR
WHERE NOT EXISTS (
    SELECT 1
    FROM PERSONAGGI
    WHERE CodiceR = r.CodiceR AND Sesso = 'M'
);
