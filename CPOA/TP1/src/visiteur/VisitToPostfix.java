package visiteur;

public class VisitToPostfix extends Visiteur {

    @Override
    public Object visiteNombre(Nombre nombre) {
        return nombre.valeur() + " ";
    }

    @Override
    public Object visiteSomme(Somme somme) {
        return "" + somme.getGauche().accept(this) + somme.getDroit().accept(this) + "+ ";
    }

    @Override
    public Object visiteProduit(Produit produit) {
        return "" + produit.getGauche().accept(this) + produit.getDroit().accept(this) + "x ";
    }

    @Override
    public Object visiteDifference(Difference difference) {
        return "" + difference.getGauche().accept(this) + difference.getDroit().accept(this) + "- ";
    }

    @Override
    public Object visiteDivision(Division division) {
        return "" + division.getGauche().accept(this) + division.getDroit().accept(this) + "÷ ";
    }

    @Override
    public Object visiteSommeMultiple(SommeMultiple somme) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < somme.elem.length - 1; ++i) {
            s.append(somme.elem[i].accept(this)).append(" ");
        }
        s.append(somme.elem[somme.elem.length - 1].accept(this)).append(" +");
        return s.toString();
    }

    @Override
    public Object visiteMoyenne(Moyenne moyenne) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < moyenne.elem.length - 1; ++i) {
            s.append(moyenne.elem[i].accept(this)).append(" ");
        }
        s.append(moyenne.elem[moyenne.elem.length - 1].accept(this)).append(" + ").append(moyenne.elem.length).append(" ÷");
        return s.toString();
    }


}
