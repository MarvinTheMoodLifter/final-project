#include "Giocatore.h"

Giocatore::Giocatore() {}
Giocatore::Giocatore(int numGio) {

  numeroGiocatore = numGio;
  fiorini = 100;
  inGioco = true;
  posizione = 0;

  //  void Giocatore::setPosizionePartenza(Tabellone & tabellone) {
  //    tabellone[0].aggiungiGiocatore(std::to_string(numeroGiocatore));
  //  }
}

void Giocatore::mossa(Tabellone &tabellone) {
  tabellone.muoviGiocatore(numeroGiocatore, posizione);
}
