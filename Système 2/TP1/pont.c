#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define ERREUR_CREATION 1
#define ERREUR_RECOUVREMENT 2

int main(int argc, char **argv)
{
    int status;
    if (argc != 4)
    {
        perror("Il faut 3 arguments");
        exit(1);
    }
    int resultat = EXIT_SUCCESS;
    pid_t ret = fork();
    printf("PID : %d (PPID : %d)\n", getpid(), getppid());
    if (ret == -1)
    {
        perror("Création impossible !");
        resultat = ERREUR_CREATION;
    }
    else if (ret == 0)
    {
        //On est dans le fils
        execl("./recouvrant_pont", "recouvrant-pont", argv[1], argv[2], argv[3], NULL);
        perror("Recouvrement impossible ");
        resultat = ERREUR_RECOUVREMENT;
    }
    waitpid(ret, &status, 0);
    return resultat;
}