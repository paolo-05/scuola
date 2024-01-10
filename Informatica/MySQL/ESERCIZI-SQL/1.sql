-- creazione tabelle --
CREATE TABLE ATTORI(
	CodAttore INT PRIMARY KEY AUTO_INCREMENT,
	Nome VARCHAR(255),
	AnnoNascita DATE,
	Nazionalita VARCHAR(255)
);

CREATE TABLE FILM(
	CodFilm INT PRIMARY KEY AUTO_INCREMENT,
	Titolo VARCHAR(255),
	AnnoProduzione INT,
	Nazionalita VARCHAR(255),
	Regista VARCHAR(255),
	Genere VARCHAR(255)
);

CREATE TABLE SALE(
	CodSala INT PRIMARY KEY AUTO_INCREMENT,
	Posti INT,
	Nome VARCHAR(255),
	Citta VARCHAR(255)
);

CREATE TABLE RECITA(
	CodAttore REFERENCES ATTORI(CodAttore),
	CodFilm REFERENCES FILM(CodFilm)
);

CREATE TABLE PROIEZIONI(
	CodProiezione INT PRIMARY KEY AUTO_INCREMENT,
	CodFilm REFERENCES FILM(CodFilm),
	CodSala REFERENCES SALE(CodSale),
	Incasso DECIMAL(15,2),
	DataProiezione DATE
);

-- 1) Il nome di tutte le sale di Pisa:
SELECT Nome
FROM SALE
WHERE Città = 'Pisa';

-- 2) Il titolo dei film di F. Fellini prodotti dopo il 1960:
SELECT Titolo
FROM FILM
WHERE Regista = 'F. Fellini' AND AnnoProduzione > 1960;

-- 3) Il titolo e la durata dei film di fantascienza giapponesi o francesi prodotti dopo il 1990:
SELECT Titolo, Durata
FROM FILM
WHERE (Genere = 'fantascienza' AND Nazionalità = 'giapponese' OR Nazionalità = 'francese') AND AnnoProduzione > 1990;

-- 4) Il titolo dei film di fantascienza giapponesi prodotti dopo il 1990 oppure francesi:
SELECT Titolo
FROM FILM
WHERE (Genere = 'fantascienza' AND Nazionalità = 'giapponese' AND AnnoProduzione > 1990) OR Nazionalità = 'francese';

-- 5) I titolo dei film dello stesso regista di "Casablanca":
SELECT Titolo
FROM FILM
WHERE Regista = (SELECT Regista FROM FILM WHERE Titolo = 'Casablanca');


-- 6) Il titolo ed il genere dei film proiettati il giorno di Natale 2004:
SELECT DISTINCT FILM.Titolo, FILM.Genere
FROM FILM
JOIN PROIEZIONI ON FILM.CodFilm = PROIEZIONI.CodFilm
WHERE PROIEZIONI.DataProiezione = '2004-12-25';

-- 7) Il titolo ed il genere dei film proiettati a Napoli il giorno di Natale 2004:
SELECT DISTINCT FILM.Titolo, FILM.Genere
FROM FILM
JOIN PROIEZIONI ON FILM.CodFilm = PROIEZIONI.CodFilm
JOIN SALE ON PROIEZIONI.CodSala = SALE.CodSala
WHERE PROIEZIONI.DataProiezione = '2004-12-25' AND SALE.Città = 'Napoli';


-- 8) I nomi delle sale di Napoli in cui il giorno di Natale 2004 è stato proiettato un film con R.Williams:
SELECT SALE.Nome
FROM SALE
JOIN PROIEZIONI ON SALE.CodSala = PROIEZIONI.CodSala
JOIN FILM ON PROIEZIONI.CodFilm = FILM.CodFilm
JOIN RECITA ON FILM.CodFilm = RECITA.CodFilm
JOIN ATTORI ON RECITA.CodAttore = ATTORI.CodAttore
WHERE PROIEZIONI.DataProiezione = '2004-12-25' AND SALE.Città = 'Napoli' AND ATTORI.Nome = 'R.Williams';


