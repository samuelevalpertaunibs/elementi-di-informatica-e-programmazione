/*Acquisire da tastiera 5 volte due numeri naturali. Si considerino i naturali acquisiti come il dividendo ed il divisore di una divisione. Dopo ciascuna acquisizione visualizzare il quoziente intero ed il resto.*/

#include <stdio.h>

int main (int argc, char *argv[])
{
    int i, quoziente, resto, dividendo, divisore;

    for (i = 0; i < 5; i++) {
        quoziente = 0;
        resto = 0;

        printf("-> ");
        scanf("%d/%d", &dividendo, &divisore);

        resto =  dividendo % divisore;
        quoziente = (dividendo - resto) / divisore;

        printf("Quoziente: %d, Resto: %d\n", quoziente, resto);

    }

    return 0;
}
