package visiteur;

public class SommeMultiple extends Naire {
    public SommeMultiple(Expression... e) {
        super(e);
    }

    public int valeur() {
        int somme = this.elem[0].valeur();
        for (int i = 1; i < this.elem.length; ++i) {
            somme += this.elem[i].valeur();
        }
        return somme;
    }

    @Override
    public Object accept(Visiteur v) {
        return v.visiteSommeMultiple(this);
    }

}
