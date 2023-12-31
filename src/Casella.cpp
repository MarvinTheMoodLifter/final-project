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

Casella::Casella(char riga, int colonna) : riga(riga), colonna(colonna) {
  coordinate.push_back(std::to_string(riga));
  coordinate.push_back(std::to_string(colonna));
}

std::string Casella::getValore() { return valore; }
char Casella::getRiga() { return riga; }
int Casella::getColonna() { return colonna; }
void Casella::setValore(std::string v) { valore = v; }
void Casella::addValore(std::string v) { valore += v; }

void Casella::aggiungiGiocatore(std::string giocatore) {
  // Aggiunge un giocatore alla Casella
  valore += giocatore;
}

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

bool Casella::isVuota() {
  // Restituisce true se la casella è vuota
  return valore == " " ? true : false;
}

void Casella::rimuoviGiocatore(std::string giocatore) {
  // Rimuove un giocatore dalla Casella
  if (isVuota()) {
    valore = " ";
  } else {
    // Altrimenti rimuove il giocatore dalla stringa valore
    valore.erase(valore.find(giocatore), 1);
  }
}
void Casella::aggiungiImmobile(int giocatore) {
  // Aggiunge un immobile alla Casella
  // Check se giocatore ha abbastanza soldi
  // TODO
  std::string casa = "*";
  std::string albergo = "^";
  // Se la casella è vuota, aggiunge il giocatore alla casella
  if (isVuota()) {
    valore += casa;
  } else if (valore == casa) {
    // Altrimenti aggiunge il giocatore alla stringa valore
    valore.erase(valore.find(casa), 1);
    // Aggiunge l'albergo PRIMA del giocatore nella stringa valore
    valore.insert(valore.find(giocatore), albergo);
  }
}

Casella Casella::operator=(const Casella &c) {
  riga = c.riga;
  colonna = c.colonna;
  valore = c.valore;
  return *this;
}
