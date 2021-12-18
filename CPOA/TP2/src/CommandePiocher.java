public class CommandePiocher implements Commande {

    private final JeuDeCartes jeuDeCartesSauvegarde;
    private final JeuDeCartes jeuDeCartes;

    public CommandePiocher(JeuDeCartes jeuDeCartes) {
        this.jeuDeCartesSauvegarde = new JeuDeCartes(jeuDeCartes);
        this.jeuDeCartes = jeuDeCartes;
    }

    @Override
    public void execute() {
        this.jeuDeCartes.piocher();
    }

    @Override
    public String toString() {
        return "Une carte a été pioché.";
    }

    public JeuDeCartes getJeuDeCartesSauvegarde() {
        return jeuDeCartesSauvegarde;
    }
}
