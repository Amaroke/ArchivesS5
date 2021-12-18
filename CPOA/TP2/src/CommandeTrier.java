public class CommandeTrier implements Commande {

    private final JeuDeCartes jeuDeCartesSauvegarde;
    private final JeuDeCartes jeuDeCartes;

    public CommandeTrier(JeuDeCartes jeuDeCartes) {
        this.jeuDeCartesSauvegarde = new JeuDeCartes(jeuDeCartes);
        this.jeuDeCartes = jeuDeCartes;
    }

    @Override
    public void execute() {
        this.jeuDeCartes.trierParCouleur();
    }

    @Override
    public String toString() {
        return "Le jeu a été trié par couleurs.";
    }

    public JeuDeCartes getJeuDeCartesSauvegarde() {
        return jeuDeCartesSauvegarde;
    }
}
