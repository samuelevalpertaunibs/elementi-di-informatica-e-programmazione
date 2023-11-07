// Si inizializzi una matrice di 10 righe e 12 colonne con interi pseudo-casuali compresi tra -50 e +50. Visualizzare per ciascuna
// riga della matrice la somma degli interi positivi e negativi presenti sulla riga. Per svolgere questo compito si definisca ed
// utilizzi una funzione che inizializza gli interi puntati da due dati puntatori a variabili intere con la somma dei numeri positivi
// e la somma dei numeri negativi presenti in un dato vettore di n variabili intere.

#include "stdio.h"
#include "stdlib.h"

#define ROWS 10
#define COLS 12

void calcolaSomme(int* negativeSum, int* positiveSum, int array[COLS]);

int main(int argc, char* argv[]){

  int array[ROWS][COLS];
  int positiveSum, negativeSum, finalSum;

  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      array[i][j] = rand() % 101 - 50;
      printf("%d\t", array[i][j]);
    }
    printf("\n");
  }

  for(int i = 0; i < ROWS; i++){

    positiveSum = 0;
    negativeSum = 0;
    
    calcolaSomme(&negativeSum, &positiveSum, array[i]);
    finalSum = positiveSum + negativeSum;

    printf("La somma della riga %d: %d\n", i, finalSum);
  }
  
  return 0;
}

void calcolaSomme(int* positiveSum, int* negativeSum, int array[COLS]){

  for(int i = 0; i < COLS; i++){
    if(array[i] >= 0){
      (*positiveSum) = (*positiveSum) + array[i];
    }else{
      (*negativeSum) = (*negativeSum) + array[i];
    }
  }
  
}