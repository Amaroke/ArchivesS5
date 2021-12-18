<html>

<head>
    <title>Vérification formulaire</title>
    <meta name="description" content="Vérification du formulaire." />
</head>

<body>
    <h1>Vérification du formulaire</h1>
    <h2>Affichage des données reçues</h2>
    <?php
    echo '<pre>';
    print_r($_POST);
    echo  '</pre>';
    ?>
    <h2>Rapport d'erreurs</h2>
    <?php
    echo "<ul>";

    // Vérification du sexe.
    if ($_POST["sexe"] == 'f' || $_POST["sexe"] == 'h') {
        echo "<li>Sexe : OK !</li>";
    } else {
        if ($_POST["sexe"] == '') {
            echo "<li>Sexe : Absent !</li>";
        } else {
            echo "<li>Sexe : Différent de f ou h !</li>";
        }
    }

    // Vérification du nom.
    if (preg_match('/^[0-9a-zA-Z]{2,}/', $_POST["nom"])) {
        echo "<li>Nom : OK !</li>";
    } else {
        if ($_POST["nom"] == "") {
            echo "<li>Nom : Absent !</li>";
        } else {
            echo "<li>Nom : Trop court ou invalide !</li>";
        }
    }

    // Vérification du prénom.
    if (preg_match('/^[a-zA-Z]+$/', $_POST["prenom"]) && ctype_alpha($_POST["prenom"])) {
        echo "<li>Prénom : OK !</li>";
    } else {
        if ($_POST["prenom"] == "") {
            echo "<li>Prénom : Absent !</li>";
        } else {
            echo "<li>Prénom : Trop court ou contient autre chose que des lettres !</li>";
        }
    }

    // Vérification du pays.
    if ($_POST["pays"] == "Allemagne" || $_POST["pays"] == "Belgique" || $_POST["pays"] == "France" || $_POST["pays"] == "Chine" || $_POST["pays"] == "Maroc" || $_POST["pays"] == "Tunisie") {
        echo "<li>Pays : OK !</li>";
    } else {
        if ($_POST["pays"] == "") {
            echo "<li>Pays : Absent !</li>";
        } else {
            echo "<li>Pays : Pays non valide !</li>";
        }
    }

    // Vérification date de naissance.
    $tab = explode("-", $_POST["naissance"]);
    if ($_POST["naissance"] == "") {
        echo "<li>Naissance : Absent !</li>";
    } else {
        if (checkdate($tab[1], $tab[2], $tab[0])) {
            echo "<li>Naissance : OK !</li>";
        } else {
            echo "<li>Naissance : Invalide !</li>";
        }
    }

    echo "</ul>";
    ?>
</body>

</html>