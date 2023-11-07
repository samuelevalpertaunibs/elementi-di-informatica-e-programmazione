/*Riempire una tabella di 4 righe e 3 colonne con interi pseudo-casuali compresi tra 1 e 9 (estremi inclusi). Per ciascuna riga della tabella visualizzare la somma degli interi presenti sulla riga e, successivamente, visualizzare la somma degli interi presenti su ciascuna colonna.*/

#include "stdio.h"
#include "stdlib.h"

#define ROW 4
#define COL 3

int main (int argc, char *argv[])
{
   
    int i, j, mat[ROW][COL], sum_row[ROW], sum_col[COL];

    for (i = 0; i < ROW; i++) {
        sum_row[i] = 0;
    }

    for (i = 0; i < COL; i++) {
        sum_col[i] = 0;
    }
   
    printf("[!] Matrice estratta\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            mat[i][j] = rand() % 10 + 1;

            // stampo il valore appena estratto
            printf("%d\t", mat[i][j]);

            // sommo il valore appena estratto
            sum_row[i] += mat[i][j];
            sum_col[j] += mat[i][j]; 
        }
        printf("\n");
    }

    printf("\n[!] Somma delle righe\n");
    for (i = 0; i < ROW; i++) {
        printf("%d\t", sum_row[i]);
    }

    printf("\n\n[!] Somma delle colonne\n");
    for (i = 0; i < COL; i++) {
        printf("%d\t", sum_col[i]);
    }


    return 0;
}
