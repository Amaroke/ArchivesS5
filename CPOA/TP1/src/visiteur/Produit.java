package visiteur;

public class Produit extends Binaire {
    public Produit(Expression g, Expression d) {
        super(g, d);
    }

    public int valeur() {
        return gauche.valeur() * droit.valeur();
    }

    @Override
    public Object accept(Visiteur v) {
        return v.visiteProduit(this);
    }
}
