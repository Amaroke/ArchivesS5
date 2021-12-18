<?php // Création de la base de données 

  function query($link,$requete)
  { 
    $resultat=mysqli_query($link,$requete) or die("$requete : ".mysqli_error($link));
	return($resultat);
  }

  
$mysqli=mysqli_connect('127.0.0.1', 'root', '') or die("Erreur de connexion");
$base="Regions";
$Sql="
		DROP DATABASE IF EXISTS $base;
		CREATE DATABASE $base;
		USE $base;
		CREATE TABLE region (id INT AUTO_INCREMENT PRIMARY KEY, lib VARCHAR(255) NOT NULL);
		CREATE TABLE departement (id INT AUTO_INCREMENT PRIMARY KEY, region INT NOT NULL, lib VARCHAR(255) NOT NULL);
		
		INSERT INTO region VALUES (1, 'Lorraine');
		INSERT INTO region VALUES (2, 'Alsace');
		
		INSERT INTO departement VALUES (1, 1, 'Moselle');
		INSERT INTO departement VALUES (2, 1, 'Meurthe-et-Moselle');
		INSERT INTO departement VALUES (3, 1, 'Vosges');
		INSERT INTO departement VALUES (4, 1, 'Meuse');
		
		INSERT INTO departement VALUES (5, 2, 'Bas-Rhin');
		INSERT INTO departement VALUES (6, 2, 'Haut-Rhin')";

foreach(explode(';',$Sql) as $Requete) query($mysqli,$Requete);

mysqli_close($mysqli);
?>