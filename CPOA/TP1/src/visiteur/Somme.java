package visiteur;

public class Somme extends Binaire {
    public Somme(Expression gauche, Expression droit) {
        super(gauche, droit);
    }

    public int valeur() {
        return gauche.valeur() + droit.valeur();
    }

    @Override
    public Object accept(Visiteur v) {
        return v.visiteSomme(this);
    }
}
