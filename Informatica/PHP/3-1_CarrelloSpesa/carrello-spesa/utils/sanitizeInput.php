<?php
/**
 * Funzione che sanifica l'input dell'utente.
 * @param $data la stringa da sanificare
 */
function sanitizeInput($data) {
    // rimozione spazi vuoit
    $data = trim($data);
    // rimozione apici
    $data = stripslashes($data);
    // modifica caratteri html
    $data = htmlspecialchars($data);
    return $data;
}