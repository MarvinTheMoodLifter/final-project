// Autore: Perin Marco
// ------------------------------
#include "Casella.h"
#include <iostream>

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

int Casella::getPrezzoProprietà() {
  // Restituisce il prezzo della proprietà
  // Controllo che tipo di casella è
  // se la stringa contiene E all'indice 2, il prezzo è 100
  if (valore.find("E") != std::string::npos) {
    return 6;
  } else if (valore.find("S") != std::string::npos) {
    return 10;
  } else {
    return 20;
  }
}

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

void Casella::setProprietarioCasella(int nuovoProprietario) {
  // Setta il proprietario della casella
  proprietarioCasella = nuovoProprietario;
}

Casella Casella::operator=(const Casella &c) {
  riga = c.riga;
  colonna = c.colonna;
  valore = c.valore;
  return *this;
}
