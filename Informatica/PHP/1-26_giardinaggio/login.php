<?php
session_start(); // Start the session

// Verifica se l'utente è già autenticato e reindirizza alla pagina successiva se lo è
if(isset($_SESSION['username']) && $_SESSION['username'] === true) {
    header("Location: visualizza.php");
    exit;
}

include_once('connessione.php');

// Function to sanitize input data
function sanitizeInput($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}

// Initialize variables
$username = $password = "";
$usernameErr = $passwordErr = "";
$loginError = "";

// Check if form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Sanitize and validate username
    if (empty($_POST["username"])) {
        $usernameErr = "Username is required";
    } else {
        $username = sanitizeInput($_POST["username"]);
    }

    // Sanitize and validate password
    if (empty($_POST["password"])) {
        $passwordErr = "Password is required";
    } else {
        $password = sanitizeInput($_POST["password"]);
    }

    // If no validation errors, check login credentials
    if (empty($usernameErr) && empty($passwordErr)) {
        $sql = "SELECT * FROM utenti WHERE login = '$username' AND password = '$password'";
        $result = $conn->query($sql);

        if ($result->num_rows == 1) {
            // Successful login
            $_SESSION['username'] = $username; // Store username in session
            header("Location: listaArgomenti.php");
            exit();
        } else {
            // Invalid login credentials
            $loginError = "Invalid username or password";
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login | Tosaerba</title>
    <link rel="stylesheet" href="/styles/login.css">
</head>
<body>

<div class="login-container">
    <h2>Login</h2>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <label for="username">Username:</label>
        <input type="text" name="username" id="username" value="<?php echo $username; ?>">
        <span class="error"><?php echo $usernameErr; ?></span>

        <label for="password">Password:</label>
        <input type="password" name="password" id="password">
        <span class="error"><?php echo $passwordErr; ?></span>

        <span class="error"><?php echo $loginError; ?></span>

        <input type="submit" value="Login">
    </form>
</div>

</body>
</html>
