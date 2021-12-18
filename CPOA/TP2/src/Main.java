import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        FabriqueCartes fabriqueCartes = FabriqueCartes.getInstance();
        JeuDeCartes jeuDeCartes = new JeuDeCartes();
        GestionnaireCommandes gestionnaireCommandes = new GestionnaireCommandes(jeuDeCartes);
        Scanner scanner = new Scanner(System.in);
        int choix = 0;
        while (choix != 1) {
            switch (choix) {
                case 0:
                    System.out.println("Bienvenue dans l'application ! Que voulez-vous faire ?\n" +
                            "0 : Afficher le menu.\n" +
                            "1 : Quitter l'application.\n" +
                            "2 : Créer un jeu de cartes.\n" +
                            "3 : Mélanger le jeu de cartes.\n" +
                            "4 : Trier le jeu par couleur.\n" +
                            "5 : Tirer une carte au hasard.\n" +
                            "6 : Obtenir la valeur du jeu.\n" +
                            "7 : Obtenir le nombre de cartes.\n" +
                            "8 : Retourner le paquet.\n" +
                            "9 : Afficher le jeu de cartes.\n" +
                            "10 : Retourner à l'état précédent.\n" +
                            "11 : Afficher Historique.\n");
                    break;
                case 1:
                    System.out.println("Vous quittez l'application !\n");
                    break;
                case 2:
                    System.out.println("Vous avez pris un nouveau jeu de Cartes.\n");
                    jeuDeCartes = fabriqueCartes.getPaquet32();
                    break;
                case 3:
                    System.out.println("Vous mélangez votre jeu de cartes.\n");
                    gestionnaireCommandes.execute(new CommandeMelanger(jeuDeCartes));
                    break;
                case 4:
                    System.out.println("Votre jeu a été trié.\n");
                    gestionnaireCommandes.execute(new CommandeTrier(jeuDeCartes));
                    break;
                case 5:
                    System.out.println("Vous avez tiré une carte au hasard.\n");
                    gestionnaireCommandes.execute(new CommandePiocher(jeuDeCartes));
                    break;
                case 6:
                    System.out.println("Voici la valeur du jeu : " + jeuDeCartes.getValeur() + "\n");
                    break;
                case 7:
                    System.out.println("Il y a " + jeuDeCartes.getNombreDeCartes() + " cartes dans le jeu.\n");
                    break;
                case 8:
                    System.out.println("Vous avez retourné le paquet.\n");
                    gestionnaireCommandes.execute(new CommandeRetourner(jeuDeCartes));
                    break;
                case 9:
                    System.out.println("Voici votre jeu de cartes :\n");
                    System.out.println(jeuDeCartes);
                    break;
                case 10:
                    System.out.println("Vous êtes retourné à l'état précédent.");
                    gestionnaireCommandes.undo();
                    jeuDeCartes = gestionnaireCommandes.getJeuDeCartes();
                    break;
                case 11:
                    System.out.println(gestionnaireCommandes);
                    break;
                default:
                    System.out.println("Erreur lors de la saisie !\n");
                    break;
            }
            System.out.print("Votre choix : ");
            choix = scanner.nextInt();
        }
    }

}
