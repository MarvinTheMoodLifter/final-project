// Autore: Perin Marco
// ------------------------------
#ifndef TABELLONE_H
#define TABELLONE_H
#include "Casella.h"
#include "Dadi.h"
#include "Giocatore.h"
#include "GiocatoreNonUmano.h"
#include "GiocatoreUmano.h"
#include <algorithm>
#include <fstream>
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
  // Costruttore
  Tabellone(std::string tipoPartita, Giocatore *g1, Giocatore *g2,
            Giocatore *g3, Giocatore *g4);

  // Costruzione Tabellone
  void riempiTabellone();
  void randomizzaVettore(std::vector<char> &v);
  void riempiCaselleRandom();

  // Stampa
  void stampaTabellone();
  void stampaFiorini() const;
  void stampaPossedimenti() const;
  void stampaLog(std::string messaggio) const;
  std::string chiediGiocatore(std::string messaggio);

  // Getters
  std::vector<Casella *> getTabellone() const;

  // Setters
  void aggiungiProprietario(Giocatore *giocatore, Casella *casella);
  void assegnaProprietario(Giocatore *giocatore, int posizione);
  void rimuoviGiocatore(Giocatore *giocatore);

  // Sposta il giocatore
  void muoviGiocatore(Giocatore *giocatore, Giocatore *giocatore2,
                      Giocatore *giocatore3, Giocatore *giocatore4);

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
