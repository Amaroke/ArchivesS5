#include "mes_semaphores.h"

/* On utilisera les sémaphores, dans semid, initialisé à 1 jeton
puisqu'ils sont privés
Le sémaphore à l'indice 0 s'occupe des rendez-vous et des échanges*/

bool termine = false;

void catcher_signal(int sig)
{
    termine = true;
}

// Fonction qui initialise le tableau avec des valeurs aléatoires
void remplir_tableau(int *tableau, int taille_tableau)
{
    for (int i = 0; i < taille_tableau; ++i)
    {
        tableau[i] = rand() % 101;
    }
}

// Fonction pour afficher le tableau
void afficher_tableau(int *tableau, int taille_tableau)
{
    printf("[");
    for (int i = 0; i < taille_tableau - 1; ++i)
    {
        printf("%d, ", tableau[i]);
    }
    printf("%i]\n", tableau[taille_tableau - 1]);
}

// Fonction qui cherche le minimum entre deux cases du tableau et renvoie sa position
int rechercher_min(int *tableau, int a, int b)
{
    int min = a;
    for (int i = a; i < b; ++i)
    {
        min = tableau[i] < tableau[min] ? i : min;
    }
    return min;
}

// Fonction qui cherche le minimum entre deux cases du tableau et renvoie sa position
int rechercher_max(int *tableau, int a, int b)
{
    int max = a;
    for (int i = a; i < b; ++i)
    {
        max = tableau[i] > tableau[max] ? i : max;
    }
    return max;
}

void echanger_valeur(int *tableau, int a, int b)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

int main(int argc, char **argv)
{
    // Initialisation du générateur de nombre aléatoire.
    srand(getpid());
    int *tableau_partagee; // Pointera sur la case mémoire partagée
    int taille_tableau;

    // On extrait le premier argument, la demi-taille du tableau
    if (((argc != 2) || atoi(argv[1])<=0 || atoi(argv[1])>100))
    {
        printf("Aucun paramètre ou paramètre non situé entre 1 et 100 ou trop de paramètres donnés, 3 est donc pris par défaut.\n");
        taille_tableau = 6;
    }
    else
    {
        // La taille du tableau est deux fois la demi-taille donnée.
        taille_tableau = 2 * atoi(argv[1]);
    }

    // Création d'un segment de memoire partagée privé
    int mem_id = shmget(IPC_PRIVATE, 1 * sizeof(float), IPC_CREAT | 0660);
    if (mem_id == -1)
    {
        perror("Erreur de création du segment de memoire partagé");
        exit(1);
    }

    // Attachement du segment pour pouvoir l'utiliser
    tableau_partagee = (int *)shmat(mem_id, NULL, 0);
    if (tableau_partagee == NULL)
    {
        perror("Erreur d'attachement au segment de memoire partagé");
        exit(1);
    }

    // Création des sémaphores
    int *semid = malloc(sizeof(int));
    if (sem_creation(semid, 1) == -1)
    {
        perror("Problème création");
        exit(1);
    }
    if (sem_initialisation(*semid, 0, 1) == -1)
    {
        perror("Problème initialisation");
        exit(1);
    }

    // On remplit le tableau et on l'affiche une première fois
    remplir_tableau(tableau_partagee, taille_tableau);

    int status;
    pid_t ret = fork();
    if (ret == -1)
    {
        perror("Création impossible !");
        exit(1);
    }
    else if (ret == 0)
    {
        // On est dans le fils
        bool fils_en_cours = true;
        while (fils_en_cours)
        {
            P(*semid, 0);
            // On recherche le min
            int min = rechercher_min(tableau_partagee, taille_tableau / 2, taille_tableau);
            if (!(tableau_partagee[min] >= tableau_partagee[0]))
            {
                // On échange le min avec la position avec le max
                afficher_tableau(tableau_partagee, taille_tableau);
                echanger_valeur(tableau_partagee, min, 0);
                afficher_tableau(tableau_partagee, taille_tableau);
            }
            else
            {
                fils_en_cours = false;
            }
            V(*semid, 0);
        }
    }
    else
    {
        // On est dans le père
        struct sigaction sa;
        sa.sa_handler = catcher_signal;
        sa.sa_flags = 0;
        sigemptyset(&(sa.sa_mask));
        sigaction(SIGCHLD, &sa, NULL);

        while (!termine)
        {
            P(*semid, 0);
            // On recherche le max
            int max = rechercher_max(tableau_partagee, 0, taille_tableau / 2);
            // On met le max de la partie de droite en position 0
            echanger_valeur(tableau_partagee, 0, max);
            V(*semid, 0);
        }
        afficher_tableau(tableau_partagee, taille_tableau);

        // On attends la fin du fils
        waitpid(ret, &status, 0);

        // On détruit les sémaphores
        sem_destruction(*semid);

        // Détachement et destruction du segment de mémoire partagé
        shmdt(tableau_partagee);
        shmctl(mem_id, IPC_RMID, 0);
    }
    return EXIT_SUCCESS;
}