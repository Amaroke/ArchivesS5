<html>

<head>
    <title>Listes deroulantes adaptatives</title>
    <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
    <script type="text/javascript">
        <?php
        
        $connect = new \PDO('mysql:dbname=$base;host=localhost',"root");

        $nbregion = count($connect->query("SELECT * FROM region")->fetchAll());

        $html = 'var departements =  new Array(Array(),';

        for ($i = 1; $i <= $nbregion; $i++) {
            $query = $connect->query("SELECT * FROM departement WHERE region = $i");
            $res = $query->fetchAll();
            $html .= 'Array(';
            for ($q = 0; $q < count($res); $q++) {
                $html .= "'" . $res[$q]['lib'] . "'";
                if ($q < count($res) - 1) {
                    $html .= ',';
                }
            }
            $html .= ')';
            if ($i < $nbregion) {
                $html .= ',';
            } else {
                $html .= ')';
            }
        }
        echo $html; ?>

        function choixRegion() {
            document.getElementById("div_departements").innerHTML = '';
            var idRegion = document.formulaire.regions.value;
            var buffer = '<select name="description">'; +
            '<option></option>';
            if (idRegion != 0) {
                for (var i = 0; i < departements[idRegion].length; ++i)
                    buffer += '<option>' + departements[idRegion][i] + '</option>';
            }
            buffer += '</select>'
            document.getElementById('div_departements').innerHTML = buffer;
        }
    </script>
</head>

<body>
    <form name="formulaire">
        <select name="regions" onChange="choixRegion()">
            <option value="0"></option>
            <option value="1">Lorraine</option>
            <option value="2">Alsace</option>
        </select>

        <div id="div_departements">

        </div>
    </form>

</body>

</html>