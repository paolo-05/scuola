<?php
// controlla se esiste un carrello nella sessione, non c'è lo crea.
if (!isset($_SESSION['cart'])) {
    $_SESSION['cart'] = [];
}