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
<<<<<<< HEAD
  int getPosizione();
  int getNumeroGiocatore();
  int getFiorini();
=======
  int getPosizione() const { return posizione; };
  int getNumeroGiocatore() const { return numeroGiocatore; };
  int getFiorini() const { return fiorini; };
  void setFiorini(int fiorini);
>>>>>>> main
  void setPosizione(int posizione);
  void mossa(Tabellone &tabellone);
  // Copy constructor
  Giocatore(const Giocatore &g);
  // Assegnatore di copia (per l'uso in Tabellone)
  Giocatore &operator=(const Giocatore &g);
};

#endif // GIOCATORE_H
