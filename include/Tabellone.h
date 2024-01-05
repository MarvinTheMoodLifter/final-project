// Autore: Perin Marco
// ------------------------------
#ifndef TABELLONE_H
#define TABELLONE_H
#include "Casella.h"
#include "Spostamento.h"
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
  void randomizzaVettore(std::vector<std::string> &v);
  // Riempie le caselle del tabellone in maniera randomica
  void inizializzaCaselleRandom();
  // Stampa il Tabellone vuoto
  void stampaTabellone();
  // Stampa il Tabellone con i giocatori
  void stampaTabelloneGiocatori() const;
  // Restituisce il vettore contente le caselle del Tabellone
  std::vector<Casella> getTabellone() const;
  // Sposta il giocatore
  void muoviGiocatore(int giocatore, int posizione);
  int tiraDadi();

  // Overloading dell'operatore []
  Casella &operator[](int i) { return tabellone[i]; }
};

#endif // TABELLONE_H
