// Riempire una sequenza con 10 interi acquisiti da tastiera e successivamente visualizzare per ciascun intero pari x maggiore di 2 nella
// sequenza la coppia di numeri primi la cui somma è uguale ad x. Per svolgere questo compito si definiscano ed utilizzino due funzioni C
// con le seguenti finalità:
// -Produrre 1 se un dato intero è primo e produrre 0 altrimenti.
// -Inizializzare gli interi puntati da due dati puntatori a variabile intera con i due numeri primi la cui somma è pari ad un dato intero.

#include "stdio.h"
#include "stdlib.h"

#define DIM 10

int isPrimo(int num){
  
  int numDivisori = 0;

  for (int i = 2; i < num; i++){
    if (num % i == 0){
      numDivisori++;
    }
  }

  return (numDivisori == 0 && num != 1);
}

void coppiaNumeriPrimi(int num, int* primo1, int* primo2){
  for (int i = 1; i < num; i++){
    if (isPrimo(i)){
      if (isPrimo(num - i)){
        *primo1 = i;
        *primo2 = num - i;
      }
    }
  }
} 

int main (int argc, char *argv[])
{

  int array[DIM], primo1, primo2;

  for (int i = 0; i < DIM; i++){
    printf("-> ");
    scanf("%d", &array[i]);
  }

  
for (int i = 0; i < DIM; i++){
    if( array[i] % 2 == 0 && array[i] > 2){
      coppiaNumeriPrimi(array[i], &primo1, &primo2);
      printf("%d = %d + %d\n", array[i], primo1, primo2);
    }
  
}

}