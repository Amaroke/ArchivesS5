<!DOCTYPE html>
<html>

<head>
	<title>Vos données</title>
	<meta charset="utf-8" />
	<link href="FormulaireEtVerification.css" rel="stylesheet">
</head>

<body>
	<?php

	if (isset($_POST["submit"])) {
		// Vérification du sexe.

		if ($_POST["sexe"] == 'f' || $_POST["sexe"] == 'h') {
			$sexe_valide = "correct";
			if ($_POST["sexe"] == 'f') {
				$est_femme = "checked";
			} else {
				$est_homme = "checked";
			}
		} else {
			$sexe_valide = "incorrect";
		}

		// Vérification du nom.
		if (preg_match('/^[0-9a-zA-Z]{2,}/', $_POST["nom"])) {
			$nom_valide = "correct";
		} else {
			$nom_valide = "incorrect";
		}

		// Vérification du prénom.
		if (preg_match('/^[a-zA-Z]+$/', $_POST["prenom"]) && ctype_alpha($_POST["prenom"])) {
			$prenom_valide = "correct";
		} else {
			$prenom_valide = "incorrect";
		}

		// Vérification du pays.
		if ($_POST["pays"] == "Allemagne" || $_POST["pays"] == "Belgique" || $_POST["pays"] == "France" || $_POST["pays"] == "Chine" || $_POST["pays"] == "Maroc" || $_POST["pays"] == "Tunisie") {
			$pays_valide = "correct";
		} else {
			$pays_valide = "incorrect";
		}

		// Vérification date de naissance.
		if ($_POST["naissance"] == null) {
			$naissance_valide = "incorrect";
		} else {
			$tab = explode("-", $_POST["naissance"]);
			if (checkdate($tab[1], $tab[2], $tab[0])) {
				$naissance_valide = "correct";
			} else {
				$naissance_valide = "incorrect";
			}
		}
	} else { //S'il n'est pas submit
		$sexe_valide = "vide";
		$nom_valide = "vide";
		$prenom_valide = "vide";
		$naissance_valide = "vide";
		$pays_valide = "vide";
	}

	if ($nom_valide != "correct" || $sexe_valide != "correct" || $prenom_valide != "correct" || $naissance_valide != "correct" || $pays_valide != "correct") {
	?>
		<h1>Vos données</h1>

		<form method="post" action="#">
			<fieldset>
				<legend>Informations personnelles</legend>
				Vous êtes :
				<span id=<?php echo ($sexe_valide); ?>>
					<input type="radio" name="sexe" value="f" <?php echo ($est_femme); ?> /> une femme
					<input type="radio" name="sexe" value="h" <?php echo ($est_homme); ?> /> un homme
				</span>
				<br />
				Nom :
				<input type="text" name="nom" required="required" value="<?php echo ($_POST["nom"]); ?>" id=<?php echo ($nom_valide); ?> /><br />
				Prénom :
				<input type="text" name="prenom" value="<?php echo ($_POST["prenom"]); ?>" id=<?php echo ($prenom_valide); ?> /><br />
				Date de naissance :
				<input type="date" name="naissance" value="<?php echo ($_POST["naissance"]); ?>" id=<?php echo ($naissance_valide); ?> /><br />
				Pays d'origine :
				<input name="pays" list="pays" value="<?php echo ($_POST["pays"]); ?>" id=<?php echo ($pays_valide); ?> />
				<datalist id="pays">
					<option value="Allemagne" />
					<option value="Belgique" />
					<option value="Chine" />
					<option value="France" />
					<option value="Maroc" />
					<option value="Tunisie" />
				</datalist>

			</fieldset>

			<br />
			<input type="submit" name="submit" value="Valider" />

		</form>
	<?php
		if (isset($_POST["submit"])) {
			echo "<br>Merci de remplir correctement les champs suivants :";

			echo "<ul>";
			if ($sexe_valide == "incorrect") {
				echo "<li>le sexe</li>";
			}
			if ($nom_valide == "incorrect") {
				echo "<li>le nom</li>";
			}
			if ($prenom_valide == "incorrect") {
				echo "<li>le prenom</li>";
			}
			if ($naissance_valide == "incorrect") {
				echo "<li>la naissance</li>";
			}
			if ($pays_valide == "incorrect") {
				echo "<li>le pays</li>";
			}
			echo "</ul>";
		}
	} else {
		$nom = ucwords(strtolower($_POST["nom"]));
		$prenom = ucwords(strtolower($_POST["prenom"]));
		$sexe = strtolower($_POST["sexe"]);
		$naissance = $tab[2] . "/" . $tab[1] . "/" . $tab[0];
		$pays = strtoupper($_POST["pays"]);
		echo ($prenom . " " . $nom . " (" . $sexe . "), né le " . $naissance . " (" . $pays . ")");
	} ?>

</body>

</html>