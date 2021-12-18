#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int signaux_recu = 0;

void catcher(int sig)
{
    signaux_recu == 0 ? printf("Signale de départ reçu !\n") : printf("Signal n°%d reçu !\n", signaux_recu);
    signaux_recu++;
    fflush(stdout);
}

int main(int argc, char **argv)
{
    int status;
    pid_t ret = fork();
    if (ret == -1)
    {
        perror("Création impossible !");
        exit(1);
    }
    else if (ret == 0)
    {
        //On est dans le fils 1
        execl("./recouvrant_attrape_signaux", "recouvrant_attrape_signaux", NULL);
        perror("Recouvrement impossible !");
        exit(1);
    }
    else
    {
        //On est dans le père
        struct sigaction sact;
        sigset_t masque;
        sact.sa_flags = 0;
        sact.sa_handler = catcher;
        sigaction(SIGUSR1, &sact, NULL);

        sigfillset(&masque);
        sigdelset(&masque, SIGUSR1);

        sigsuspend(&masque);
        for (int i = 0; i < atoi(argv[1]); i++)
        {
            kill(ret, SIGUSR1);
            sigsuspend(&masque);
        }
        kill(ret, SIGTERM);
        waitpid(ret, &status, 0);
    }
    return EXIT_SUCCESS;
}