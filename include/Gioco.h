#include "Giocatore.h"
#include <algorithm>
#include <vector>

class Gioco {

  Gioco(int i = 0);
  Gioco(int i = 1);

  void turnoGiocatore();
  void gioca();

  std::vector<int> ordineGioco();

  // li definisco già come giocatore umano e non umano

  Giocatore cp1;
  Giocatore cp2;
  Giocatore cp3;
  Giocatore cp4;

  Giocatore giocatoriInPartita[];

  Tabellone principale();

  Giocatore[] aggiungiGiocatori();

  bool ultimoGiocatore();
  int comparaFiorini();
  bool umanoInGioco();
  void finePartita();
};
