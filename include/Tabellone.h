// Autore: Perin Marco
// ------------------------------
#ifndef TABELLONE_H
#define TABELLONE_H

#include "Casella.h"
#include "Dadi.h"
#include "Giocatore.h"
#include <vector>

// Classe tabellone
class Tabellone {
private:
  // giocatori
  Giocatore giocatore1;
  Giocatore giocatore2;
  Giocatore giocatore3;
  Giocatore giocatore4;
  
  std::vector<Casella> tabellone;

public:
  // Costruttore di default
  Tabellone(std::string tipoPartita);
  // Riempe il vettore con le caselle vuote
  void riempiTabellone();
  // Genera un numero random tra min e max
  void randomizzaVettore(std::vector<std::string> &v);
  // Riempie le caselle del tabellone in maniera randomica
  void riempiCaselleRandom();
  // Stampa il Tabellone vuoto
  void stampaTabellone();
  // Stampa il Tabellone con i giocatori
  void stampaTabelloneGiocatori() const;
  // Restituisce il vettore contente le caselle del Tabellone
  std::vector<Casella> getTabellone() const;
  // Sposta il giocatore
  void muoviGiocatore(Giocatore giocatore);
  int tiraDadi();

  // Overloading dell'operatore []
  Casella &operator[](int i) { return tabellone[i]; }
};

#endif // TABELLONE_H
