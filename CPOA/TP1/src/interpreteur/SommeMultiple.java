package interpreteur;

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

    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("(");
        for (int i = 0; i < elem.length - 1; ++i) {
            s.append(elem[i]).append(" + ");
        }
        return s + "" + elem[elem.length - 1] + ")";
    }

    @Override
    public String toStringPrefix() {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < elem.length - 1; ++i) {
            s.append(elem[i].toStringPrefix()).append(" ");
        }
        return s + "" + elem[elem.length - 1].toStringPrefix();
    }

    @Override
    public String toStringPostfix() {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < elem.length - 1; ++i) {
            s.append(elem[i].toStringPostfix()).append(" ");
        }
        s.append(elem[elem.length - 1].toStringPostfix()).append(" +");
        return s.toString();
    }

    @Override
    public int nombreNombre() {
        int res = 0;
        for(Expression e : elem) {
            res += e.nombreNombre();
        }
        return res;
    }
}
