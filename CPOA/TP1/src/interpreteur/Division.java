package interpreteur;

public class Division extends Binaire {
    public Division(Expression g, Expression d) {
        super(g, d);
    }

    public int valeur() {
        return gauche.valeur() / droit.valeur();
    }

    public String toString() {
        return "(" + gauche + "÷" + droit + ")";
    }

    public String toStringPrefix() {
        return "÷ " + gauche.toStringPrefix() + droit.toStringPrefix();
    }

    public String toStringPostfix() {
        return "" + gauche.toStringPostfix() + droit.toStringPostfix() + "÷ ";
    }

    @Override
    public int nombreNombre() {
        return gauche.nombreNombre() + droit.nombreNombre();
    }
}