#include "Giocatore.h"

Giocatore::Giocatore() {}
Giocatore::Giocatore(int numGio) {
  numeroGiocatore = numGio;
  fiorini = 100;
  inGioco = true;
  posizione = 0;
}

void Giocatore::setFiorini(int n) { fiorini = n; }
