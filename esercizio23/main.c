// Riempire e visualizzare una tabella di 10 righe e 5 colonne con interi pseudo-casuali compresi tra 1 e 9 (estremi inclusi).
// Successivamente riempire e visualizzare una sequenza di 10 interi con la somma dei numeri pari presenti su ciascuna riga della
// matrice. Per svolgere questo compito si definiscano ed utilizzino tre funzioni C con le seguenti finalità:
// Riempire un dato vettore di n variabili intere con interi pseudo-casuali compresi tra due dati interi.
// Visualizzare un dato vettore di n variabili intere.
// Produrre la somma dei numeri pari in un dato vettore di n variabili intere.


#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define ROWS 10
#define COLS 5

void fillArray(int array[], int dim, int max, int min);
void printArray(int array[], int dim);
int sommaPari(int array[], int dim);

int main(){

  srand(time(NULL));
  int mat[ROWS][COLS];
  int somme[ROWS];

  for(int i = 0; i < ROWS; i++){
    fillArray(mat[i], COLS, 9, 1);
    // printArray(mat[i], COLS);
  }

  for(int i = 0; i < ROWS; i++){
    somme[i] = sommaPari(mat[i], COLS);
  }

  printArray(somme, ROWS);

  return 0;
}

void fillArray(int array[], int dim, int max, int min){
  for(int i = 0; i < dim; i++){
    array[i] = rand() % (max - min + 1) + min;
  }
}

void printArray(int array[], int dim){
  for(int i = 0; i < dim; i ++){
    printf("%d\t", array[i]);
  }
  printf("\n");
}

int sommaPari(int array[], int dim){
  int somma = 0;
  for(int i = 0; i < dim; i++){
    if (array[i] % 2 == 0)
      somma += array[i];      
  }
  return somma;
}