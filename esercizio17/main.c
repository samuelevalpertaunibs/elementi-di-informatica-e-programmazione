// Si visualizzi una sequenza di 10 numeri naturali pseudo-casuali compresi tra 10 e 50. Si acquisisca da tastiera un intero n.
// Successivamente per ciascun intero x della sequenza si visualizzi il quoziente e il resto della divisione tra x e n.
// Per svolgere questo compito si definisca ed utilizzi una funzione che inizializza le variabili puntate da due dati puntatori
// con il quoziente e il resto della divisione tra due date variabili intere.
// Scrivere infine una seconda versione della funzione nell’ipotesi che gli unici operatori disponibili siano quelli di somma e sottrazione.

#include "stdio.h"
#include "stdlib.h"

#define DIM 10


void quozienteResto(int dividendo, int divisore, int* quoziente, int* resto);
void quozienteRestoSomma(int dividendo, int divisore, int* quoziente, int* resto);

int main (int argc, char *argv[]){

  int array_int[DIM];
  int num, quoziente, resto;

  // Riempi array
  for(int i = 0; i < DIM; i++){
    array_int[i] = rand() % 41 + 10;
    printf("%d ", array_int[i]);
  }

  // Leggi divisore
   printf("\nInserisci il divisore: ");
  scanf("%d", &num);

  // Fai divisone
  for(int i=0; i < DIM; i++){
    // quozienteResto(array_int[i], num, &quoziente, &resto);
    quozienteRestoSomma(array_int[i], num, &quoziente, &resto);
    printf("Quoziente: %d\nResto: %d\n", quoziente, resto);
  }
  

  return 0;

}


void quozienteResto(int dividendo, int divisore, int* quoziente, int* resto){
  *resto = dividendo % divisore;
  *quoziente = dividendo / divisore;
}

void quozienteRestoSomma(int dividendo, int divisore, int* quoziente, int* resto){

  *quoziente = 0;
  
  while(divisore <= dividendo){
    (*quoziente)++;
    dividendo -= divisore;
  }

  *resto = dividendo;
}