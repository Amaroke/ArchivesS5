#ifndef EXERCICE1_H
#define EXERCICE1_H

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

#define PATH "exercice1.h"
#define ID 4

typedef struct buff
{
    long mtype;
    int valeur;
    pid_t pid;
} buff;

#endif