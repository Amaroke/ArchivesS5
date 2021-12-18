#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);
    printf("J'ai %i %s !\n", arg1*arg2, argv[3]);
    fflush(stdout);
    return EXIT_SUCCESS;
}