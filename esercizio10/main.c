/*Acquisire da tastiera 5 volte due numeri naturali. Si considerino i naturali acquisiti come il dividendo ed il divisore di una divisione. Dopo avere acquisito tutti i naturali e calcolato tutti i quozienti interi e resti, visualizzare il quoziente intero di ciascuna divisione con resto zero.

Si noti che la fase di elaborazione dei risultati è richiesta essere completata prima della fase di visualizzazione degli stessi.*/

#include "stdio.h"

int main (int argc, char *argv[])
{

    int i, dividendo[5], divisore[5], quoziente[5], resto[5];

    for (i = 0; i < 5; i++) {
        printf("[?] Inserisci dividendo/divisore: ");
        scanf("%d/%d", &dividendo[i], &divisore[i]);
    }

    for (i = 0; i < 5; i++) {
        resto[i] = dividendo[i] % divisore[i];
        quoziente[i] = (dividendo[i] - resto[i]) / divisore[i];
    }

    for (i = 0; i < 5; i++) {
        if (resto[i] == 0) {
            printf("[!] %d/%d = %d\n", dividendo[i], divisore[i], quoziente[i]);
        } 
    }

    


    return 0;
}
