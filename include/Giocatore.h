// Autore: Chellin Davide
// ------------------------------
#ifndef GIOCATORE_H
#define GIOCATORE_H
#include "Tabellone.h"

class Giocatore {
private:
  int numeroGiocatore;
  int fiorini;
  int posizione;
  bool inGioco;

public:
  Giocatore();
  Giocatore(int numeroGiocatore);
  int getPosizione();
  int getNumeroGiocatore();
  int getFiorini();
  void setFiorini(int fiorini);
  void setPosizione(int posizione);
  // void mossa(Tabellone &tabellone);
  // Copy constructor
  Giocatore(const Giocatore &g);
  // Assegnatore di copia (per l'uso in Tabellone)
  Giocatore &operator=(const Giocatore &g);
};

#endif // GIOCATORE_H
