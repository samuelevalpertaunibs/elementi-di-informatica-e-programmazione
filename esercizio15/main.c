/*Si consideri una sequenza di 10 numeri naturali pseudo-casuali compresi tra 1 e 100. Si visualizzi la sequenza. Successivamente si visualizzi il naturale con la maggior quantità di divisori. Per svolgere questo compito si definisca ed utilizzi una funzione che produca la quantità di divisori di un dato intero.*/

#include "stdio.h"
#include "stdlib.h"

#define DIM 10

int calcolaNumeroDivisori(int numero){

    int i, num_divisori = 0;
    
    for (i = 1; i < numero; i++) {
    
        if (numero % i == 0){
            num_divisori++;
        }
    
    }

    return num_divisori;
}

int main (int argc, char *argv[])
{
    
    int array[DIM];
    int max_divisori, index_of_max, i, divisori_curr;

    // Inizializza e stampa array
    for (i = 0; i < DIM; i++) {

        array[i] = rand() % 100 + 1;

        printf("%d\t", array[i]);
    }

    max_divisori = 0;
    index_of_max = 0;

    // Calcola numero com max divisori
    for (i = 0; i < DIM; i++) {

        divisori_curr = calcolaNumeroDivisori(array[i]);

            if (divisori_curr > max_divisori) {
                max_divisori = divisori_curr;
                index_of_max = i;
            }
    }

    printf("\nIl numero %d è quello con il maggior numero di divisori: %d\n", array[index_of_max], max_divisori);

    return 0;
}
