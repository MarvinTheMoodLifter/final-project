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
