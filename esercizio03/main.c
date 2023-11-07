/* Acquisire da tastiera una successione di interi che termina con il primo 0 immesso e visualizzare la media degli interi positivi acquisiti. */

#include <stdio.h>

int main (int argc, char *argv[])
{
    int i, n_pos = 0, n;
    float average = 0;
    
    do {

        printf("-> ");
        scanf("%d", &n);
            
        if (n > 0) {
            average = average + n;
            n_pos = n_pos + 1;
        }

    }while (n != 0);

    average = average/n_pos; 

    printf("La media dei numeri positivi inseriti è : %.2f\n", average);

    return 0;
}
