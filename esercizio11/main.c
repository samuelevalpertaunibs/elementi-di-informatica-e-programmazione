#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DIM 21

int main (int argc, char *argv[])
{
    
    char parola[DIM], anagramma[DIM];
    int n, i, j;

    scanf("%20s", parola);

    n = strlen(parola);

    for (i = 0; i < n; i++) {

       j = rand() % n;
       anagramma[j] = parola[i];

    }

    anagramma[n] = '\n';

    printf("%s\n", anagramma);
    return 0;
}
