// Autore: Perin Marco
// ------------------------------
#ifndef TABELLONE_H
#define TABELLONE_H
#include "Casella.h"
#include <algorithm>
#include <random>
#include <vector>

// Classe tabellone
class Tabellone {
private:
  std::vector<Casella> tabellone;

public:
  // Costruttore di default
  Tabellone();
  // Genera un numero random tra min e max
  std::vector<std::string> randomizzaVettore(std::vector<std::string> v) const;
  // Riempie le caselle del tabellone in maniera randomica
  void inzializzaCaselleRandom();
  // Stampa il Tabellone vuoto
  void stampaTabellone();
  // Stampa il Tabellone con i giocatori
  void stampaTabelloneGiocatori();

  // Distruttore
  ~Tabellone();
};

#endif // TABELLONE_H
