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
  std::vector<Casella *> tabellone;
  Giocatore *cp1;
  Giocatore *cp2;
  Giocatore *cp3;
  Giocatore *cp4;
  std::vector<Casella *> proprietàcp1;
  std::vector<Casella *> proprietàcp2;
  std::vector<Casella *> proprietàcp3;
  std::vector<Casella *> proprietàcp4;

public:
  // Costruttore di default
  Tabellone(std::string tipoPartita, Giocatore *g1, Giocatore *g2,
            Giocatore *g3, Giocatore *g4);
  // Riempe il vettore con le caselle vuote
  void riempiTabellone();
  // Genera un numero random tra min e max
  void randomizzaVettore(std::vector<char> &v);
  // Riempie le caselle del tabellone in maniera randomica
  void riempiCaselleRandom();
  // Stampa il tabellone
  void stampaTabellone();
  // Stampa i fiorini dei giocatori
  void stampaFiorini() const;
  // Stampa i possedimenti dei giocatori
  void stampaPossedimenti() const;
  // Restituisce il vettore contente le caselle del Tabellone
  std::vector<Casella *> getTabellone() const;
  // Sposta il giocatore
  void muoviGiocatore(Giocatore *giocatore, Giocatore *giocatore2,
                      Giocatore *giocatore3, Giocatore *giocatore4);
  void aggiungiProprietario(Giocatore *giocatore, Casella *casella);
  std::string chiediGiocatore(std::string messaggio);
  bool acquistaImmobile(Giocatore *giocatore, int posizione);
  int tiraDadi();

  void assegnaProprietario(Giocatore *giocatore, int posizione);
  void rimuoviGiocatore(Giocatore *giocatore);

  // Copy constructor per Gioco
  Tabellone(const Tabellone *t)
      : tabellone(t->tabellone), cp1(t->cp1), cp2(t->cp2), cp3(t->cp3),
        cp4(t->cp4) {}

  // Assignment copy per Gioco
  Tabellone &operator=(const Tabellone &t) {
    tabellone = t.tabellone;
    return *this;
  }

  // Overloading dell'operatore []
  Casella &operator[](int i) { return *tabellone[i]; }

  // Distruttore
  ~Tabellone();
};

#endif // TABELLONE_H
