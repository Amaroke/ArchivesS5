import java.util.ArrayList;
import java.util.Collections;

public class JeuDeCartes {

    private final ArrayList<Carte> paquet;

    public JeuDeCartes() {
        this.paquet = new ArrayList<>();
    }

    public JeuDeCartes(JeuDeCartes jeuDeCartes) {
        this.paquet = new ArrayList<>();
        this.paquet.addAll(jeuDeCartes.paquet);
    }

    public boolean estVide() {
        return this.paquet.isEmpty();
    }

    public int getNombreDeCartes() {
        return this.paquet.size();
    }

    public int getValeur() {
        int s = 0;
        for (Carte i : this.paquet) {
            s += i.getValeur();
        }
        return s;
    }

    public String toString() {
        StringBuilder s = new StringBuilder(this.getNombreDeCartes() * 30);
        for (Carte i : this.paquet) {
            s.append(i.toString()).append(" ");
        }
        return s.toString();
    }

    public void ajouter(Carte... cartes) {
        Collections.addAll(this.paquet, cartes);
    }

    public void melanger() {
        Collections.shuffle(this.paquet);
    }

    public void retourner() {
        Collections.reverse(this.paquet);
    }

    public void trierParCouleur() {
        ArrayList cartesRouges = new ArrayList<>();
        ArrayList cartesVertes = new ArrayList<>();
        ArrayList cartesJaunes = new ArrayList<>();
        ArrayList cartesBleues = new ArrayList<>();
        for (Carte c : this.paquet
        ) {
            if (c.getCouleur() == Couleur.ROUGE) {
                cartesRouges.add(c);
            } else if (c.getCouleur() == Couleur.VERT) {
                cartesVertes.add(c);
            } else if (c.getCouleur() == Couleur.JAUNE) {
                cartesJaunes.add(c);
            } else {
                cartesBleues.add(c);
            }
        }
        this.paquet.clear();
        this.paquet.addAll(cartesBleues);
        this.paquet.addAll(cartesRouges);
        this.paquet.addAll(cartesJaunes);
        this.paquet.addAll(cartesVertes);
    }

    public Carte piocher() {
        if (!this.estVide()) {
            Carte c = this.paquet.get(0);
            this.paquet.remove(0);
            return c;
        }
        return null;
    }

}
