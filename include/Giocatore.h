// Autore: Chellin Davide
// ------------------------------

#ifndef GIOCATORE_H
#define GIOCATORE_H
#include "Casella.h"
#include "Tabellone.h"

//class posizione

class Giocatore {
private:
  const int numeroGiocatore;
  int fiorini;
  int posizione;
  bool inGioco;

public:
  Giocatore(int numeroGiocatore);
  void setPosizionePartenza(Tabellone &tabellone); //non convinto
  int getPosizione() const;
  void mossa(Tabellone &tabellone);
  int getNumeroGiocatore();
};

#endif // GIOCATORE_H
