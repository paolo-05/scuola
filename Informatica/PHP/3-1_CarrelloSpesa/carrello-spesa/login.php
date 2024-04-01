<?php

include_once('./utils/db.php');
include_once('./utils/sanitizeInput.php');

session_start();

if (isset($_SESSION['user_id'])) {
    // se l'utente è già loggato allora reindirzziamo all'index
    header("Location: index.php");
    exit();
}

$email = $password = "";
$error = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // validazione input
    $email = sanitizeInput($_POST["email"]);
    $password = sanitizeInput($_POST["password"]);

    // controllo delle credenziali
    $sql = "SELECT id, password FROM users WHERE email = '$email'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
        if (password_verify($password, $row["password"])) {
            // Login avventuto con successo, inizializzazione sessione
            // e reindirizzamento alla pagina con i prodotti.
            $_SESSION['user_id'] = $row["id"];
            header("Location: index.php");
            exit();
        } else {
            $error = "Email o password errate";
        }
    } else {
        $error = "Email o passowrd errate";
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login utente</title>
    <link rel="stylesheet" href="./styles/login.css">
</head>

<body>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <h2>User Login</h2>
        <label for="email">Email:</label>
        <input type="email" name="email" required>

        <label for="password">Password:</label>
        <input type="password" name="password" required>

        <input type="submit" value="Login">
        <?php
        // mostra errori
        echo "<p>$error</p>";
        ?>
        Non sei registrato? <a href="register.php">Registrati</a>
    </form>
</body>
</html>
