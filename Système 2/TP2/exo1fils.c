#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

int signaux_recu = 0;

void handler_pour_signal(int sig)
{
    if (sig == SIGUSR1)
    {
        signaux_recu++;
    }
}

void handler_pour_signal2(int sig)
{
    if (sig == SIGTERM)
    {
        printf("PID du fils : %i, %i SIGSUR1 ont été reçus !\n", getpid(), signaux_recu);
        fflush(stdout);
        exit(1);
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa, sa2;
    sa.sa_handler = handler_pour_signal;
    sa2.sa_handler = handler_pour_signal2;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGTERM, &sa2, NULL);
    while (true)
    {
        pause();
    }
    return EXIT_SUCCESS;
}