// Autore: Perin Marco
// ------------------------------
#ifndef TABELLONE_H
#define TABELLONE_H
#include "Casella.h"
#include "Dadi.h"
#include "Giocatore.h"
#include "GiocatoreNonUmano.h"
#include "GiocatoreUmano.h"
#include <vector>

// Classe tabellone
class Tabellone {
private:
  // giocatori
  std::vector<Casella> tabellone;
  Giocatore &g1;
  Giocatore &g2;
  Giocatore &g3;
  Giocatore &g4;

public:
  // Costruttore di default
  Tabellone(std::string tipoPartita, Giocatore &g1, Giocatore &g2,
            Giocatore &g3, Giocatore &g4);
  // Riempe il vettore con le caselle vuote
  void riempiTabellone();
  // Genera un numero random tra min e max
  void randomizzaVettore(std::vector<char> &v);
  // Riempie le caselle del tabellone in maniera randomica
  void riempiCaselleRandom();
  // Stampa il Tabellone vuoto
  void stampaTabellone();
  // Stampa il Tabellone con i giocatori
  void stampaTabelloneGiocatori() const;
  // Restituisce il vettore contente le caselle del Tabellone
  std::vector<Casella> getTabellone() const;
  // Sposta il giocatore
  void muoviGiocatore(Giocatore &giocatore, Giocatore &giocatore2,
                      Giocatore &giocatore3, Giocatore &giocatore4);
  std::string chiediGiocatore(std::string messaggio);
  bool acquistaImmobile(Giocatore &giocatore, int posizione);
  int tiraDadi();

  // Copy constructor per Gioco
  Tabellone(const Tabellone &t)
      : tabellone(t.tabellone), g1(t.g1), g2(t.g2), g3(t.g3), g4(t.g4) {}

  // Assignment copy per Gioco
  Tabellone &operator=(const Tabellone &t) {
    tabellone = t.tabellone;
    return *this;
  }

  // Overloading dell'operatore []
  Casella &operator[](int i) { return tabellone[i]; }
};

#endif // TABELLONE_H
