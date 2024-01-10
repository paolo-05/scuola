-- CREAZIONE TABELLE
CREATE TABLE CORSIDILAUREA (
    CorsoLaurea INT PRIMARY KEY,
    TipoLaurea VARCHAR(255),
    Facoltà VARCHAR(255)
);

CREATE TABLE DOCENTI (
    CodDocente INT PRIMARY KEY,
    NomeD VARCHAR(255),
    Dipartimento VARCHAR(255)
);

CREATE TABLE CORSI (
    CodCorso INT PRIMARY KEY,
    NomeCorso VARCHAR(255),
    CodDocente INT,
    FOREIGN KEY (CodDocente) REFERENCES DOCENTI(CodDocente)
);

CREATE TABLE STUDENTI (
    Matricola INT PRIMARY KEY,
    NomeS VARCHAR(255),
    CorsoLaurea INT,
    AnnoN INT,
    FOREIGN KEY (CorsoLaurea) REFERENCES CORSIDILAUREA(CorsoLaurea)
);

CREATE TABLE FREQUENTA (
    Matricola INT,
    CodCorso INT,
    PRIMARY KEY (Matricola, CodCorso),
    FOREIGN KEY (Matricola) REFERENCES STUDENTI(Matricola),
    FOREIGN KEY (CodCorso) REFERENCES CORSI(CodCorso)
);

--1. Il nome e l’anno di nascita degli studenti iscritti a SBC, in ordine rispetto al nome:
SELECT NomeS, AnnoN
FROM STUDENTI
WHERE CorsoLaurea IN (SELECT CorsoLaurea FROM CORSIDILAUREA WHERE TipoLaurea = 'SBC')
ORDER BY NomeS;

--2. Il nome ed il Dipartimento dei docenti di “Basi di Dati e Sistemi Informativi” o di “Informatica Generale”:
SELECT NomeD, Dipartimento
FROM DOCENTI
WHERE CodDocente IN (SELECT CodDocente FROM CORSI WHERE NomeCorso IN ('Basi di Dati e Sistemi Informativi', 'Informatica Generale'));

--3. Matricola e nome degli studenti di un corso di laurea triennale (tipoLaurea = 'L') che seguono un corso di un docente di nome Felice:
SELECT Matricola, NomeS
FROM STUDENTI
WHERE CorsoLaurea IN (SELECT CorsoLaurea FROM CORSIDILAUREA WHERE TipoLaurea = 'L')
AND Matricola IN (SELECT Matricola FROM FREQUENTA WHERE CodCorso IN (SELECT CodCorso FROM CORSI WHERE CodDocente IN (SELECT CodDocente FROM DOCENTI WHERE NomeD = 'Felice')));

--4. Per ogni tipo di laurea, il tipoLaurea e l’età media degli studenti:
SELECT TipoLaurea, AVG(YEAR(CURRENT_DATE) - AnnoN) AS MediaEtà
FROM STUDENTI
JOIN CORSIDILAUREA ON STUDENTI.CorsoLaurea = CORSIDILAUREA.CorsoLaurea
GROUP BY TipoLaurea;
--5. Di ogni corso di un docente di nome Leoni, il CodCorso e il numero degli studenti che lo frequentano:
SELECT CodCorso, COUNT(Matricola) AS NumeroStudenti
FROM FREQUENTA
WHERE CodCorso IN (SELECT CodCorso FROM CORSI WHERE CodDocente IN (SELECT CodDocente FROM DOCENTI WHERE NomeD = 'Leoni'))
GROUP BY CodCorso;

--6. Il codice dei corsi frequentati da più di 5 studenti e tenuti da docenti del Dipartimento di Informatica:
SELECT CodCorso
FROM FREQUENTA
WHERE CodCorso IN (SELECT CodCorso FROM CORSI WHERE CodDocente IN (SELECT CodDocente FROM DOCENTI WHERE Dipartimento = 'Informatica'))
GROUP BY CodCorso
HAVING COUNT(Matricola) > 5;

--7. Per ogni studente della Facoltà di Lettere e Filosofia, la matricola ed il numero di corsi seguiti:
SELECT Matricola, COUNT(CodCorso) AS NumeroCorsi
FROM FREQUENTA
WHERE Matricola IN (SELECT Matricola FROM STUDENTI WHERE CorsoLaurea IN (SELECT CorsoLaurea FROM CORSIDILAUREA WHERE Facoltà = 'Lettere e Filosofia'))
GROUP BY Matricola;

--8. Matricola e nome degli studenti che non frequentano nessun corso:
SELECT Matricola, NomeS
FROM STUDENTI
WHERE Matricola NOT IN (SELECT Matricola FROM FREQUENTA);

--9. Il Codice ed il Nome dei docenti dei Corsi che non sono frequentati da nessuno studente:
SELECT CodDocente, NomeD
FROM DOCENTI
WHERE CodDocente IN (SELECT CodDocente FROM CORSI WHERE CodCorso NOT IN (SELECT CodCorso FROM FREQUENTA));

--10. Matricola e nome degli studenti che seguono solo corsi di docenti del dipartimento di Storia:
SELECT Matricola, NomeS
FROM STUDENTI
WHERE Matricola NOT IN (SELECT Matricola FROM FREQUENTA WHERE CodCorso IN (SELECT CodCorso FROM CORSI WHERE CodDocente NOT IN (SELECT CodDocente FROM DOCENTI WHERE Dipartimento = 'Storia')));

--11. Il CodCorso dei corsi seguiti solo da studenti che appartengono al Corso di Laurea Triennale in SBC:
SELECT CodCorso
FROM FREQUENTA
GROUP BY CodCorso
HAVING COUNT(DISTINCT Matricola) = (SELECT COUNT(Matricola) FROM STUDENTI WHERE CorsoLaurea = (SELECT CorsoLaurea FROM CORSIDILAUREA WHERE TipoLaurea = 'L' AND Facoltà = 'SBC'));

--12. Nome e CodDocente dei docenti che insegnano qualche corso seguito da più di 5 studenti:
SELECT DISTINCT NomeD, CodDocente
FROM DOCENTI
WHERE CodDocente IN (SELECT CodDocente FROM CORSI WHERE CodCorso IN (SELECT CodCorso FROM FREQUENTA GROUP BY CodCorso HAVING COUNT(Matricola) > 5));

--13. Codice dei corsi che sono frequentati da tutti gli studenti del CorsoLaurea SBC:
SELECT CodCorso
FROM FREQUENTA
WHERE Matricola NOT IN (SELECT Matricola FROM STUDENTI WHERE CorsoLaurea = (SELECT CorsoLaurea FROM CORSIDILAUREA WHERE TipoLaurea = 'SBC'));




