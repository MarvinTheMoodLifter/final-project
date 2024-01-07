#ifndef TURNO_H
#define TURNO_H
#include "Tabellone.h"

class Stampa;

class Turno {
public:
  Turno();
  Turno(int n);

  void turnoGiocatoreUmano(Tabellone &tab, Giocatore umano);
  void turnoGiocatoreNonUmano(Tabellone &tab, Giocatore nonUmano);

private:
  int numeroTurniGiocati;
  int numeroTurni;
};

#endif // TURNO_H
