public class FabriqueCartes {

    private static final FabriqueCartes instance = new FabriqueCartes();

    public static FabriqueCartes getInstance() {
        return instance;
    }

    public JeuDeCartes getPaquetVide() {
        return new JeuDeCartes();
    }

    public JeuDeCartes getPaquet1Vert() {
        JeuDeCartes paquet = new JeuDeCartes();
        paquet.ajouter(new Carte(1, Couleur.VERT));
        return paquet;
    }

    public JeuDeCartes getPaquet5Vert() {
        Carte[] cartes = new Carte[5];
        JeuDeCartes paquet = new JeuDeCartes();
        for (int i = 0; i < 5; ++i) {
            cartes[i] = new Carte(i + 1, Couleur.VERT);
        }
        paquet.ajouter(cartes);
        return paquet;
    }

    public JeuDeCartes getPaquet32() {
        Carte[] cartes = new Carte[32];
        JeuDeCartes paquet = new JeuDeCartes();
        for (int i = 0; i < 8; ++i) {
            cartes[i] = new Carte(i + 1, Couleur.BLEU);
        }
        for (int i = 8; i < 16; ++i) {
            cartes[i] = new Carte(i - 7, Couleur.ROUGE);
        }
        for (int i = 16; i < 24; ++i) {
            cartes[i] = new Carte(i - 15, Couleur.VERT);
        }
        for (int i = 24; i < 32; ++i) {
            cartes[i] = new Carte(i - 23, Couleur.JAUNE);
        }
        paquet.ajouter(cartes);
        return paquet;
    }

}