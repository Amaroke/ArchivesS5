package visiteur;

public class Division extends Binaire {
    public Division(Expression g, Expression d) {
        super(g, d);
    }

    public int valeur() {
        return gauche.valeur() / droit.valeur();
    }

    @Override
    public Object accept(Visiteur v) {
        return v.visiteDivision(this);
    }
}