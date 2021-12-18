#include "exercice1.h"

int main(int argc, char **argv)
{
    sleep(1); //On attends un peu que le serveur soit créé.

    //Création d'une clé.
    key_t cle = ftok(PATH, ID);

    //Récupération de la file.
    int mes_id = msgget(cle, 0);
    if (mes_id == -1)
    {
        perror("Client1 : Erreur dans création de la file de message");
        exit(-1);
    }

    //Envoi d'un message.
    buff message;
    message.mtype = 1;
    message.valeur = getpid() % 13;
    message.pid = getpid();
    if (msgsnd(mes_id, &message, sizeof(buff) - sizeof(long), 0) == -1)
    {
        perror("Serveur : Erreur lors de l'envoi de message.");
        exit(1);
    }
    if (msgrcv(mes_id, &message, sizeof(buff) - sizeof(long), getpid(), 0) == -1)
    {
        perror("Client : Erreur dans la reception");
        exit(3);
    }
    printf("Message reçu par %i : (PID : %i, Contenu : %i)\n", getpid(), message.pid, message.valeur);
    fflush(stdout);
    return EXIT_SUCCESS;
}