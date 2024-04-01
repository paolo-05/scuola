<?php
    session_start();

    if(!isset($_SESSION['username']) || $_SESSION['username'] !== true) {
        // L'utente non è autenticato, reindirizza alla pagina di login
        header("Location: login.php");
        exit;
    }

    include("connessione.php");

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Process form data for insertion
        $marca = $_POST["marca"];
        $modello = $_POST["modello"];
        $motore = $_POST["motore"];
        $prezzo = $_POST["prezzo"];
        $immagine = $_POST["immagine"];

        $sql = "INSERT INTO tosaerba (marca, modello, motore, prezzo, immagine) VALUES ('$marca', '$modello', '$motore', $prezzo, '$immagine')";
        $conn->query($sql);

        // Redirect to the display page after insertion
        header("Location: visualizza.php");
        exit();
    }
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Inseresci Tosaerba</title>
    <link rel="stylesheet" href="/styles/form.css">
</head>
<body>
    <h2>Inserisci Tosaerba</h2>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <label for="marca">Marca:</label>
        <input type="text" name="marca" required><br>

        <label for="modello">Modello:</label>
        <input type="text" name="modello" required><br>

        <label for="motore">Motore:</label>
        <input type="text" name="motore" required><br>

        <label for="prezzo">Prezzo:</label>
        <input type="number" name="prezzo" step="0.01" required><br>

        <label for="immagine">Immagine:</label>
        <input type="file" name="immagine" required><br>

        <input type="submit" value="Inserisci">
    </form>
</body>
</html>
