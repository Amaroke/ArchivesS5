#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

void catcher(int sig)
{
    printf("Signal interrompu !\n");
    fflush(stdout);
}

int main(int argc, char **argv)
{
    struct sigaction sact;
    sact.sa_handler = catcher;
    sigaction(SIGUSR1, &sact, NULL);
    sleep(1);
    kill(getpid(), SIGUSR1);
    sleep(1);
    return EXIT_SUCCESS;
}