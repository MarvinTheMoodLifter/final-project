// Autore: Chellin Davide
// ------------------------------
#ifndef GIOCATORE_H
#define GIOCATORE_H
#include "Casella.h"

class Posizione;

// Classe giocatore
class Giocatore {
private:
  int numeroGiocatore;
  int fiorini;
  int posizione;
  bool inGioco;

public:
  Giocatore(int numeroGiocatore);
  int getPosizione() const;
  void setPosizione(int posizione);
  int getNumeroGiocatore();
};

#endif // GIOCATORE_H
