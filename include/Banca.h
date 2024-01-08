#ifndef BANCA_H
#define BANCA_H
#include "Giocatore.h"

class Banca {
private:
  Giocatore giocatore1;
  Giocatore giocatore2;
  Giocatore giocatore3;
  Giocatore giocatore4;

public:
  Banca(Giocatore g1, Giocatore g2, Giocatore g3, Giocatore g4);
};

#endif // !BANCA_H
