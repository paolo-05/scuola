<?php
    session_start();

    if(!isset($_SESSION['username']) || $_SESSION['username'] !== true) {
        // L'utente non è autenticato, reindirizza alla pagina di login
        header("Location: login.php");
        exit;
    }

    include("connessione.php");

    // Check if 'codice' parameter is set in the URL
    $codice = isset($_GET['codice']) ? $_GET['codice'] : '';

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Process form data for modification
        $marca = $_POST["marca"];
        $modello = $_POST["modello"];
        $motore = $_POST["motore"];
        $prezzo = $_POST["prezzo"];
        $immagine = $_POST["immagine"];

        $sql = "UPDATE tosaerba SET marca='$marca', modello='$modello', motore='$motore', prezzo=$prezzo, immagine='$immagine' WHERE codice='$codice'";
        $conn->query($sql);

        // Redirect to the display page after modification
        header("Location: visualizza.php");
        exit();
    }

    // Retrieve the existing record for pre-filling the form
    $sql = "SELECT * FROM tosaerba WHERE codice='$codice'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
    } else {
        // Redirect to the display page if the record is not found
        header("Location: visualizza.php");
        exit();
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit Tosaerba</title>
   <link rel="stylesheet" href="/styles/form.css">
</head>
<body>
    <h2>Edit Tosaerba</h2>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <label for="marca">Marca:</label>
        <input type="text" name="marca" value="<?php echo $row["marca"]; ?>" required>

        <label for="modello">Modello:</label>
        <input type="text" name="modello" value="<?php echo $row["modello"]; ?>" required>

        <label for="motore">Motore:</label>
        <input type="text" name="motore" value="<?php echo $row["motore"]; ?>" required>

        <label for="prezzo">Prezzo:</label>
        <input type="number" name="prezzo" step="0.01" value="<?php echo $row["prezzo"]; ?>" required>

        <label for="immagine">Immagine:</label>
        <input type="file" name="immagine" value="<?php echo $row["immagine"]; ?>" required>

        <input type="submit" value="Modifica">
    </form>
</body>
</html>
