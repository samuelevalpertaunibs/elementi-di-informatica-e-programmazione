// Elementi di Informatica e Programmazione 22/23
// Elaborato di fine corso
// Samuele Valperta, 739885

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int statoPenna;
  // 0 penna alzata
  // 1 penna abbssata
  int direzione;
  // 0 su
  // 1 destra
  // 2 giu
  // 3 sinistra
} Tartaruga;

Tartaruga tartaruga;
int righe, colonne;
int posX, posY;
// Creo la griglia con dimensione massima
char griglia[25][100];
char vecchio_char = ' ';

void inizializzaVettore(char vettore[], char c);
void stampaGriglia();
void aggiornaGriglia(int passi);

int getMin(int n1, int n2) { return (n1 > n2) ? n2 : n1; }
int getMax(int n1, int n2) { return (n1 < n2) ? n2 : n1; }

int main(int argc, char *argv[]) {

  do {
    printf("Inserire COLONNExRIGHE: ");
    scanf("%dx%d", &colonne, &righe);
  } while ((righe < 1 || righe > 25) || (colonne < 1 || colonne > 100));

  // Inizializzo la griglia
  for (int i = 0; i < righe; i++) {
    inizializzaVettore(griglia[i], ' ');
  }

  // Inizializzo la tartaruga e la sua posizione nella griglia
  tartaruga.direzione = 0;
  tartaruga.statoPenna = 0;

  posX = colonne / 2 - 1;
  posY = righe / 2 - 1;

  // Evitare che la partenza sia in -1 se c'è solo una riga o colonna
  if (righe == 1)
    posY = 0;
  if (colonne == 1)
    posX = 0;

  // "Disegno" la tartaruga nella griglia all'inizio del gioco
  griglia[posY][posX] = (tartaruga.statoPenna) ? 'I' : 'O';

  int scelta, passi;

  do {

    // Stampo griglia
    stampaGriglia();

    printf("Posizione attuale: (%d,%d)\tDirezione: ", posX, posY);
    switch (tartaruga.direzione % 4) {
    case 0:
      printf("su\n");
      break;
    case 1:
      printf("destra\n");
      break;
    case 2:
      printf("giu\n");
      break;
    case 3:
      printf("sinistra\n");
      break;
    }

    printf("Scegliere il comando:\n1.%s penna  2.Gira dx  3.Gira sx  4,n "
           "Avanti n spazi  9.Esci\n",
           (tartaruga.statoPenna) ? "Alza" : "Abbassa");
    scanf("%d,%d", &scelta, &passi);

    switch (scelta) {
    case 1:
      tartaruga.statoPenna = !tartaruga.statoPenna;
      griglia[posY][posX] = (tartaruga.statoPenna) ? 'I' : 'O';
      if (griglia[posY][posX] == 'I')
        vecchio_char = '*';
      break;
    case 2:
      tartaruga.direzione++;
      break;
    case 3:
      // Aggiungo 4 (se serve) per evitare che tartaruga.direzione sia negativo
      // e non possa più usare direzione%4
      if (tartaruga.direzione == 0)
        tartaruga.direzione += 4;
      tartaruga.direzione--;
      break;
    case 4:
      if (passi >= 0)
        aggiornaGriglia(passi);
      break;
    case 9:
      // Stampa la griglia senza il "cursore" ed esci
      griglia[posY][posX] = vecchio_char;
      stampaGriglia();
      return 0;
      break;
    }

  } while (1);

  return 0;
}

// Funzione che inizializza un vettore di char con un carattere
void inizializzaVettore(char vettore[], char c) {
  for (int i = 0; i < colonne; i++) {
    vettore[i] = c;
  }
}

// Funzione che stampa la griglia di gioco
void stampaGriglia() {
  // Stampa bordo supoeriore, -2 per equipare gli | delle singole righe
  for (int i = -2; i < colonne; i++) {
    printf("-");
  }
  printf("\n");

  for (int i = 0; i < righe; i++) {
    printf("|");
    for (int j = 0; j < colonne; j++) {
      printf("%c", griglia[i][j]);
    }
    printf("|\n");
  }

  // Stampa bordo inferiore
  for (int i = -2; i < colonne; i++) {
    printf("-");
  }
  printf("\n");
}

// Aggiorna la griglia
void aggiornaGriglia(int passi) {

  if (tartaruga.statoPenna) {
    int i;
    // Disegna punto iniziale
    griglia[posY][posX] = '*';

    switch (tartaruga.direzione % 4) {
    // su
    case 0:
      for (i = 0; i < passi && posY > 0; i++) {
        posY--;
        griglia[posY][posX] = '*';
      }
      // posY = posY - getMin(passi, posY);
      break;
    // dx
    case 1:
      for (i = 0; i < passi && posX < colonne - 1; i++) {
        posX++;
        griglia[posY][posX] = '*';
      }
      break;
    // giu
    case 2:
      for (i = 0; i < passi && posY < righe - 1; i++) {
        posY++;
        griglia[posY][posX] = '*';
      }
      // posY = posY + getMin(passi, righe - posY - 1);
      break;
    // sx
    case 3:
      for (i = 0; i < passi && posX > 0; i++) {
        posX--;
        griglia[posY][posX] = '*';
      }
      // posX = posX - getMin(passi, posX);
      break;
    }

    // Disegna e salva nuova griglia
    vecchio_char = '*';
    griglia[posY][posX] = 'I';

  } else {
    // Sposta la posizione direttamente

    griglia[posY][posX] = vecchio_char;

    switch (tartaruga.direzione % 4) {
    // su
    case 0:
      posY = posY - getMin(passi, posY);
      break;
    // dx
    case 1:
      posX = posX + getMin(passi, colonne - posX - 1);
      break;
    // giu
    case 2:
      posY = posY + getMin(passi, righe - posY - 1);
      break;
    // sx
    case 3:
      posX = posX - getMin(passi, posX);
      break;
    }

    // Disegna e salva nuova griglia
    vecchio_char = griglia[posY][posX];
    griglia[posY][posX] = 'O';
  }
}