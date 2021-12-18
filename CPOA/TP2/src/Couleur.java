public enum Couleur {
    JAUNE("Jaune"), VERT("Vert"), BLEU("Bleu"), ROUGE("Rouge");

    private final String nom;

    Couleur(String nom) {
        assert (nom.equals("Jaune") || nom.equals("Vert") || nom.equals("Bleu") || nom.equals("Rouge"))
                : "Couleur non autorisée pour une carte";
        this.nom = nom;
    }

    public String getNom() {
        return this.nom;
    }

    public String toString() {
        return this.nom;
    }
}