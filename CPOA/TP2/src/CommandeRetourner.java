public class CommandeRetourner implements Commande {

    private final JeuDeCartes jeuDeCartesSauvegarde;
    private final JeuDeCartes jeuDeCartes;

    public CommandeRetourner(JeuDeCartes jeuDeCartes) {
        this.jeuDeCartesSauvegarde = new JeuDeCartes(jeuDeCartes);
        this.jeuDeCartes = jeuDeCartes;
    }

    @Override
    public void execute() {
        this.jeuDeCartes.retourner();
    }

    @Override
    public String toString() {
        return "Le jeu a été retourné.";
    }

    public JeuDeCartes getJeuDeCartesSauvegarde() {
        return jeuDeCartesSauvegarde;
    }
}
