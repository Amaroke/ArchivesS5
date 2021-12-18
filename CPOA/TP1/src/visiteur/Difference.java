package visiteur;


public class Difference extends Binaire {
    public Difference(Expression g, Expression d) {
        super(g, d);
    }

    public int valeur() {
        return gauche.valeur() - droit.valeur();
    }

    @Override
    public Object accept(Visiteur v) {
        return v.visiteDifference(this);
    }
}