-- 9) Il titolo dei film in cui recita M. Mastroianni oppure S.Loren:
SELECT DISTINCT FILM.Titolo
FROM FILM
JOIN RECITA ON FILM.CodFilm = RECITA.CodFilm
JOIN ATTORI ON RECITA.CodAttore = ATTORI.CodAttore
WHERE ATTORI.Nome = 'M. Mastroianni' OR ATTORI.Nome = 'S.Loren';


-- 10) Il titolo dei film in cui recitano M. Mastroianni e S.Loren:
SELECT DISTINCT FILM.Titolo
FROM FILM
JOIN RECITA AS R1 ON FILM.CodFilm = R1.CodFilm
JOIN ATTORI AS A1 ON R1.CodAttore = A1.CodAttore
JOIN RECITA AS R2 ON FILM.CodFilm = R2.CodFilm
JOIN ATTORI AS A2 ON R2.CodAttore = A2.CodAttore
WHERE (A1.Nome = 'M. Mastroianni' AND A2.Nome = 'S.Loren') OR (A1.Nome = 'S.Loren' AND A2.Nome = 'M. Mastroianni');


-- 11) Per ogni film in cui recita un attore francese, il titolo del film e il nome dell’attore:
SELECT FILM.Titolo, ATTORI.Nome
FROM FILM
JOIN RECITA ON FILM.CodFilm = RECITA.CodFilm
JOIN ATTORI ON RECITA.CodAttore = ATTORI.CodAttore
WHERE ATTORI.Nazionalità = 'francese';

-- 12) Per ogni film che è stato proiettato a Pisa nel gennaio 2005, il titolo del film e il nome della sala:
SELECT FILM.Titolo, SALE.Nome
FROM FILM
JOIN PROIEZIONI ON FILM.CodFilm = PROIEZIONI.CodFilm
JOIN SALE ON PROIEZIONI.CodSala = SALE.CodSala
WHERE PROIEZIONI.DataProiezione BETWEEN '2005-01-01' AND '2005-01-31' AND SALE.Città = 'Pisa';

-- 13) Il numero di sale di Pisa con più di 60 posti:
SELECT COUNT(*)
FROM SALE
WHERE SALE.Città = 'Pisa' AND SALE.Posti > 60;

-- 14) Il numero totale di posti nelle sale di Pisa:
SELECT SUM(Posti)
FROM SALE
WHERE SALE.Città = 'Pisa';

-- 15) Per ogni città, il numero di sale:
SELECT SALE.Città, COUNT(*)
FROM SALE
GROUP BY SALE.Città;

-- 16) Per ogni città, il numero di sale con più di 60 posti:
SELECT SALE.Città, COUNT(*)
FROM SALE
WHERE SALE.Posti > 60
GROUP BY SALE.Città;

-- 17) Per ogni regista, il numero di film diretti dopo il 1990
SELECT Regista, COUNT(*)
FROM FILM
WHERE AnnoProduzione > 1990
GROUP BY Regista;

-- 18) Per ogni regista, l’incasso totale di tutte le proiezioni dei suoi film:
SELECT FILM.Regista, SUM(PROIEZIONI.Incasso) AS IncassoTotale
FROM FILM
JOIN PROIEZIONI ON FILM.CodFilm = PROIEZIONI.CodFilm
GROUP BY FILM.Regista;


-- 19) Per ogni film di S. Spielberg, il titolo del film, il numero totale di proiezioni a Pisa e l’incasso totale:
SELECT FILM.Titolo, COUNT(*) AS NumeroProiezioni, SUM(PROIEZIONI.Incasso) AS IncassoTotale
FROM FILM
JOIN PROIEZIONI ON FILM.CodFilm = PROIEZIONI.CodFilm
JOIN SALE ON PROIEZIONI.CodSala = SALE.CodSala
WHERE FILM.Regista = 'S. Spielberg' AND SALE.Città = 'Pisa'
GROUP BY FILM.Titolo;

