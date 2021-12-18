#include "mes_semaphores.h"

int sem_creation(int *semid, int nombre_semaphores)
{
    /*Fonction qui crée un ensemble de sémaphores (semid) de nombre_semaphores.
    Elle renvoie 0 si la création a bien fonctionné.*/
    int cle = ftok("./mes_semaphores", 5);
    *semid = semget(cle, nombre_semaphores, IPC_CREAT | 0660 | IPC_EXCL);
    return *semid;
}

int sem_initialisation(int semid, int num_semaphore, int nbr_jetons)
{
    /* Fonction qui initialise le semaphore numéro num_semaphore de l'ensemble
    de sémaphore semid par la valeur nbr_jetons.*/

    semval initsem;
    initsem.val = nbr_jetons;
    return semctl(semid, num_semaphore, SETVAL, initsem);
}

int P(int semid, int num_semaphore)
{
    // Primitive P pour le sémaphore numéro num_semaphore.
    struct sembuf smbf;
    smbf.sem_num = num_semaphore;
    smbf.sem_op = -1;
    smbf.sem_flg = 0;
    return semop(semid, &smbf, 1);
}

int V(int semid, int num_semaphore)
{
    // Primitive V pour le sémaphore numéro num_semaphore.
    struct sembuf smbf;
    smbf.sem_num = num_semaphore;
    smbf.sem_op = +1;
    smbf.sem_flg = 0;
    return semop(semid, &smbf, 1);
}

int sem_destruction(int semid)
{
    // Fonction qui détruit un ensemble de sémaphores (semid).
    return semctl(semid, IPC_RMID, 0); //voir ci-après pour la fonction semctl
}

int sem_recup(int *semid, int nb_semaphores)
{
    /* Fonction qui récupère le numéro de l'ensemble de sémaphores (semid)
    En entrée, il faut indiquer le nombre de sémaphore
    qu'il y a dans l'ensemble à récupérer. */
    int cle = ftok("./mes_semaphores", 5);
    *semid = semget(cle, nb_semaphores, 0);
    return *semid;
}