// Autore: Perin Marco
// ------------------------------
#ifndef TABELLONE_H
#define TABELLONE_H
#include "Casella.h"
#include <vector>

// Classe tabellone
class Tabellone {
private:
  std::vector<Casella> tabellone;

public:
  // Costruttore di default
  Tabellone();
  // Inizializza il tabellone in maniera randomica
  void inizializzaTabelloneRandom();
  // Stampa il Tabellone vuoto
  void stampaTabellone();
  // Stampa il Tabellone con i giocatori
  void stampaTabelloneGiocatori();

  // Distruttore
  ~Tabellone();
};

#endif // TABELLONE_H
