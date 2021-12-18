/* L'envoi d'un signal SIGTERM à un processus endormi, le force à changer d'état et à se terminer, ce qui a pour effet d'interrompre le sleep().*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void catcher(int sig)
{
    printf("Processus interrompu !\n");
}

int main(int argc, char **argv)
{
    pid_t ret = fork();
    if (ret == -1)
    {
        perror("Création impossible !");
        exit(1);
    }
    else if (ret == 0)
    {
        sleep(2);
        kill(getppid(), SIGTERM);
    }
    else
    {
        //On est dans le père
        struct sigaction sact;
        sact.sa_handler = catcher;
        sigaction(SIGTERM, &sact, NULL);
        sleep(100);
    }
    return EXIT_SUCCESS;
}