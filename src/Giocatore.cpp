#include "Giocatore.h"

Giocatore::Giocatore() {}
Giocatore::Giocatore(int numGio) {

  numeroGiocatore = numGio;
  fiorini = 100;
  inGioco = true;
  posizione = 0;

  //  void Giocatore::setPosizionePartenza(Tabellone & tabellone) {
  //    tabellone[0].aggiungiGiocatore(std::to_string(numeroGiocatore));
}

int Giocatore::getPosizione() { return posizione; };
int Giocatore::getNumeroGiocatore() const { return numeroGiocatore; };
int Giocatore::getFiorini() const { return fiorini; };
void Giocatore::setPosizione(int posizione){};
// void mossa(Tabellone &tabellone);
// Copy constructor
// Giocatore::Giocatore(const Giocatore &g);
// Assegnatore di copia (per l'uso in Tabellone)
// Giocatore::Giocatore &operator=(const Giocatore &g);
