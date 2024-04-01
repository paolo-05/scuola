<?php
include "utils/checkSession.php";
include "utils/db.php";
include "utils/sanitizeInput.php";

$marca = $modello = $immagine = $error = "";

if($_SERVER['REQUEST_METHOD'] == "POST") {
    if (empty($_POST['marca']) || empty($_POST['modello']) || empty($_POST['immagine'])) {
        $error = "Campi obbligatori";
    }
    else {
        $marca = sanitizeInput($_POST['marca']);
        $modello = sanitizeInput($_POST['modello']);
        $immagine = sanitizeInput($_POST['immagine']);

        $sql = "INSERT INTO computer (modello, marca, img) VALUES ('$modello', '$marca', '$immagine')";
        if($conn->query($sql) === TRUE) {
            header("Location: index.php?successo");
            exit();
        } else {
            $error = "Errore inserimento: " . $conn->error;
        }
    }
}
?>

<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Inserimento Nuovo Computer</title>
</head>
<body>
    <div style="text-align: right;">
        <h4>Utente: <?= $utente ?></h4>
    </div>

    <h1>Inserimento nuovo computer</h1>

    <form action="<?= $_SERVER['PHP_SELF'] ?>" method="post">
        <label for="modello">Modello:</label>
        <input type="text" name="modello" id="modello">
        <br>
        <br>
        <label for="marca">Marca:</label>
        <input type="text" name="marca" id="marca">
        <br>
        <br>
        <label for="immagine">Immagine:</label>
        <input type="file" name="immagine" id="immagine">
        <br>
        <br>
        <input type="reset" value="Cancella">
        <input type="submit" value="Invia">
    </form>
    <br>
    <?= $error ?>

    <hr>
    <div style="text-align: center;">
        <a href="index.php"><img src="/imgComputer/elenco.jpg" alt="aggiungi" width="64px"/></a>
        <a href="logout.php"><img src="/imgComputer/logout.jpg" alt="logout" width="64px"/></a>
    </div>
</body>
</html>