-- 20) Per ogni regista e per ogni attore, il numero di film del regista con l’attore:
SELECT FILM.Regista, ATTORI.Nome, COUNT(*) AS NumeroFilm
FROM FILM
JOIN RECITA ON FILM.CodFilm = RECITA.CodFilm
JOIN ATTORI ON RECITA.CodAttore = ATTORI.CodAttore
GROUP BY FILM.Regista, ATTORI.Nome;

-- 21) Il regista ed il titolo dei film in cui recitano meno di 6 attori:
SELECT FILM.Regista, FILM.Titolo
FROM FILM
JOIN RECITA ON FILM.CodFilm = RECITA.CodFilm
GROUP BY FILM.Regista, FILM.Titolo
HAVING COUNT(RECITA.CodAttore) < 6;

-- 22) Per ogni film prodotto dopo il 2000, il codice, il titolo e l’incasso totale di tutte le sue proiezioni:
SELECT FILM.CodFilm, FILM.Titolo, SUM(PROIEZIONI.Incasso) AS IncassoTotale
FROM FILM
JOIN PROIEZIONI ON FILM.CodFilm = PROIEZIONI.CodFilm
WHERE FILM.AnnoProduzione > 2000
GROUP BY FILM.CodFilm, FILM.Titolo;

-- 23) Il numero di attori dei film in cui appaiono solo attori nati prima del 1970:
SELECT COUNT(DISTINCT RECITA.CodAttore) AS NumeroAttori
FROM RECITA
JOIN ATTORI ON RECITA.CodAttore = ATTORI.CodAttore
WHERE NOT EXISTS (
    SELECT *
    FROM ATTORI AS A
    WHERE A.AnnoNascita > 1970 AND A.CodAttore = RECITA.CodAttore
);

-- 24) Per ogni film di fantascienza, il titolo e l’incasso totale di tutte le sue proiezioni:
SELECT FILM.Titolo, SUM(PROIEZIONI.Incasso) AS IncassoTotale
FROM FILM
JOIN PROIEZIONI ON FILM.CodFilm = PROIEZIONI.CodFilm
WHERE FILM.Genere = 'fantascienza'
GROUP BY FILM.Titolo;

-- 25) Per ogni film di fantascienza il titolo e l’incasso totale di tutte le sue proiezioni successive al 1/1/01:
SELECT FILM.Titolo, SUM(PROIEZIONI.Incasso) AS IncassoTotale
FROM FILM
JOIN PROIEZIONI ON FILM.CodFilm = PROIEZIONI.CodFilm
WHERE FILM.Genere = 'fantascienza' AND PROIEZIONI.DataProiezione > '2001-01-01'
GROUP BY FILM.Titolo;

-- 26) Per ogni film di fantascienza che non è mai stato proiettato prima del 1/1/01 il titolo e l’incasso totale di tutte le sue proiezioni:
SELECT FILM.Titolo, SUM(PROIEZIONI.Incasso) AS IncassoTotale
FROM FILM
JOIN PROIEZIONI ON FILM.CodFilm = PROIEZIONI.CodFilm
WHERE FILM.Genere = 'fantascienza'
GROUP BY FILM.Titolo
HAVING MIN(PROIEZIONI.DataProiezione) > '2001-01-01';


-- 27) Per ogni sala di Pisa, che nel mese di gennaio 2005 ha incassato più di 20000 €, il nome della sala e l’incasso totale (sempre del mese di gennaio 2005):
SELECT SALE.Nome, SUM(PROIEZIONI.Incasso) AS IncassoTotale
FROM SALE
JOIN PROIEZIONI ON SALE.CodSala = PROIEZIONI.CodSala
WHERE SALE.Città = 'Pisa' AND EXTRACT(MONTH FROM PROIEZIONI.DataProiezione) = 1 AND EXTRACT(YEAR FROM PROIEZIONI.DataProiezione) = 2005
GROUP BY SALE.Nome
HAVING IncassoTotale > 20000;

