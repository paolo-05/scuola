<?php
session_start();

include "utils/db.php";
include "utils/sanitizeInput.php";

if(isset($_SESSION['utente'])){
    header("Location: index.php");
    exit();
}

$codice = $error = "";

if($_SERVER['REQUEST_METHOD'] == "POST") {
    if (empty($_POST['codice'])) {
        $error = "Inserisci il codice";
    }
    else {
        $codice = sanitizeInput($_POST['codice']);

        $sql = "SELECT nome, cognome FROM utenti WHERE codiceAccesso = '$codice'";
        $result = $conn->query($sql);

        if($result->num_rows > 0) {
            $row = $result->fetch_assoc();
            $_SESSION['utente'] = $row['nome']." ".$row['cognome'];
            header("Location: index.php");
            exit();
        } else {
            $error = "Codice errato";
        }
    }
}

?>
<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
</head>
<body>
    <h1>Accesso Lista Computer</h1>
    <form action="<?= $_SERVER['PHP_SELF'] ?>" method="post">
        <label for="codice">Codice Accesso:</label>
        <input type="text" name="codice" id="codice">
        <input type="submit" value="Invia">
    </form>

    <?= $error ?>
</body>
</html>