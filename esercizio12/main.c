/*Si acquisisca da tastiera una parola, assumendo che la parola acquisita contenga al massimo 20 lettere.
 * Si visualizzi la parola acquisita al contrario.
 * Svolgere l'esercizio con e esenza l'uso di un secondo vettore per la memorizzazione della parola ribaltata*/

#include "stdio.h"
#include "string.h"

#define DIM 21

int main (int argc, char *argv[])
{
    char parola[DIM];
    char parola_ribaltata[DIM];
    int n, i, j;

    scanf("%20s", parola);

    n = strlen(parola);

    // for (i = n - 1; i >= 0; i--) {
    //     printf("%c", parola[i]);
    // }

    for (i = n - 1, j = 0; i >= 0; i--, j++) {
        parola_ribaltata[j] = parola[i]; 
    }

    printf("%s\n", parola_ribaltata);

    return 0;
}
