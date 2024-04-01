<?php
// Parametri necessari alla connessione al database
$servername = "localhost:3306";
$username = "root";
$password = "PasswordRoot";
$dbname = "carrello";

// crea la connessione
$conn = new mysqli($servername, $username, $password, $dbname);

// testa la connessione
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}