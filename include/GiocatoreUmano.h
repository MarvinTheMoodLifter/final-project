#include "Giocatore.h"

class GiocatoreUmano : private Giocatore {
private:
public:
  GiocatoreUmano(int numGio);
  bool umano;
};