-- 28) I titoli dei film che non sono mai stati proiettati a Pisa:
SELECT FILM.Titolo
FROM FILM
WHERE FILM.CodFilm NOT IN (SELECT CodFilm FROM PROIEZIONI WHERE CodSala IN (SELECT CodSala FROM SALE WHERE Città = 'Pisa'));

-- 29) I titoli dei film che sono stati proiettati solo a Pisa:
SELECT FILM.Titolo
FROM FILM
WHERE FILM.CodFilm IN (SELECT CodFilm FROM PROIEZIONI WHERE CodSala IN (SELECT CodSala FROM SALE WHERE Città = 'Pisa'))
  AND FILM.CodFilm NOT IN (SELECT CodFilm FROM PROIEZIONI WHERE CodSala NOT IN (SELECT CodSala FROM SALE WHERE Città = 'Pisa'));


-- 30) I titoli dei film dei quali non vi è mai stata una proiezione con incasso superiore a 500 €:
SELECT DISTINCT FILM.Titolo
FROM FILM
WHERE FILM.CodFilm NOT IN (SELECT CodFilm FROM PROIEZIONI WHERE Incasso > 500);

-- 31) I titoli dei film le cui proiezioni hanno sempre ottenuto un incasso superiore a 500 €:
SELECT DISTINCT FILM.Titolo
FROM FILM
WHERE FILM.CodFilm NOT IN (SELECT CodFilm FROM PROIEZIONI WHERE Incasso <= 500);

-- 32) Il nome degli attori italiani che non hanno mai recitato in film di Fellini:
SELECT DISTINCT ATTORI.Nome
FROM ATTORI
WHERE ATTORI.Nazionalità = 'italiana'
  AND ATTORI.CodAttore NOT IN (SELECT CodAttore FROM RECITA WHERE CodFilm IN (SELECT CodFilm FROM FILM WHERE Regista = 'F. Fellini'));

-- 33) Il titolo dei film di Fellini in cui non recitano attori italiani:
SELECT DISTINCT FILM.Titolo
FROM FILM
WHERE FILM.Regista = 'F. Fellini'
  AND FILM.CodFilm NOT IN (SELECT CodFilm FROM RECITA WHERE CodAttore IN (SELECT CodAttore FROM ATTORI WHERE Nazionalità = 'italiana'));

-- 34) Il titolo dei film senza attori:
SELECT FILM.Titolo
FROM FILM
WHERE FILM.CodFilm NOT IN (SELECT CodFilm FROM RECITA);

-- 35) Gli attori che prima del 1960 hanno recitato solo nei film di Fellini:
SELECT DISTINCT ATTORI.Nome
FROM ATTORI
WHERE ATTORI.CodAttore IN (SELECT CodAttore FROM RECITA WHERE CodFilm IN (SELECT CodFilm FROM FILM WHERE Regista = 'F. Fellini'))
  AND ATTORI.CodAttore NOT IN (SELECT CodAttore FROM RECITA WHERE CodFilm NOT IN (SELECT CodFilm FROM FILM WHERE Regista = 'F. Fellini') AND EXTRACT(YEAR FROM (SELECT DataProiezione FROM PROIEZIONI WHERE CodFilm = RECITA.CodFilm LIMIT 1)) < 1960);

-- 36) Gli attori che hanno recitato in film di Fellini solo prima del 1960:
SELECT DISTINCT ATTORI.Nome
FROM ATTORI
WHERE ATTORI.CodAttore IN (SELECT CodAttore FROM RECITA WHERE CodFilm IN (SELECT CodFilm FROM FILM WHERE Regista = 'F. Fellini'))
  AND ATTORI.CodAttore NOT IN (SELECT CodAttore FROM RECITA WHERE CodFilm IN (SELECT CodFilm FROM FILM WHERE Regista = 'F. Fellini') AND EXTRACT(YEAR FROM (SELECT DataProiezione FROM PROIEZIONI WHERE CodFilm = RECITA.CodFilm LIMIT 1)) >= 1960);
