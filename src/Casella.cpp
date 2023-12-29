// Autore: Perin Marco
// ------------------------------
#include "../include/Casella.h"

struct Righe {
  char A, B, C, D, E, F, G, H;
};

Casella::Casella() {
  // Inizializza la casella
  riga = 'A';
  colonna = 1;
  valore = " ";
}

Casella::Casella(char riga, int colonna, std::string valore)
    : riga(riga), colonna(colonna), valore(valore) {}

char Casella::getRiga() { return riga; }
int Casella::getColonna() { return colonna; }
std::string Casella::getValore() { return valore; }

void Casella::stampaCasella() {
  // Stampa la casella (con giocatori e immobili se presenti)
  if (valore == " ") {
    std::cout << "| " << riga << colonna << " | ";
  } else {
    std::cout << "| " << riga << colonna << valore << " | ";
  }
}

Casella::~Casella() {}
