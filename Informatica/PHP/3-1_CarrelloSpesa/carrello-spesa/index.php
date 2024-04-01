<?php

include_once './utils/checkSession.php';
include_once './utils/db.php';
include_once './utils/sanitizeInput.php';
include_once './utils/initCart.php';

// recupero prodotti dal db
$sql = "SELECT id, nome, descrizione, prezzoUnitario, immagine FROM prodotti";
$result = $conn->query($sql);


// controlla se il form è stato inviato con
//l'intenzione di aggiungere elementi al carrello.
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['add_to_cart'])) {
    $product_id = sanitizeInput($_POST['product_id']);

    // incrementa la quantità oppure aggiunta al carrello
    $_SESSION['cart'][$product_id] = isset($_SESSION['cart'][$product_id]) ? $_SESSION['cart'][$product_id] + 1 : 1;
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Visualizzazione prodotti</title>
    <link rel="stylesheet" href="./styles/table.css">
</head>
<body>
    <form method="post" action="logout.php">
        <input type="submit" class="logout" value="Logout">
    </form>

    <form method="post" action="cart.php">
        <input type="submit" class="view-cart" value="Visualizza Carrello">
    </form>

    <h2>Visualizzazione prodotti</h2>

    <table>
        <tr>
            <th>ID</th>
            <th>Nome</th>
            <th>Descrizione</th>
            <th>Prezzo Unitario</th>
            <th>Immagine</th>
            <th>Azioni</th>
        </tr>

        <?php
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>{$row['id']}</td>";
            echo "<td>{$row['nome']}</td>";
            echo "<td>{$row['descrizione']}</td>";
            echo "<td>{$row['prezzoUnitario']}</td>";
            echo "<td><img src='{$row['immagine']}' alt='Product Image'></td>";
            echo "<td><form method='post' action='{$_SERVER["PHP_SELF"]}'>
                    <input type='hidden' name='product_id' value='{$row['id']}'>
                    <button type='submit' name='add_to_cart' title='Aggiungi al carrello'><img src='./imm/car.png'/></button>
                </form></td>";
            echo "</tr>";
        }
        ?>
    </table>
</body>
</html>
