#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/wait.h>

typedef union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
} semval;

int sem_creation(int *semid, int nombre_semaphores);

int sem_initialisation(int semid, int num_semaphore, int nbr_jetons);

int P(int semid, int num_semaphore);

int V(int semid, int num_semaphore);

int sem_destruction(int semid);

int sem_recup(int *semid, int nb_semaphores);