// Autore: Chellin Davide
// ------------------------------
#include "Giocatore.h"

// Costruttore di default
Giocatore::Giocatore() {}
// Costruttore con parametri
Giocatore::Giocatore(int numGio, bool inGioco, int fiorini, int posizione)
    : numeroGiocatore(numGio), inGioco(inGioco), fiorini(fiorini),
      posizione(posizione) {}

// Getters
int Giocatore::getPosizione() const { return posizione; };
int Giocatore::getNumeroGiocatore() const { return numeroGiocatore; };
int Giocatore::getFiorini() const { return fiorini; };
// Setters
void Giocatore::setPosizione(int p) { posizione = p; };
void Giocatore::setFiorini(int valore) { fiorini = valore; }
void Giocatore::setInGioco(bool v) { inGioco = v; }

// Metodo virtuale isUmano
bool Giocatore::isUmano() const { return umano; }

// Copy constructor
Giocatore::Giocatore(const Giocatore &g) {
  numeroGiocatore = g.numeroGiocatore;
  fiorini = g.fiorini;
  posizione = g.posizione;
  inGioco = g.inGioco;
  umano = g.umano;
}

// Assegnatore di copia (per l'uso in Tabellone)
Giocatore &Giocatore::operator=(const Giocatore &g) {
  numeroGiocatore = g.numeroGiocatore;
  fiorini = g.fiorini;
  posizione = g.posizione;
  inGioco = g.inGioco;
  umano = g.umano;
  return *this;
}
