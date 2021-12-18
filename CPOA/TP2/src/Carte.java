public class Carte {

    private int valeur;

    private Couleur couleur;

    public Carte(int valeur, Couleur couleur) {
        assert (valeur >= 1 && valeur <= 8) : "Valeur interdite pour une carte";
        this.valeur = valeur;
        assert (couleur == Couleur.VERT || couleur == Couleur.JAUNE || couleur == Couleur.BLEU
                || couleur == Couleur.ROUGE) : "Couleur non autorisée pour une carte";
        this.couleur = couleur;
    }

    public int getValeur() {
        return valeur;
    }

    public void setValeur(int valeur) {
        assert (valeur >= 1 && valeur <= 8) : "Valeur interdite pour une carte";
        this.valeur = valeur;
    }

    public Couleur getCouleur() {
        return couleur;
    }

    public void setCouleur(Couleur couleur) {
        this.couleur = couleur;
    }

    public String toString() {
        return "Carte{" + "valeur=" + valeur + ", couleur=" + couleur + '}';
    }

}
