/*Acquisire da tastiera due naturali x e y e visualizzare il loro massimo comune divisore, calcolato verificando se ciascun naturale inferiore a x e y sia o meno divisore di entrambi i naturali x e y. */

#include <stdio.h>

int main (int argc, char *argv[])
{
    
    int x,y,i;
    int mcm,min;

    printf("-> ");
    scanf("%d,%d", &x, &y);

    if (x < y) min = x; else min = y;

    for (i = 1; i <= min; i++) {
        if (x % i == 0 && y % i == 0) {
            mcm = i;
        }
    }

    printf("Il massimo comune divisore è: %d\n", mcm);

    return 0;
}
