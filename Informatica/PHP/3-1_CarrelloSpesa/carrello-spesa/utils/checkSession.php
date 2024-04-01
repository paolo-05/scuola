<?php
session_start();

if (!isset($_SESSION['user_id'])) {
    // Se l'utente non è loggato rendirizziamo alla pagina di login
    header("Location: login.php");
    exit();
}