// Autore: Perin Marco
// ------------------------------
#include "../include/Tabellone.h"
#include <iostream>

Tabellone::Tabellone() {
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

void Tabellone::inizializzaCaselleRandom() {
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

void Tabellone::muoviGiocatore(int giocatore, int posizione) {
  // Muove il giocatore di valoreDadi caselle
  // Se il giocatore supera la casella 27, riparte dalla casella di partenza e
  // finisce di muovere
  int valoreDadi = tiraDadi();
  int posizioneInizialeGiocatore = posizione;
  int posizioneFinaleGiocatore = posizioneInizialeGiocatore + valoreDadi;
  if (posizioneFinaleGiocatore > 27) {
    posizioneFinaleGiocatore -= 28;
  }
  tabellone[posizione].stampaCasella();
  tabellone[posizioneFinaleGiocatore].aggiungiGiocatore(
      std::to_string(giocatore));
  stampaTabellone();
  tabellone[posizione].rimuoviGiocatore(std::to_string(giocatore));
  stampaTabellone();
}

int Tabellone::tiraDadi() {
  // Genera un numero random tra 2 e 12
  std::random_device randomSeed;
  std::mt19937 gen(randomSeed());
  std::uniform_int_distribution<> distribuzione(2, 12);
  return distribuzione(gen);
}
