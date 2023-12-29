// Autore: Perin Marco
// ------------------------------
#include "../include/Casella.h"

struct Righe {
  char A = 'A';
  char B = 'B';
  char C = 'C';
  char D = 'D';
  char E = 'E';
  char F = 'F';
  char G = 'G';
  char H = 'H';
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

void Casella::setValore(std::string valore) { this->valore = valore; }

void Casella::stampaCasella() {
  // Stampa la casella (con giocatori e immobili se presenti)
  if (valore == " ") {
    // std::cout << "| " << riga << colonna << " | ";
    std::cout << "|   | ";
  } else {
    // std::cout << "| " << riga << colonna << valore << " | ";
    std::cout << "| " << valore << " | ";
  }
}

bool Casella::validaCasella() {
  // Controlla se la casella è valida, ovvero se è presente nel tabellone.
  // Se la casella è valida ritorna true, altrimenti false.
  Righe righe;
  // Controllo righe A e H
  if ((riga == righe.A || riga == righe.H) & (colonna >= 1 && colonna <= 9)) {
    return true;
  }
  // Controllo colonne 1 e 9
  else if ((riga >= righe.B && riga <= righe.G) &&
           (colonna == 1 || colonna == 9)) {
    return true;
  }
  return false;
}

Casella Casella::operator=(const Casella &c) {
  riga = c.riga;
  colonna = c.colonna;
  valore = c.valore;
  return *this;
}
