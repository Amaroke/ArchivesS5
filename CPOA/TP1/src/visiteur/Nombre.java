package visiteur;

public class Nombre implements Expression {
    protected final int valeur;

    public Nombre(int val) {
        this.valeur = val;
    }

    public int valeur() {
        return valeur;
    }

    @Override
    public Object accept(Visiteur v) {
        return v.visiteNombre(this);
    }
}
