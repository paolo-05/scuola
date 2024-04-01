<?php
session_start();

if (!isset($_SESSION['utente'])) {
    header("Location: login.php");
    exit();
}

$utente = $_SESSION['utente'];