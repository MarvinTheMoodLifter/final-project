#include "Giocatore.h"

class GiocatoreNonUmano : public Giocatore {
private:
  bool umano;

public:
  GiocatoreNonUmano(int numGio);
  char scelte();
  bool isUmano() const override { return false; }
  // override distruttore virtuale
  ~GiocatoreNonUmano() override = default;
};

int generatore();
