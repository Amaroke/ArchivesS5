<?php

if (isset($_GET["taille"])) $taille = $_GET["taille"];
else $taille = 0;

if ($taille > 20) {
    echo "Triangle trop grand.";
} else {
    if ($taille == 0) {
        $taille = 10;
    }
    for ($i = 1; $i <= $taille; $i++) {
        for ($j = 1; $j <= $i; $j++) {
            echo "*";
        }
        echo "<br>";
    }
}
