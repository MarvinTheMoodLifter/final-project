#ifndef TURNO_H
#define TURNO_H
#include "Tabellone.h"

class Stampa;

class Turno {
public:
  Turno(Tabellone &tab);
  Turno(Tabellone &tab, int n);

  void turnoGiocatoreUmano(Giocatore umano);
  void turnoGiocatoreNonUmano(Giocatore nonUmano);

private:
  int numeroTurniGiocati;
  int numeroTurni;
  Tabellone tabellone;
};

#endif // TURNO_H
