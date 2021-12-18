#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

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
        execl("./exo1fils", "exo1fils", NULL);
        perror("Recouvrement impossible !");
        exit(1);
    }
    else
    {
        //On est dans le père
        sleep(1);
        for (int i = 0; i < atoi(argv[1]); i++)
        {
            kill(ret, SIGUSR1);
        }
        sleep(1);
        kill(ret, SIGTERM);
        waitpid(ret, &status, 0);
    }
    return EXIT_SUCCESS;
}