#ifndef SPOSTAMENTO_H
#define SPOSTAMENTO_H
#include "Giocatore.h"
#include "Tabellone.h"

class Spostamento {
private:
  Tabellone tabellone;
  bool passaDaVia = false;

public:
  Spostamento(Tabellone tabellone);
  void mossaGiocatore(Giocatore &giocatore);
  int tiroDadi();
};

#endif // SPOSTAMENTO_H
