#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int nb_sigint = 0;

void handler_pour_signal(int sig)
{
    nb_sigint++;
    if (nb_sigint == 1)
    {
        printf("\nVous avez fait Ctrl+C une fois, encore une fois pour fermer le programme.\n");
        fflush(stdout);
    }
    if (nb_sigint >= 2)
    {
        printf("\nVous avez fait Ctrl+C une deuxième fois, arrêt du programme.\n");
        fflush(stdout);
        exit(1);
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    sa.sa_handler = handler_pour_signal;
    sa.sa_flags = 0;
    sigemptyset(&(sa.sa_mask));
    sigaction(SIGINT, &sa, NULL);
    sigset_t masque, masque_avant;
    sigaddset(&masque, SIGINT);
    sigprocmask(SIG_SETMASK, &masque, &masque_avant);
    for (int i = 0; i < 40; ++i)
    {
        fflush(stdout);
        usleep(500000);
    }
    sigprocmask(SIG_SETMASK, &masque_avant, NULL);
    for (int i = 40; i < 60; ++i)
    {
        fflush(stdout);
        usleep(500000);
    }
    return EXIT_SUCCESS;
}