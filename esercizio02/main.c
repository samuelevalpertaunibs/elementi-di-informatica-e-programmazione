/* Acquisire da tastiera una successione di naturali che termina con 0 e al termine delle acquisizioni visualizzare la quantità di numeri primi acquisiti*/ 
#include <stdio.h>

int main (int argc, char *argv[])
{
    int i, n_primi = 0, n_div, n;
    
    do {

    printf("-> ");
    scanf("%d", &n);
        
    n_div = 0;
    for (i = 1; i <= n; i++) {
        if (n % i == 0) n_div = n_div + 1;
    }

    if (n_div == 2) n_primi = n_primi + 1;

    }
    while (n != 0);

    
    printf("Numeri primi acquisiti: %d\n", n_primi);
    return 0;
}
