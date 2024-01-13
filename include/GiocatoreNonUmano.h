#ifndef GIOCATORENONUMANO_H
#define GIOCATORENONUMANO_H
#include "Giocatore.h"

class GiocatoreNonUmano : public Giocatore {
private:
  bool umano = false;

public:
  GiocatoreNonUmano(int numGio);
  char scelte();
  bool isUmano() const override { return false; }
  // override distruttore virtuale
  ~GiocatoreNonUmano() override = default;
};

int generatore();

#endif // GIOCATORENONUMANO_H
