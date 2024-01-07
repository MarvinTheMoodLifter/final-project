#ifndef STAMPA_H
#define STAMPA_H

#include "Tabellone.h"

class Stampa {

  Stampa();
  void show(Tabellone &tab, Giocatore a, Giocatore b, Giocatore c, Giocatore d);
  void stampaTabelloneGiocatori();
  void stampaFiorini(Giocatore a, Giocatore b, Giocatore c, Giocatore d);
  void stampaPossedimenti(Giocatore a, Giocatore b, Giocatore c, Giocatore d);
};

#endif // STAMPA_H
