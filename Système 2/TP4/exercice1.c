#include "mes_semaphores.h"

int main(int argc, char **argv)
{
    float *pVariablePartagee; //Pointera sur la case mémoire partagée

    /* Création d'un segment de memoire partagée privé */
    int mem_id = shmget(IPC_PRIVATE, 1 * sizeof(float), IPC_CREAT | 0660);
    if (mem_id == -1)
    {
        perror("Erreur creation segment memoire partagé");
        exit(1);
    }
    /* Attachement du segment pour pouvoir l'utiliser */
    pVariablePartagee = (float *)shmat(mem_id, NULL, 0);
    if (pVariablePartagee == NULL)
    {
        perror("Erreur d'attachement au segment memoire partagé");
        exit(2);
    }

    *(pVariablePartagee) = 0;

    // Création des sémaphores
    int *semid;
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
    int status;
    pid_t ret = fork();
    if (ret == -1)
    {
        perror("Création impossible !");
        exit(1);
    }
    else if (ret == 0)
    {
        // On est dans le fils :
        for (int i = 0; i < 100000; ++i)
        {
            P(*semid, 0);
            int tmp = (*pVariablePartagee);
            tmp = tmp + 5;
            *(pVariablePartagee) = tmp;
            V(*semid, 0);
        }
        exit(1);
    }
    else
    {
        // On est dans le père :
        for (int i = 0; i < 100000; ++i)
        {
            P(*semid, 0);
            int tmp = (*pVariablePartagee);
            tmp = tmp + 3;
            *(pVariablePartagee) = tmp;
            V(*semid, 0);
        }
        waitpid(ret, &status, 0);
        sem_destruction(*semid);
        printf("Valeur contenu dans la variable : %f\n", *(pVariablePartagee));

        // Détachement
        shmdt(pVariablePartagee);
        // Destruction
        shmctl(mem_id, IPC_RMID, 0);
    }
    return EXIT_SUCCESS;
}