/*Si consideri una tabella di 5 righe e 12 colonne di interi pseudo-casuali compresi tra -20 e +80. Si visualizzi la tabella e successivamente, per ciascuna colonna della tabella, si visualizzi la media degli interi positivi presenti sulla colonna.*/

#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 12

int main (int argc, char *argv[])
{
    int mat[ROW][COL];
    int i,j,average,count;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            mat[i][j] = rand() % 101 - 20;
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    } 

    printf("Media\n");
    for (i = 0; i < COL; i++) {
        count = 0;
        average = 0;
        for (j = 0; j < ROW; j++) {
            if (mat[j][i] >= 0) {
                average = average + mat[j][i];
                count++;
            }
        } 
        if (count > 0) {
            average = average / count;
            printf("%d\t", average);
        } else {
            printf("Nessun numero positivo.");
        }
    }
    printf("\n");
    
    return 0;
}
