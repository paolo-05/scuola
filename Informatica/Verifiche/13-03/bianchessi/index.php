<?php
include "utils/checkSession.php";
include "utils/db.php";

$messaggio = "";

if(isset($_REQUEST['successo'])){
    $messaggio = "Inserimento PC avvenuto con successo!";
}
?>

<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Visualizzazione dei computer</title>
</head>
<body>
    <h1>Lista computer</h1>
    <h4>Benvenuto <?= $utente ?></h4>
    <table border style="margin: 0 auto;">
        <thead>
            <tr>
                <th>ID</th>
                <th>Modello</th>
                <th>Marca</th>
                <th>Immagine</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $sql = "SELECT * FROM computer";
            $result = $conn->query($sql);
            if($result->num_rows > 0) {
                while($row = $result->fetch_assoc()) {
                    echo "<tr>";
                    echo "<td>".$row['idComputer']."</td>";
                    echo "<td>".$row['modello']."</td>";
                    echo "<td>".$row['marca']."</td>";
                    echo "<td><img src='/imgComputer/".$row['img']."' alt='immagine'></td>";
                    echo "</tr>";
                }
            }
            ?>
        </tbody>
    </table>
    <hr>
    <div style="text-align: center;">
        <a href="nuovoComputer.php"><img src="/imgComputer/Aggiungi.jpg" alt="aggiungi" width="64px"/></a>
        <a href="logout.php"><img src="/imgComputer/logout.jpg" alt="logout" width="64px"/></a>
    </div>

    <?= $messaggio ?>
</body>
</html>
