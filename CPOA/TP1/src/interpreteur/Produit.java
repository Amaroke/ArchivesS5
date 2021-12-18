package interpreteur;

public class Produit extends Binaire {
    public Produit(Expression g, Expression d) {
        super(g, d);
    }

    public int valeur() {
        return gauche.valeur() * droit.valeur();
    }

    public String toString() {
        return "(" + gauche + "*" + droit + ")";
    }

    public String toStringPrefix() {
        return "x " + gauche.toStringPrefix() + droit.toStringPrefix();
    }

    public String toStringPostfix() {
        return "" + gauche.toStringPostfix() + droit.toStringPostfix() + "x ";
    }

    @Override
    public int nombreNombre() {
        return gauche.nombreNombre() + droit.nombreNombre();
    }
}
