<!DOCTYPE html>
<html>

<head>
    <title>Session</title>
    <meta charset="utf-8" />
</head>

<body>
    <?php
    session_start();
    $_SESSION["MaVariable"] += 1;
    $var = $_SESSION["MaVariable"];
    echo "Ma variable de session vaut " . $var . " !";
    ?>
</body>

</html>