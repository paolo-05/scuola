<?php
include_once './utils/db.php';
include_once './utils/sanitizeInput.php';
include_once './utils/checkSession.php';

$email = $nome = $cognome = $password = $dataNascita = $sesso = "";
$error = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if($_POST['password'] != $_POST['confirmPassword']){
        $error = "Le password non corrispondono.";
    }
    else {
        // validazione input
        $email = sanitizeInput($_POST["email"]);
        $nome = sanitizeInput($_POST["nome"]);
        $cognome = sanitizeInput($_POST["cognome"]);
        $password = password_hash(sanitizeInput($_POST["password"]),PASSWORD_BCRYPT,  ['cost' => 12]);
        $dataNascita = sanitizeInput($_POST["dataNascita"]);
        $sesso = sanitizeInput($_POST["sesso"]);

        // inserimento nel db dell'utente,
        $sql = "INSERT INTO users (email, nome, cognome, password, dataNascita, sesso) VALUES ('$email', '$nome', '$cognome', '$password', '$dataNascita', '$sesso')";

        if ($conn->query($sql) === TRUE) {
            echo "Registrazione avvenuta con successo!";
            header("Location: login.php");
        } else {
            $error = "Errore: " . $sql . "<br>" . $conn->error;
        }
    }
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registrazione utente</title>
    <link rel="stylesheet" href="./styles/register.css">
</head>
<body>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
    <h2>Registrazione utente</h2>
        <label for="email">Email:</label>
        <input type="email" name="email" required>

        <label for="nome">Nome:</label>
        <input type="text" name="nome" required>

        <label for="cognome">Cognome:</label>
        <input type="text" name="cognome" required>

        <label for="password">Password:</label>
        <input type="password" name="password" required>

        <label for="confirmPassword">Conferma Password:</label>
        <input type="password" name="confirmPassword" required>

        <label for="dataNascita">Date of Birth:</label>
        <input type="date" name="dataNascita" required>

        <label>Sesso:</label>
        <input type="radio" name="sesso" value="M" required>
        <label for="male">Maschio</label>
        <input type="radio" name="sesso" value="F" required>
        <label for="female">Femmina</label>

        <input type="submit" value="Registrati">

        <?php
        // mostra errori
        echo "<p>$error</p>";
        ?>

        Già registrato? <a href="login.php">Login</a>
    </form>
</body>
</html>
