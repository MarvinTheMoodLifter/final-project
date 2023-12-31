// Autore: Chellin Davide
// ------------------------------
#ifndef GIOCATORE_H
#define GIOCATORE_H
#include "Casella.h"
#include "Tabellone.h"

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
  void setPosizionePartenza(Tabellone &tabellone);
  int getPosizione() const;
  void mossa(Tabellone &tabellone);
  int getNumeroGiocatore();
};

#endif // GIOCATORE_H
