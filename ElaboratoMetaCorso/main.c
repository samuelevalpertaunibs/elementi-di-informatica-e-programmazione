/*Permettere a due giocatori (umani) di effettuare una partita al classico gioco del tris. Il gioco prevede la presenza di una griglia 3×3 sulla quale i giocatori posizionano, ciascuno rispettando il proprio turno, una X o un O. Ovvero ciascun giocatore immette da tastiera le coordinate della casella all'interno della griglia nella quale posizionare il proprio contrassegno. La partita termina quando uno dei due giocatori riesce a mettere tre simboli uguali sulla stessa riga, sulla stessa colonna oppure su una delle due diagonali della griglia. Se nessuna di queste condizioni si verifica, la partita termina con un pareggio.*/

#include "stdlib.h"
#include "stdio.h"

#define DIM 3

char grid[DIM][DIM];

void initializeGrid(){
    int i, j;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            grid[i][j] = ' ';
        }
    }
}

void printGrid() {
    int i, j;
    printf("\n");
    for (i = 0; i < DIM; i++) {
        printf("+---+---+---+\n");
        for (j = 0; j < DIM; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
    }
    printf("+---+---+---+\n");

    printf("\n");
}

int checkRows(char player){

    int i, j;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {

            // stop checking this row when one wrong char is found
            if (grid[i][j] != player) {
                break;
            } else {
                // If all char were right and this is the last of the row it's a tris
                if (j == DIM - 1) {
                    
                    return 1;
                }
            }
        }
    }
    return 0;

}

int checkCols(char player){

    int i, j;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {

            // stop checking this col when one wrong char is found
            if (grid[j][i] != player) {
                break;
            } else {
                // If all char were right and this is the last of the col it's a tris
                if (j == DIM - 1) {
                    return 1;
                }
            }
        }
    }
    return 0;

}

int checkDiag(char player){
    int i, j;
    for (i = 0; i < DIM; i++) {
        if (grid[i][i] != player) {
            break;
        } else {
            if ( i == DIM - 1) {
                return 1;
            }
        }
    }

    for (i = 0, j = DIM - 1; i < DIM; i++, j--) {
        if (grid[i][j] != player){
        break;
        } else {
            if (i == DIM - 1) {
                return 1;
            }
        }
        
    }
    return 0;
}

int checkWin(char player){
    return checkRows(player) || checkCols(player) || checkDiag(player);
}

void play(char player){
    
    int i, j;
    while (1) {
    printf("[?] Giocatore %c. Inserisci riga,colonna: ", player);
    scanf("%d,%d", &i, &j);
    if ( grid[i][j] == ' ' && i < DIM && j < DIM){
        break;
    }
    }

    grid[i][j] = player;
}


int main (int argc, char *argv[])
{
    char player[2] = "XO";
    int currentPlayer = 1;
    int round = 1;

    initializeGrid();

    while(1){
        printGrid();

        // Change the current player and let it play
        if (currentPlayer) {
            currentPlayer = 0;
        } else {
            currentPlayer = 1;
        }
       
        printf("------------------------------ ROUND %d ------------------------------\n", round);
        play(player[currentPlayer]);


        if (checkWin(player[currentPlayer])){
            printGrid();
            printf("[!] Ha vinto il giocatore %c\n", player[currentPlayer]);
            return 0;
        } else {
        if (round == DIM*DIM) {
            printGrid();
            printf("[!] La partita è finita in parità.\n");
            return 0;
        }
        }


        round++;
    }
        

    return 0;
}
