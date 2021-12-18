package visiteur;

public class VisitToNombreDeNombre extends Visiteur {

    @Override
    public Object visiteNombre(Nombre nombre) {
        return 1;
    }

    @Override
    public Object visiteSomme(Somme somme) {
        return (int) somme.getGauche().accept(this) + (int) somme.getDroit().accept(this);
    }

    @Override
    public Object visiteProduit(Produit produit) {
        return (int) produit.getGauche().accept(this) + (int) produit.getDroit().accept(this);
    }

    @Override
    public Object visiteDifference(Difference difference) {
        return (int) difference.getGauche().accept(this) + (int) difference.getDroit().accept(this);
    }

    @Override
    public Object visiteDivision(Division division) {
        return (int) division.getGauche().accept(this) + (int) division.getDroit().accept(this);
    }

    @Override
    public Object visiteSommeMultiple(SommeMultiple somme) {
        int res = 0;
        for (int i = 0; i < somme.elem.length; ++i) {
            res += (int) somme.elem[i].accept(this);
        }
        return res;
    }

    @Override
    public Object visiteMoyenne(Moyenne moyenne) {
        int res = 0;
        for (int i = 0; i < moyenne.elem.length; ++i) {
            res += (int) moyenne.elem[i].accept(this);
        }
        return res;
    }
}