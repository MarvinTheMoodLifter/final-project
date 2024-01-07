// Autore: Perin Marco
// ------------------------------
#include "Tabellone.h"
#include <algorithm>
#include <iostream>
#include <random>

Tabellone::Tabellone() {
  // Riempie la prima parte di tabellone con le caselle vuote
  riempiTabellone();
  // Riempie le caselle del tabellone in maniera randomica
  riempiCaselleRandom();
  // Crea i giocatori
}

void Tabellone::riempiTabellone() {
  // Riempie la prima parte di tabellone con le caselle vuote
  for (char riga = 'H'; riga > 'A'; riga--) {
    for (int colonna = 8; colonna >= 1; colonna--) {
      if (riga == 'H' || colonna == 1) {
        tabellone.push_back(Casella(riga, colonna));
      }
    }
  }
  // Riempie la seconda parte di tabellone con le caselle vuote
  for (char riga = 'A'; riga < 'H'; riga++) {
    for (int colonna = 1; colonna <= 8; colonna++) {
      if (riga == 'A' || colonna == 8) {
        tabellone.push_back(Casella(riga, colonna));
      }
    }
  }
}

void Tabellone::randomizzaVettore(std::vector<std::string> &v) {
  // Genera un seme casuale
  std::random_device randomSeed;
  // Genera numeri casuali a partire dal seme generato in precedenza
  std::mt19937 gen(randomSeed());
  // Mescola il vettore
  std::shuffle(v.begin(), v.end(), gen);
}

void Tabellone::riempiCaselleRandom() {
  // Creo un vettore di char con i tipi di caselle
  // 8 caselle economiche
  // 10 caselle standard
  // 6 caselle lusso
  std::vector<std::string> tipiCaselle = {
      "E", "E", "E", "E", "E", "E", "E", "E", "S", "S", "S", "S",
      "S", "S", "S", "S", "S", "S", "L", "L", "L", "L", "L", "L"};
  randomizzaVettore(tipiCaselle);
  // Inizializzo la casella di partenza
  tabellone[0].setValore("P");
  int count = 0;
  for (int i = 1; i < 28; i++) {
    char rigaCasella = tabellone[i].getRiga();
    int colonnaCasella = tabellone[i].getColonna();
    // Salta le caselle agli angoli
    if (rigaCasella == 'A' && colonnaCasella == 1 ||
        rigaCasella == 'A' && colonnaCasella == 8 ||
        rigaCasella == 'H' && colonnaCasella == 1) {
      count++;
      tabellone[i].setValore(" ");
      continue;
    }
    tabellone[i].setValore(tipiCaselle[i - 1 - count]);
  }
}

void Tabellone::muoviGiocatore(Giocatore giocatore) {
  // Prendo la posizione attuale del giocatore
  int vecchiaPosizione = giocatore.getPosizione();
  bool passaVia = false;
  // Creo dadi e li tiro
  Dadi dadi(6);
  int mossa = dadi.tiraDadi(2);
  // Genero l'indice della nuova posizione
  int nuovaPosizione = vecchiaPosizione + mossa;
  // Nel caso in cui la nuova posizione sia maggiore di 27, il giocatore passa
  // dal via
  if (nuovaPosizione > 27) {
    nuovaPosizione -= 27;
    bool passaVia = true;
  }
  Casella vecchiaCasella = tabellone[vecchiaPosizione];
  Casella nuovaCasella = tabellone[nuovaPosizione];
  int numGiocatore = giocatore.getNumeroGiocatore();
  // Sposto il Giocatore
  giocatore.setPosizione(nuovaPosizione);
  // Cambio il valore della casella
  vecchiaCasella.rimuoviGiocatore(std::to_string(numGiocatore));
  nuovaCasella.aggiungiGiocatore(std::to_string(numGiocatore));
  // Controllo se la casella è posseduta da un altro giocatore
  int proprietarioCasella = nuovaCasella.getProprietarioCasella();
  if (proprietarioCasella == giocatore.getNumeroGiocatore())
    return;
  if (proprietarioCasella == 0) {
    std::cout << "La casella è libera, vuoi acquistarla? (s->si, n->no, show->"
                 "mostra il tabellone)"
              << std::endl;
    for (int i = 0; i < 3; i++) {
      if (std::cin.get() == 's' &&
          giocatore.getFiorini() >= nuovaCasella.getPrezzoProprietà()) {
        // Acquista la casella
        nuovaCasella.setProprietarioCasella(numGiocatore);
      } else if (std::cin.get() == 'show') {
        stampaTabellone();
      }
    }
  }
}

void Tabellone::stampaTabellone() {
  // Stampa il tabellone a partire dalla prima riga, poi le righe intermedie ed
  // infine l'ultima riga Stampa la prima riga
  // Prima riga
  for (int i = tabellone.size() - 14; i < tabellone.size() - 6; i++) {
    tabellone[i].stampaCasella();
  }
  std::cout << std::endl;
  // Righe intermedie
  for (int i = 0; i < 6; i++) {
    // Stampa la colonna di sinistra
    tabellone[13 - i].stampaCasella();
    // Stampa il logo centrale
    switch (i) {
    case 0:
      std::cout << "  .. ..                     .       ";
      break;
    case 1:
      std::cout << "  ::::: ::: ::: ::: ::: ::: : : :   ";
      break;
    case 2:
      std::cout << "  : : : : : : : : : : : : : : : :   ";
      break;
    case 3:
      std::cout << "  :. .: ::: : : ::: ::: ::: :  ::   ";
      break;
    case 4:
      std::cout << "                    :          :    ";
      break;
    case 5:
      std::cout << "                    \'         \'     ";
      break;
    }
    // Stampa la colonna di destra
    tabellone[27 - i].stampaCasella();
    std::cout << std::endl;
  }
  // Ultima riga
  for (int i = 0; i < 8; i++) {
    tabellone[7 - i].stampaCasella();
  }
  std::cout << std::endl;
}

std::vector<Casella> Tabellone::getTabellone() const { return tabellone; }
