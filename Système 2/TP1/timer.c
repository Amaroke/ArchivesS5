#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler_pour_signal(int sig)
{
    int temps_restant = alarm(0); //On récupère le temps restant.
    if (sig == SIGALRM)
    {
        printf("\nVous avez perdu !\n");
        fflush(stdout);
    }
    else
    {
        printf("\nBien joué ! Vous étiez à %i secondes de la fin de l'alarme !\n", temps_restant);
        fflush(stdout);
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    sa.sa_handler = handler_pour_signal;
    sa.sa_flags = 0;
    sigemptyset(&(sa.sa_mask));
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGALRM, &sa, NULL);
    alarm(10); //On lance l'alarme de 10 secondes.
    pause();

    return EXIT_SUCCESS;
}