/*Si acquisisca da tastiera una sequenza di parole che termina con la 50-esima parola acquisita o con l’acquisizione della parola “fine”. Si assume per questo che le parole acquisite contenga al massimo 20 lettere. Successivamente si visualizzi quali parole seguono lessicograficamente la prima parola acquisita. */

#include "stdio.h"
#include "string.h"

#define DIM 50

int main (int argc, char *argv[])
{

    char seq[DIM][21];
    int i = 0, j;

    do {
        printf("[?] Inserisci una parola: ");
        scanf("%20s", seq[i]);
        i++;

    } while( i < DIM && strncmp(seq[i-1], "fine", 4));

    for (j = 0; j < i-1; j++) {
        if (strncmp(seq[0], seq[j], strlen(seq[0])) < 0) {
            printf("%s\n", seq[j]);
        }
    }

    return 0;
}


