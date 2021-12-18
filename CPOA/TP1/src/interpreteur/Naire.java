package interpreteur;

public abstract class Naire implements Expression {
    protected final Expression[] elem;

    public Naire(Expression[] e) {
        this.elem = new Expression[e.length];
        System.arraycopy(e, 0, this.elem, 0, elem.length);
    }
}
