package interpreteur;

public class Nombre implements Expression {
    protected final int valeur;

    public Nombre(int val) {
        this.valeur = val;
    }

    public int valeur() {
        return valeur;
    }

    public String toString() {
        return valeur() + "";
    }

    public String toStringPrefix() {
        return "" + valeur() + " ";
    }

    public String toStringPostfix() {
        return "" + valeur() + " ";
    }

    @Override
    public int nombreNombre() {
        return 1;
    }
}
