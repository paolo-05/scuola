CREATE TABLE users (
    id INT PRIMARY KEY AUTO_INCREMENT,
    email VARCHAR(255) NOT NULL,
    nome VARCHAR(255) NOT NULL,
    cognome VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    dataNascita DATE NOT NULL,
    sesso VARCHAR(2) NOT NULL
);

CREATE TABLE prodotti (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(255) NOT NULL,
    descrizione TEXT NOT NULL,
    prezzoUnitario DECIMAL(10,2) NOT NULL,
    immagine VARCHAR(255) NOT NULL
);