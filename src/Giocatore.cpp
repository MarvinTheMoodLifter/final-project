#include "../include/Giocatore.h"

Giocatore::Giocatore(int numeroGiocatore)
    : numeroGiocatore(numeroGiocatore), fiorini(100), inGioco(true),
      posizione(21){};

void Giocatore::setPosizione(int p) { posizione = p; }

int Giocatore::getPosizione() const { return posizione; }

int Giocatore::getNumeroGiocatore() { return numeroGiocatore; }
