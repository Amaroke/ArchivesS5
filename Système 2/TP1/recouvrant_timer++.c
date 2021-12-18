#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv)
{
    srand(getpid());
    int random = (rand()%8)+5;
    if (atoi(argv[1]) == 1)
    {
        usleep(1000000 * random);
        kill(getppid(), SIGUSR1);
    }
    if (atoi(argv[1]) == 2)
    {
        usleep(1000000 * random);
        kill(getppid(), SIGUSR2);
    }
}