/*Riempire la prima colonna di una tabella di 10 righe con interi pseudo-casuali compresi tra 10 e 100 e la seconda colonna della tabella con interi pseudo-casuali tali che l’intero sulla i-esima riga e seconda colonna della matrice è compreso tra l’intero sulla i-esima riga e prima colonna della matrice e 100. Successivamente interpretando la coppia di interi presenti su ciascuna riga della matrice come il numeratore ed il denominatore di una frazione visualizzare la frazione ridotta ai minimi termini. Per svolgere questo compito si definisca ed utilizzi una funzione C che produce il massimo comune divisore di due dati interi.*/

#include "stdio.h"
#include "stdlib.h"

#define ROW 10
#define COL 2

int calcolaMassimoComuneDivisore(int num1, int num2){

    int massimoComuneDivisore = 1, min, i;

    if (num1 < num2) min = num1; else min = num2;

    for (i = min; i > 0; i--) {
        if (num1 % i == 0 && num2 % i == 0) {
            massimoComuneDivisore = i;
            break;
        }
    }

    return massimoComuneDivisore;
}

int main (int argc, char *argv[])
{
    int i, array[ROW][COL], massimoComuneDivisore;

    for (i = 0; i < ROW; i++) {
        array[i][0] = rand() % 91 + 10;
        array[i][1] = rand() % 100-array[i][0] + array[i][0];
        printf("%d\t%d\t\n", array[i][0], array[i][1]);
    }

    for (i = 0; i < ROW; i++) {
        massimoComuneDivisore = calcolaMassimoComuneDivisore(array[i][0], array[i][1]);
        printf("Divisione ridotta ai minimi termini: %d/%d\n", array[i][0]/massimoComuneDivisore, array[i][1]/massimoComuneDivisore);
    }


    return 0;
}

