// Autore: Chellin Davide
// ------------------------------
#ifndef GIOCATOREUMANO_H
#define GIOCATOREUMANO_H

#include "Giocatore.h"

class GiocatoreUmano : public Giocatore {
private:
  bool umano = true;

public:
  // Costruttore
  GiocatoreUmano(int numGio);
  // override metodo virtuale
  bool isUmano() const override { return true; }
  // override distruttore virtuale
  ~GiocatoreUmano() override = default;
};

#endif // GIOCATOREUMANO_H
