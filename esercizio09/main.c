/*Riempire una tabella di 4 righe e 5 colonne con interi pseudo-casuali compresi tra 1 e 9 (estremi inclusi). Riempire una sequenza con 5 numeri interi acquisiti da tastiera. Si supponga che la tabella e la successione di interi rappresentano rispettivamente una matrice e un vettore dell’algebra lineare. Visualizzare il vettore risultante dal prodotto tra la matrice ed il vettore.*/

#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 5

int main (int argc, char *argv[])
{
    int i, j, mat[ROW][COL], vet[COL], ris[ROW];

    // Initialize array
    for (i = 0; i < ROW; i++) {
        ris[i] = 0;        
    }
    
    // Fill the matrix
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            mat[i][j] = rand() % 9 + 1;
        }
    }

    // Print the matrix
    printf("[*] This is the random matrix: \n");
    for (i = 0; i < ROW; i++) {
        printf("|");
        for (j = 0; j < COL; j++) {
            printf("%d\t", mat[i][j]);   
        }
        printf("|\n");
    }

    // Ask for vector
    printf("[?] Insert vector values separated by comma: ");
    scanf("%d, %d, %d, %d, %d", &vet[0], &vet[1], &vet[2], &vet[3], &vet[4]);
    

    // Do the math
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            ris[i] = ris[i] + mat[i][j] * vet[j];
        }
    }

    // Print the result
    printf("[!] This is the result: \n");
   for (i = 0; i < ROW; i++) {
        printf("|%d|\n", ris[i]); 
   } 

    return 0;
}
