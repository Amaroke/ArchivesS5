package visiteur;

public abstract class Visiteur {

    public abstract Object visiteNombre(Nombre nombre);

    public abstract Object visiteSomme(Somme somme);

    public abstract Object visiteProduit(Produit produit);

    public abstract Object visiteDifference(Difference difference);

    public abstract Object visiteDivision(Division division);

    public abstract Object visiteSommeMultiple(SommeMultiple somme);

    public abstract Object visiteMoyenne(Moyenne moyenne);
}
