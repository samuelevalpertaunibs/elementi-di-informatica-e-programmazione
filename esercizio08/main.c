/*Acquire da tastiera due coppie di interi. Ciascuna coppia indica il numeratore ed il denominatore di una frazione. Visualizzare la somma delle frazioni acquisite ridotta ai minimi termini.*/

#include <stdio.h>

int main (int argc, char *argv[])
{
    int i, num1, den1, num2, den2, num_ris, den_ris, min;

    printf("-> ");
    scanf("%d/%d,%d/%d", &num1, &den1, &num2, &den2);

    den_ris = den1 * den2;

    num_ris = den_ris / den1 * num1;
    num_ris = num_ris + den_ris / den2 * num2;

    // riduzione ai minimi termini
    if (num_ris < den_ris) min = num_ris; else min = den_ris;

    for (i = min; i > 0; i--) {
        if (num_ris % i == 0 && den_ris % i == 0) {
            num_ris = num_ris / i;
            den_ris = den_ris / i;
        }
    }
    
    printf("Risultato: %d/%d\n", num_ris, den_ris);

    return 0;
}
