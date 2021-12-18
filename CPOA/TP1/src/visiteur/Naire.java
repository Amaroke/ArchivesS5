package visiteur;

public abstract class Naire implements visiteur.Expression {
    protected final visiteur.Expression[] elem;

    public Naire(visiteur.Expression[] e) {
        this.elem = new Expression[e.length];
        System.arraycopy(e, 0, this.elem, 0, elem.length);
    }
}
