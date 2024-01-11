#ifndef GIOCATOREUMANO_H
#define GIOCATOREUMANO_H

#include "Giocatore.h"

class GiocatoreUmano : public Giocatore {
private:
  bool umano;

public:
  GiocatoreUmano(int numGio);
  bool isUmano() const override { return true; }
};

#endif // GIOCATOREUMANO_H
