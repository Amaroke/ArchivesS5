/* Même avec un masque vide, le signaleest masqué durant l'éxecution d'un handler. Tandis que lorsqu'on utilise SA_NODEFER le signal n'est pas masqué et peut continuer d'être catch.*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void catcher(int sig)
{
    printf("Ctrl-C interrompu !");
    fflush(stdout);
    sleep(10);
}

int main(int argc, char **argv)
{
    struct sigaction sact;
    sact.sa_handler = catcher;
    sigemptyset(&(sact.sa_mask));
    sact.sa_flags = SA_NODEFER;
    sigaction(SIGINT, &sact, NULL);
    pause();
    return EXIT_SUCCESS;
}