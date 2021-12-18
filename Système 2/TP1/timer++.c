#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int gagne = 0;
int signaux_recu = 0;

void handler_pour_signal(int sig)
{
    signaux_recu++;
    if (sig == SIGUSR1)
    {
        gagne = 1;
        pause();
    }
    if (sig == SIGUSR2)
    {
        gagne = 2;
        pause();
    }
    if (sig == SIGALRM || signaux_recu == 2)
    {
        if (gagne == 0)
        {
            printf("\nLes fils ont perdu !\n");
            fflush(stdout);
            exit(0);
        }
        if (gagne == 1)
        {
            printf("\nLe fils 1 a gagné !\n");
            fflush(stdout);
            exit(0);
        }
        if (gagne == 2)
        {
            printf("\nLe fils 2 a gagné !\n");
            fflush(stdout);
            exit(0);
        }
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    sa.sa_handler = handler_pour_signal;
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    pid_t ret = fork();
    if (ret == -1)
    {
        perror("Création impossible !");
        exit(1);
    }
    else if (ret == 0)
    {
        //On est dans le fils 1
        execl("./recouvrant_timer++", "recouvrant_timer++", "1", NULL);
        perror("Recouvrement impossible ");
        exit(1);
    }

    pid_t ret2 = fork();
    if (ret2 == -1)
    {
        perror("Création impossible !");
        exit(1);
    }
    else if (ret2 == 0)
    {
        //On est dans le fils 2
        execl("./recouvrant_timer++", "recouvrant_timer++", "2", NULL);
        perror("Recouvrement impossible ");
        exit(1);
    }
    alarm(10);
    pause();
    return EXIT_SUCCESS;
}