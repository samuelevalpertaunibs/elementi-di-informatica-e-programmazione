// Riempire e visualizzare una tabella di 10 righe e 10 colonne con interi pseudo-casuali compresi tra 10 e 99 (estremi inclusi).
// Riempire una sequenza di 10 interi con la somma dei numeri pari presenti su ciascuna riga della tabella ed una sequenza di 10
// interi con la somma dei numeri dispari. Per svolgere questo compito si definisca ed utilizzi una funzione C che inizializza gli
// interi puntati da due dati puntatori a variabile intera con la somma dei numeri pari e dispari presenti in un dato vettore di n
// variabili intere.

#include "stdio.h"
#include "stdlib.h"

#define DIM 10

void calcolaSomme(int array[DIM], int* sommaPari, int* sommaDispari);

int main(int argc, char *argv[]){

  int mat[DIM][DIM], sommePari[DIM], sommeDispari[DIM];
  int sommaPari, sommaDispari;

  for(int i = 0; i < DIM; i++){
    for(int j = 0; j < DIM; j++){
      mat[i][j] = rand() % 90 + 10;
      printf("%d\t", mat[i][j]);
    }
    printf("\n");
  }

  for(int i = 0; i < DIM; i++){
    calcolaSomme(mat[i], &sommePari[i], &sommeDispari[i]);
    printf("Riga: %d\tsomma pari: %d\tsomma dispari: %d\n", i, sommePari[i], sommeDispari[i]);
  }
  
}

void calcolaSomme(int array[DIM], int* sommaPari, int* sommaDispari){
  for(int i = 0; i < DIM; i++){
    if(array[i] % 2 == 0) *sommaPari += array[i]; else *sommaDispari += array[i];
  }
}


