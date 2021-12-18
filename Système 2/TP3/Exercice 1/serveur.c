#include "exercice1.h"

int main(int argc, char **argv)
{
    //Création d'une clé.
    key_t cle = ftok(PATH, ID);
    
    //Création de la file.
    int mes_id = msgget(cle, IPC_CREAT | 0660);
    if (mes_id == -1)
    {
        perror("Serveur : Erreur dans création de la file de message.");
        exit(-1);
    }

    //Reception d'une message (de type 1).
    buff message;
    if (msgrcv(mes_id, &message, sizeof(buff) - sizeof(long), 1, 0) == -1)
    {
        perror("Client : Erreur dans la reception");
        exit(3);
    }
    message.valeur = message.valeur * 2;

    if (msgsnd(mes_id, &message, sizeof(buff) - sizeof(long), 0) == -1)
    {
        perror("Serveur : Erreur lors de l'envoi de message.");
        exit(1);
    }
   
    sleep(2); //On attends avant de supprimer la file.

    //Suppression de la file.
    msgctl(mes_id, IPC_RMID, 0);

    return EXIT_SUCCESS;
}