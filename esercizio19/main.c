// Si inizializzi una matrice di 10 righe e 12 colonne con interi pseudo- casuali compresi tra -50 e +50. Visualizzare per
// ciascuna riga della matrice la somma degli interi positivi e negativi presenti sulla riga. Per svolgere questo compito si
// definiscano ed utilizzino due funzioni con le seguenti finalità:
// Produrre la somma degli interi positivi presenti in un dato vettore di n variabili intere
// Produrre la somma degli interi negativi presenti in un dato vettore di n variabili intere

#include "stdio.h"
#include "stdlib.h"

#define ROWS 10
#define COLS 12

int sumPositiveInArray(int array[COLS]);
int sumNegativeInArray(int array[COLS]);

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
    positiveSum = sumPositiveInArray(array[i]);
    negativeSum = sumNegativeInArray(array[i]);
    finalSum = positiveSum + negativeSum;
    
    printf("La somma della riga %d: %d\n", i, finalSum);
  }
  
  return 0;
}

int sumPositiveInArray(int array[COLS]){
  int sum = 0;

  for(int i = 0; i < COLS; i++){
    if(array[i] >= 0){
      sum += array[i];
    }
  }
 
  return sum;
}

int sumNegativeInArray(int array[COLS]){
  int sum = 0;

  for(int i = 0; i < COLS; i++){
    if(array[i] < 0){
      sum += array[i];
    }
  }
 
  return sum;
}