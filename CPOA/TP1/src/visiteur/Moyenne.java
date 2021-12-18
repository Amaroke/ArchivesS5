package visiteur;

public class Moyenne extends Naire {
    public Moyenne(visiteur.Expression... e) {
        super(e);
    }

    public int valeur() {
        int somme = this.elem[0].valeur();
        for (int i = 1; i < this.elem.length; ++i) {
            somme += this.elem[i].valeur();
        }
        return somme / this.elem.length;
    }

    @Override
    public Object accept(Visiteur v) {
        return v.visiteMoyenne(this);
    }
}
