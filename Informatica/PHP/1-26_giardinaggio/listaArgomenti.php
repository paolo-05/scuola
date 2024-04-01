<?php
    session_start();

    if(!isset($_SESSION['username']) || $_SESSION['username'] !== true) {
        // L'utente non è autenticato, reindirizza alla pagina di login
        header("Location: login.php");
        exit;
    }

    include("connessione.php");
    $sql = "SELECT DISTINCT motore FROM tosaerba";
    $result = $conn->query($sql);

    $scelta = '<select name="scelta"><option>Tutti i tipi</option>';

    if($result->num_rows > 0){
        while($row=$result->fetch_assoc()){
            $scelta.='<option value="'.$row["motore"].'">'.$row["motore"].'</option>';
        }
    }
    $scelta.='</select>';
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Lista Argomenti</title>
    <link rel="stylesheet" href="/styles/listaArgomenti.css">
</head>
<body>
    <h1>Lista argomenti</h1>
    <form name="f2" action="visualizza.php" method="GET">
        <fieldset>
            <legend>Scelta</legend>
            <p><?php echo $scelta ?></p>
            <p><input type="submit" value="invia"></p>
        </fieldset>
    </form>
</body>
</html>