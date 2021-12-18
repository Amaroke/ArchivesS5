<!DOCTYPE html>
<html>

<head>
    <title>Tableaux</title>
    <meta charset="utf-8" />
</head>

<body>

    <?php
    $PotesDePromo = array(
        "0" => "paul",
        "1" => "lea",
        "2" => "leon"
    );
    ?>
    <ul>
        <?php
        for ($i = 0; $i < count($PotesDePromo); ++$i) {
            echo ("<li>$PotesDePromo[$i]</li>");
        }
        ?>
    </ul>
    <ul>
        <?php
        echo ("\n");
        foreach ($PotesDePromo as &$value) {
            echo ("<li>$value</li>");
        }
        ?>
    </ul>

    <?php
    $Menu = array(
        "" => array("entrée" => "Entrée", "plat" => "Plat", "desert" => "Déssert"),
        "Lundi" => array("entrée" => "Salade", "plat" => "Boudin/Purée", "desert" => "Mousseau chocolat"),
        "Mardi" => array("entrée" => "Tomates", "plat" => "Couscous", "desert" => "Glace"),
        "Mercredi" => array("entrée" => "Sardine", "plat" => "Steack/Frites", "desert" => "Yaourt"),
        "Jeudi" => array("entrée" => "Jambon", "plat" => "Paela", "desert" => "Gâteau"),
        "Vendredi" => array("entrée" => "Poireaux vinaigrette", "plat" => "Poisson/Riz", "desert" => "Pomme")
    );
    ?>

    <?php
    echo '<table border=1>';
    foreach ($Menu as $key => $value) {
        echo '<tr>';
        echo '<td>';
        echo $key;
        echo '</td>';
        foreach ($value as $value3) {
            echo '<td align="center">';
            echo $value3;
            echo '</td>';
        }
        echo '</tr>';
    }
    echo '</table>';
    ?>

</body>

</html>