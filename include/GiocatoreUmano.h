#include "Giocatore.h"

class GiocatoreUmano : private Giocatore {

public:
  GiocatoreUmano(int numGio);
  bool umano;
};
