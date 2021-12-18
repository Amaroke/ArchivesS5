<!DOCTYPE html>
<html>

<head>
    <title>ExpressionsRegulieres</title>
    <meta charset="utf-8" />
</head>
<style>
    .oui {
        color: green;
    }

    .non {
        color: red;
    }
</style>

<body>

    <?php
    $file = file_get_contents("www.php.net.html");
    if (preg_match('#<title>(.*)</title>#', $file, $sortie)) {
        echo ($sortie[1] . "<br>" . "<br>");
    }

    preg_match_all('#href="(.*)"#', $file, $TabUrl);
        foreach ($TabUrl[0] as $value) {
        if (preg_match('#(https?://.*?/)#', $value, $TabUrl2)) {
            echo $TabUrl2[1];
            if (preg_match('#://[^/]*php[^/]*/#', $TabUrl2[1], $TabUrl3)) {
                echo "<div class=oui>OUI </div>";
            } else {
                echo "<div class=non>NON </div>";
            }
            echo "<br>";
        }
    }
    ?>

</body>

</html>