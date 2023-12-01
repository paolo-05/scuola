CREATE DATABASE mobilificio; CREATE TABLE negozi(
    cod INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(255) NOT NULL,
    indirizzo VARCHAR(255) NOT NULL,
    citta VARCHAR(255) NOT NULL,
    telefono VARCHAR(255) NOT NULL
); CREATE TABLE ordini(
    cod INT PRIMARY KEY AUTO_INCREMENT,
    neg_cod INT NOT NULL,
    DATA DATE NOT NULL,
    FOREIGN KEY(neg_cod) REFERENCES negozi(cod)
); CREATE TABLE categorie(
    cod INT PRIMARY KEY AUTO_INCREMENT,
    descrizione TEXT NOT NULL
); CREATE TABLE laboratori(
    cod INT PRIMARY KEY AUTO_INCREMENT,
    indirzzo VARCHAR(255) NOT NULL,
    citta VARCHAR(255) NOT NULL,
    telefono VARCHAR(255) NOT NULL
); CREATE TABLE componenti(
    cod INT PRIMARY KEY AUTO_INCREMENT,
    descrizione TEXT NOT NULL,
    costo DECIMAL(10, 2) NOT NULL,
    lab_cod INT,
    FOREIGN KEY (lab_cod) REFERENCES laboratori(cod)
); CREATE TABLE articoli(
    cod INT PRIMARY KEY AUTO_INCREMENT,
    cat INT NOT NULL,
    descrizione TEXT NOT NULL,
    prezzo DECIMAL(10, 2) NOT NULL,
    iva INT NOT NULL,
    spese_trasporto DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY cat REFERENCES categorie(cod)
); CREATE TABLE compart(
    cod INT NOT NULL,
    com_cod INT NOT NULL,
    qta INT DEFAULT 1,
    FOREIGN KEY(com_cod) REFERENCES componenti(cod),
    FOREIGN KEY (cod) REFERENCES articoli(cod)
); CREATE TABLE ordart(
    ord_cod INT NOT NULL,
    art_cod INT NOT NULL,
    qta INT DEFAULT 1,
    FOREIGN KEY (ord_cod) REFERENCES ordini(cod),
    FOREIGN KEY (art_cod) REFERENCES articoli(cod)
);
