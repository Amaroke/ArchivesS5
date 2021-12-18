public class CommandeMelanger implements Commande {

    private final JeuDeCartes jeuDeCartesSauvegarde;
    private final JeuDeCartes jeuDeCartes;

    public CommandeMelanger(JeuDeCartes jeuDeCartes) {
        this.jeuDeCartesSauvegarde = new JeuDeCartes(jeuDeCartes);
        this.jeuDeCartes = jeuDeCartes;
    }

    @Override
    public void execute() {
        this.jeuDeCartes.melanger();
    }

    @Override
    public String toString() {
        return "Le jeu a été mélangé.";
    }

    public JeuDeCartes getJeuDeCartesSauvegarde() {
        return jeuDeCartesSauvegarde;
    }
}
