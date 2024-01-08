#include "Giocatore.h"

Giocatore::Giocatore(int numeroGiocatore) : numeroGiocatore(numeroGiocatore) {
  fiorini = 100;
  inGioco = true;
  posizione = 0;
}
void Giocatore::setPosizione(int p) { posizione = p; }
void Giocatore::mossa(Tabellone &tabellone) {
  tabellone.muoviGiocatore(numeroGiocatore, posizione);
}

// Copy constructor
Giocatore::Giocatore(const Giocatore &g) {
  numeroGiocatore = g.getNumeroGiocatore();
  fiorini = g.getFiorini();
  posizione = g.getPosizione();
}

// Copy assignment (per l'uso in Tabellone)
Giocatore &Giocatore::operator=(const Giocatore &g) {
  numeroGiocatore = g.getNumeroGiocatore();
  fiorini = g.getFiorini();
  posizione = g.getPosizione();
  return *this;
}
