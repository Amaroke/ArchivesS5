<!DOCTYPE html>
<html>

<head>
    <title>Acceuil</title>
    <meta charset="utf-8" />
</head>

<body>
    <?php
    if (!isset($_COOKIE["Tracker"])) {
        echo "Bonjour, je ne vous connais pas, c’est la 1ère fois que
        vous accédez à cette page.";
        setcookie("Tracker", serialize(0));
    ?>
        <form method="post" action="#">
            <fieldset>
                <legend>Veuillez saisir votre prénom</legend>
                Prénom :
                <input type="text" name="prenom" value="<?php echo ($_POST["prenom"]); ?>" />
            </fieldset>
            <br />
            <input type="submit" value="Valider" />
        </form>
    <?php
    } else {
        $var = unserialize($_COOKIE["Tracker"]);
        $var += 1;
        if ($var == 1) {
            echo ("Bonjour " . $_POST["prenom"] . ", je suis ravi de faire votre connaissance !");
            setcookie("Tracker", serialize($var));
        } else if ($var < 6) {
            echo ("Bonjour " . $_POST["prenom"] . ", c'est la " . $var . "ème fois que tu accèdes à mon site !");
            setcookie("Tracker", serialize($var));
        } else {
            echo ("Salut " . $_POST["prenom"] . ", bienvenue sur mon site !");
            setcookie("Tracker", serialize($var));
        }
    } ?>

</body>

</html>