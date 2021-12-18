/* Dans les deux cas si le signal est masqué dans le père il est aussi masqué dans le fils.*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void catcher(int sig)
{
    printf("Signal interrompu !\n");
    fflush(stdout);
}

int main(int argc, char **argv)
{
    struct sigaction sact;
    sact.sa_handler = catcher;
    sigemptyset(&(sact.sa_mask));
    sigaction(SIGUSR1, &sact, NULL);
    sigset_t masque, masque_avant;
    sigaddset(&masque, SIGUSR1);
    sigprocmask(SIG_SETMASK, &masque, &masque_avant);
    pid_t ret = fork();
    if (ret == -1)
    {
        perror("Création impossible !");
        exit(1);
    }
    else if (ret == 0)
    {
        //On est dans le fils 1
        execl("./question3_recouvrant", "question3_recouvrant", NULL);
        perror("Recouvrement impossible !");
        exit(1);;
    }
    else
    {
        //On est dans le père
        sleep(1);
        kill(getpid(), SIGUSR1);
        sleep(3);
    }
    return EXIT_SUCCESS;
}