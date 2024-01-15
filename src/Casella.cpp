// Autore: Perin Marco
// ------------------------------
#include "Casella.h"
#include <iostream>

struct Righe {
  // Contiene le righe del tabellone
  char A = 'A';
  char B = 'B';
  char C = 'C';
  char D = 'D';
  char E = 'E';
  char F = 'F';
  char G = 'G';
  char H = 'H';
};

// Costruttore
Casella::Casella(char riga, int colonna) : riga(riga), colonna(colonna) {
  coordinate.push_back(std::to_string(riga));
  coordinate.push_back(std::to_string(colonna));
}

// Getters
int Casella::getPrezzoProprietà() {
  // Restituisce il prezzo della proprietà in base alla tipologia
  if (tipologia == 'E') {
    return 6;
  } else if (tipologia == 'S') {
    return 10;
  } else if (tipologia == 'L') {
    return 20;
  }
  // Se la casella non è una proprietà, restituisce 0
  return 0;
}
int Casella::getAffitto() {
  // Restituisce l'affitto della casella, in base alla tipologia e all'immobile
  int moltiplicatoreAlbergo = 2;
  int valoreAffitto;
  if (tipologia == 'E') {
    valoreAffitto = 2;
  } else if (tipologia == 'S') {
    valoreAffitto = 4;
  } else if (tipologia == 'L') {
    valoreAffitto = 7;
  }
  // Se l'immobile è un albergo, moltiplica l'affitto per 2
  if (immobile == '^') {
    valoreAffitto *= moltiplicatoreAlbergo;
  }
  if (immobile == ' ') {
    valoreAffitto = 0;
  }
  return valoreAffitto;
}
int Casella::prezzoMiglioramentoImmobile() {
  // Restituisce il prezzo dell'immobile in base alla tipologia
  if (tipologia == 'E') {
    return 3;
  } else if (tipologia == 'S') {
    return 5;
  } else if (tipologia == 'L') {
    return 10;
  }
  return 0;
}
bool Casella::isVuota() {
  // Restituisce true se nella casella non ci sono giocatori
  return giocatoriPresenti == " " ? true : false;
}
bool Casella::isAngolare() {
  // Restituisce true se la casella è angolare
  if (riga == 'A' || riga == 'H') {
    if (colonna == 1 || colonna == 8) {
      return true;
    }
  }
  return false;
}

// Setters
void Casella::setImmobile(char i) { immobile = i; }
void Casella::setTipologia(char t) { tipologia = t; }
void Casella::setProprietarioCasella(int nuovoProprietario) {
  // Setta il proprietario della casella
  proprietarioCasella = nuovoProprietario;
}
void Casella::setProprietario(Giocatore *nuovoProprietario) {
  // Setta il proprietario della casella
  proprietario = nuovoProprietario;
}
void Casella::aggiungiGiocatore(std::string giocatore) {
  // Aggiunge un giocatore alla Casella
  giocatoriPresenti += giocatore;
}
void Casella::rimuoviGiocatore(std::string giocatore) {
  if (!isVuota()) {
    // Rimuove il giocatore dalla stringa giocatoriPresenti
    giocatoriPresenti.erase(giocatoriPresenti.find(giocatore), 1);
  }
}
void Casella::miglioraImmobile() {
  // Migliora l'immobile
  if (immobile == ' ') {
    immobile = '*';
  } else if (immobile == '*') {
    immobile = '^';
  }
}

// Stampa
void Casella::stampaCasella() {
  // Stampa la casella (con tipologia, giocatori e immobili se presenti)
  if (isVuota()) {
    std::cout << "| " << tipologia << immobile << " | ";
  } else {
    // std::cout << "| " << riga << colonna << valore << " | ";
    std::cout << "|" << tipologia << immobile << giocatoriPresenti << "| ";
  }
}

// Copy assignment operator
Casella Casella::operator=(const Casella &c) {
  riga = c.riga;
  colonna = c.colonna;
  proprietarioCasella = c.proprietarioCasella;
  coordinate = c.coordinate;
  immobile = c.immobile;
  tipologia = c.tipologia;
  giocatoriPresenti = c.giocatoriPresenti;
  prezzoProprietà = c.prezzoProprietà;
  return *this;
}
