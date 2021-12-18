package visiteur;

public abstract class Binaire implements Expression {
    protected final Expression gauche;
    protected final Expression droit;

    protected Binaire(Expression gauche, Expression droit) {
        this.gauche = gauche;
        this.droit = droit;
    }

    public Expression getGauche() {
        return gauche;
    }

    public Expression getDroit() {
        return droit;
    }
}
