#include "exercice1.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        perror("Il faut un argument");
        return EXIT_FAILURE;
    }

    sleep(1); //On attends un peu que le serveur soit créé.

    //Création d'une clé.
    key_t cle = ftok(PATH, ID);

    //Récupération de la file.
    int mes_id = msgget(cle, 0);
    if (mes_id == -1)
    {
        perror("Client : Erreur dans création de la file de message");
        exit(-1);
    }

    //Envoi d'un message.
    buff message;
    message.mtype = 1;
    message.valeur = atoi(argv[1]);
    if (msgsnd(mes_id, &message, sizeof(buff) - sizeof(long), 0) == -1)
    {
        perror("Serveur : Erreur lors de l'envoi de message.");
        exit(1);
    }

    //Reception d'une message (de type 1).
    if (msgrcv(mes_id, &message, sizeof(buff) - sizeof(long), 1, 0) == -1)
    {
        perror("Client : Erreur dans la reception");
        exit(3);
    }
    printf("Message reçu par le client : %i\n", message.valeur);

    return EXIT_SUCCESS;
}