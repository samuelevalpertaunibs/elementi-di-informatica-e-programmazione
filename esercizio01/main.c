/*Acquisire da tastiera una successione di due interi che termina con due interi positivi.
 Si consideri gli interi acquisiti come il dividendo ed il divisore di una divisione.
 Visualizzare il quoziente intero calcolato utilizzando esclusivamente operazioni di somma e sottrazione.*/

#include <stdio.h>

int main (int argc, char *argv[])
{
    int dividendo, divisore;
    int risultato = 0;
    
    do{ 
        scanf("%d/%d", &dividendo, &divisore);
    } while(dividendo < 0 || divisore < 0);

    while (dividendo >= divisore) {
        dividendo = dividendo - divisore;
        risultato = risultato + 1;
    }

    printf("Il risultato della divisione è: %d\n", risultato);

    return 0;
}
