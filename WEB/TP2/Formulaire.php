<!DOCTYPE html>
<html>

<head>
      <title>Vos données</title>
	  <meta charset="utf-8" />
</head>

<body>

<h1>Vos données</h1>

<form method="post" action="VerificationFormulaire.php" >
<fieldset>
    <legend>Informations personnelles</legend>
	Vous êtes :  
	<input type="radio" name="sexe" value="f"/> une femme 	
	<input type="radio" name="sexe" value="h"/> un homme
	<br />
    Nom :    
	<input type="text" name="nom" required="required" /><br />   
    Prénom : 
	<input type="text" name="prenom" /><br /> 	
    Date de naissance : 
	<input type="date" name="naissance" /><br /> 	
	Pays d'origine :
    <input name="pays" list="pays" />
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
<input type="submit" value="Valider" />
         
</form>
</body>
</html>
