-- CREAZIONE TABELLE
CREATE TABLE MUSEI(
    NomeM VARCHAR(255) PRIMARY KEY,
    Citta VARCHAR(255)
);
CREATE TABLE ARTISTI(
    NomeA VARCHAR(255) PRIMARY KEY,
    Nazionalita VARCHAR(255)
);
CREATE TABLE OPERE(
    Codice INT PRIMARY KEY AUTO_INCREMENT,
    Titolo VARCHAR(255),
    NomeM REFERENCES MUSEI(NomeM),
    NomeA REFERENCES ARTISTI(NomeA)
);
CREATE TABLE PERSONAGGI(
    Personaggio VARCHAR(255) PRIMARY KEY,
    Codice REFERENCES OPERE(Codice)
);

--1. Il codice ed il titolo delle opere di Tiziano conservate alla “National Gallery”.
SELECT Codice, Titolo
FROM OPERE
WHERE NomeA = 'Tiziano' AND NomeM = 'National Gallery';


--2. Il nome dell’artista ed il titolo delle opere conservate alla “Galleria degli Uffizi” o alla “National Gallery”.
SELECT NomeA, Titolo
FROM OPERE
WHERE NomeM IN ('Galleria degli Uffizi', 'National Gallery');


--3. Il nome dell’artista ed il titolo delle opere conservate nei musei di Firenze
SELECT NomeA, Titolo
FROM OPERE
WHERE NomeM IN (SELECT NomeM FROM MUSEI WHERE Città = 'Firenze');

--4. Città in cui sono conservate opere di Caravaggio
SELECT DISTINCT Città
FROM MUSEI
WHERE NomeM IN (SELECT NomeM FROM OPERE WHERE NomeA = 'Caravaggio');

--5. Codice ed il titolo delle opere di Tiziano conservate nei musei di Londra
SELECT Codice, Titolo
FROM OPERE
WHERE NomeA = 'Tiziano' AND NomeM IN (SELECT NomeM FROM MUSEI WHERE Città = 'Londra');

--6. Nome dell'artista ed il titolo delle opere di artisti spagnoli conservate nei musei di Firenze:
SELECT NomeA, Titolo
FROM OPERE
WHERE NomeA IN (SELECT NomeA FROM ARTISTI WHERE Nazionalità = 'Spagnola')
AND NomeM IN (SELECT NomeM FROM MUSEI WHERE Città = 'Firenze');

--7. Codice ed il titolo delle opere di artisti italiani conservate nei musei di Londra, in cui è rappresentata la Madonna:
SELECT Codice, Titolo
FROM OPERE
WHERE NomeA IN (SELECT NomeA FROM ARTISTI WHERE Nazionalità = 'Italiana')
AND NomeM IN (SELECT NomeM FROM MUSEI WHERE Città = 'Londra')
AND Codice IN (SELECT Codice FROM PERSONAGGI WHERE Personaggio = 'Madonna');

--8. Per ciascun museo di Londra, il numero di opere di artisti italiani ivi conservate:
SELECT NomeM, COUNT(*)
FROM OPERE
WHERE NomeA IN (SELECT NomeA FROM ARTISTI WHERE Nazionalità = 'Italiana')
AND NomeM IN (SELECT NomeM FROM MUSEI WHERE Città = 'Londra')
GROUP BY NomeM;

--9. Nome dei musei di Londra che non conservano opere di Tiziano:
SELECT NomeM
FROM MUSEI
WHERE Città = 'Londra' AND NomeM NOT IN (SELECT NomeM FROM OPERE WHERE NomeA = 'Tiziano');

--10. Nome dei musei di Londra che conservano solo opere di Tiziano:
SELECT NomeM
FROM MUSEI
WHERE Città = 'Londra' AND NomeM IN (SELECT NomeM FROM OPERE WHERE NomeA = 'Tiziano')
AND NomeM NOT IN (SELECT NomeM FROM OPERE WHERE NomeA <> 'Tiziano');

--11. Per ciascun artista, il nome dell'artista ed il numero di sue opere conservate alla "Galleria degli Uffizi":
SELECT NomeA, COUNT(*)
FROM OPERE
WHERE NomeM = 'Galleria degli Uffizi'
GROUP BY NomeA;

--12. I musei che conservano almeno 20 opere di artisti italiani:
SELECT NomeM
FROM OPERE
WHERE NomeA IN (SELECT NomeA FROM ARTISTI WHERE Nazionalità = 'Italiana')
GROUP BY NomeM
HAVING COUNT(*) >= 20;

--13. Per le opere di artisti italiani che non hanno personaggi, il titolo dell'opera ed il nome dell'artista:
SELECT Titolo, NomeA
FROM OPERE
WHERE NomeA IN (SELECT NomeA FROM ARTISTI WHERE Nazionalità = 'Italiana')
AND Codice NOT IN (SELECT Codice FROM PERSONAGGI);

--14. Nome dei musei di Londra che non conservano opere di artisti italiani, eccettuato Tiziano:
SELECT NomeM
FROM MUSEI
WHERE Città = 'Londra' AND NomeM NOT IN (SELECT NomeM FROM OPERE WHERE NomeA = 'Tiziano')
AND NomeM IN (SELECT NomeM FROM OPERE WHERE NomeA IN (SELECT NomeA FROM ARTISTI WHERE Nazionalità = 'Italiana'));

--15. Per ogni museo, il numero di opere divise per la nazionalità dell'artista:
SELECT NomeM, Nazionalità, COUNT(*)
FROM MUSEI
JOIN OPERE ON MUSEI.NomeM = OPERE.NomeM
JOIN ARTISTI ON OPERE.NomeA = ARTISTI.NomeA
GROUP BY NomeM, Nazionalità;
