<?php
    session_start();

    if(!isset($_SESSION['username']) || $_SESSION['username'] !== true) {
        // L'utente non è autenticato, reindirizza alla pagina di login
        header("Location: login.php");
        exit;
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Visualizza</title>
    <link rel="stylesheet" href="/styles/visualizza.css">
</head>
<body>
    <h1>Visualizzando i tosaerba</h1>
    <?php
        include("connessione.php");

        $filterMotore = !isset($_REQUEST['scelta'])
            ? ''
            : ($_REQUEST['scelta'] == 'Tutti i tipi' 
                ? ''
                : $_REQUEST['scelta']);

        $sql = "SELECT * FROM tosaerba";
        if (!empty($filterMotore)) {
            $sql .= " WHERE motore = '$filterMotore'";
        }

        $result = $conn->query($sql);

        if ($result->num_rows > 0) {
            while($row = $result->fetch_assoc()) {
                echo '<div class="container">';
                echo '<img src="/images/' . $row["immagine"] . '" alt="' . $row["modello"] . '" class="image">';
                echo '<strong>' . $row["marca"] . ' ' . $row["modello"] . '</strong><br>';
                echo 'Motore: ' . $row["motore"] . '<br>';
                echo 'Prezzo: €' . number_format($row["prezzo"], 2) . '<br>';
                echo '<a href="modifica.php?codice=' . $row["codice"] . '">Modifica</a> | ';
                echo '<a href="elimina.php?codice=' . $row["codice"] . '" onclick="return confirm(\'Sicuro di voler eliminare?\')">Elimina</a>';
                echo '</div>';
            }
        } else {
            echo "0 results";
        }

        $conn->close();
    ?>
    <div style="text-align: center; margin-top: 20px;">
        <a href="inserisci.php"><button type="button" class="button">Insersisci Tosaerba</button></a>
    </div>
</body>
</html>