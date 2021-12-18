import java.util.ArrayList;

public class GestionnaireCommandes {

    private final ArrayList<Commande> historique = new ArrayList<>();
    private JeuDeCartes jeuDeCartes;

    public GestionnaireCommandes(JeuDeCartes jeuDeCartes) {
        this.jeuDeCartes = jeuDeCartes;
    }

    public void execute(Commande commande) {
        this.historique.add(commande);
        commande.execute();
    }

    public void undo() {
        if (this.historique.size() != 0) {
            this.jeuDeCartes = historique.get(historique.size() - 1).getJeuDeCartesSauvegarde();
            historique.remove(historique.size() - 1);
        }
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (Commande c : historique) {
            s.append(c).append("\n");
        }
        return s.toString();
    }

    public JeuDeCartes getJeuDeCartes() {
        return jeuDeCartes;
    }
}
