/* Acquisire 5 numeri naturali e per ognuno mostrare il numero di suoi divisori*/

#include <stdio.h>

int main (int argc, char *argv[])
{
    int a
    int n, i, n_div, j;

    for (i = 1; i <= 5; i++) {

        printf("-> ");
        scanf("%d", &n);
        
        n_div = 0;

        for (j = 1; j <= n; j++) {
            if (n % j == 0) n_div = n_div + 1;
        }

        printf("Numero divisori: %d\n", n_div);
    }

    return 0;
}
