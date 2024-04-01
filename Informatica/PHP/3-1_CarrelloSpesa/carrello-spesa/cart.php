<?php

include_once './utils/checkSession.php';
include_once './utils/db.php';
include_once './utils/sanitizeInput.php';
include_once './utils/initCart.php';

// recupero dal db i prodotti.
$sql = "SELECT id, nome, prezzoUnitario FROM prodotti";
$result = $conn->query($sql);

// controlla se il form è stato inviato con
// l'intenzione di rimuovere un elemento dal carrello.
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['remove_from_cart'])) {
    $product_id = sanitizeInput($_POST['product_id']);

    // rimizione prodotto dal carrello
    unset($_SESSION['cart'][$product_id]);

    // reset degli indici nell'array
    $_SESSION['cart'] = array_values($_SESSION['cart']);
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Shopping Cart</title>
    <link rel="stylesheet" href="./styles/table.css">
</head>
<body>
    <h2>Carrello della Spesa</h2>

    <table>
        <tr>
            <th>Id Prodotto</th>
            <th>Nome Articolo</th>
            <th>Quantità</th>
            <th>Totale Parziale</th>
            <th>Azioni</th>
        </tr>

        <?php
        $totalCartAmount = 0;

        foreach ($_SESSION['cart'] as $product_id => $quantity) {
            $product_sql = "SELECT id, nome, prezzoUnitario FROM prodotti WHERE id = $product_id";
            $product_result = $conn->query($product_sql);

            if ($product_result->num_rows > 0) {
                $product_row = $product_result->fetch_assoc();
                $partialTotal = $quantity * $product_row['prezzoUnitario'];
                $totalCartAmount += $partialTotal;

                echo "<tr>";
                echo "<td>{$product_row['id']}</td>";
                echo "<td>{$product_row['nome']}</td>";
                echo "<td>$quantity</td>";
                echo "<td>$partialTotal</td>";
                echo "<td><form method='post' action='{$_SERVER["PHP_SELF"]}'>
                        <input type='hidden' name='product_id' value='{$product_row['id']}'>
                        <button type='submit' name='remove_from_cart'><img src='./imm/del.gif'/></button>
                    </form></td>";
                echo "</tr>";
            }
        }
        if (empty($_SESSION['cart'])) {
            echo "<tr><td colspan='5'><h4>Carrello vuoto.</h4></td></tr>";
        }
        ?>
    </table>

    <p>Totale Complessivo: <?php echo $totalCartAmount; ?></p>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <input type="submit" class="empty-cart" name="empty_cart" value="Svuota Carrello">
    </form>

    <?php
    // controlla se il form è stato inviato con l'intenzione di svuotare il carrello.
    if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['empty_cart'])) {
        // Svuota il carrello.
        $_SESSION['cart'] = [];
    }
    ?>

    <a href="index.php" style="margin: 10px;">Vai alla Visualizzazione dei prodotti</a>
</body>
</html>
