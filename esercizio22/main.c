// Si riempia e visualizzi una sequenza di 10 numeri reali con numeri pseudo-casuali differenti compresi tra 0 e 1, di modo che la
// sequenza sia costantemente mantenuta ordinata. Si acquisisca da tastiera un reale; si cancelli il reale dalla sequenza di reali;
// si visualizzi la sequenza risultante. Per svolgere questo compito si considerino reali con 2 cifre di precisione dopo la virgola e
// si definiscano 4 funzioni con le seguenti finalità:

// Inserire un dato reale in una data sequenza ordinata di n numeri reali, mantenendo la sequenza ordinata e producendo la nuova lunghezza della sequenza.
// Visualizzare una data sequenza di n numeri reali
// Produrre la posizione di un dato reale in una data sequenza di n numeri reale, se presente; produrre -1 altrimenti.
// Cancellare una dato numero reale da una data sequenza di n numeri reali producendo la nuova lunghezza della sequenza

#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define DIM 10

void printSequence(float seq[], int size);
int add(float seq[], float num, int size);
int searchIndex(float seq[], float num, int size);
int delete(float seq[], float num, int size);

int main()
{
    srand(time(NULL));

    float seq[DIM], num;
    int size = 0;

    while (1) {
      num = (rand() % 101) / 100.;
      // printf("%f\n", num);
      size = add(seq, num, size);
      // printf("%d\n", size);
      if (size == 10)
        break;
    };

    printf(" Sequenza ordinata di numeri casuali:\n");
    printSequence(seq, size);

    printf("\n Quale numero reale vuoi cancellare? ");
    scanf("%f", &num);

    size = delete(seq, num, size);
    printSequence(seq, size);

    return 0;
}

void printSequence(float seq[], int size){
  for (int i = 0; i < size; i++){
    printf("%.2f\t", seq[i]);
  }
  printf("\n");
}

int add(float seq[], float num, int size){
  if (searchIndex(seq, num, size) >= 0 || size == 10)
    return size;
  
  int i;
  for(i = size - 1; i >= 0 && seq[i] > num; i--)
    seq[i+1] = seq[i];
  seq[i+1] = num;
  return size+1;
}

int searchIndex(float seq[], float num, int size){
  for (int i = 0; i < size; i++){
    if (seq[i] == num)
      return i; 
  }
  return -1;
}

int delete (float seq[], float num, int size) {
  int i, pos = searchIndex(seq, num, size);
  if (pos >= 0) {
    for (int i = pos; i < size-1 ; i++) {
      seq[i] = seq[i+1];
    }
    size--;
  }else
    printf("\n WARNING: Number %.2f not found!!!", num);
    
  return size;
  
}
