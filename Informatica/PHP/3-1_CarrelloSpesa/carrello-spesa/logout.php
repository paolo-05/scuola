<?php
session_start();

// rimozione di tutte le variabili di sessione.
$_SESSION = array();

session_destroy();

// reindirizzamento alla login page.
header("Location: login.php");
exit();

