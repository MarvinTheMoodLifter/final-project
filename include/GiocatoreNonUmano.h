// Autore: Chellin Davide
// ------------------------------
#ifndef GIOCATORENONUMANO_H
#define GIOCATORENONUMANO_H
#include "Giocatore.h"

class GiocatoreNonUmano : public Giocatore {
private:
  bool umano = false;

public:
  // Costruttore
  GiocatoreNonUmano(int numGio);
  bool isUmano() const override { return false; }
  // override distruttore virtuale
  ~GiocatoreNonUmano() override = default;
};

#endif // GIOCATORENONUMANO_H
