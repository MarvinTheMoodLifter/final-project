// Autore: Chellin Davide
// ------------------------------

#include "Dadi.h"
#include <cstdlib>
#include <time.h>

Dadi::Dadi() {
  numeroFacce = 6;
  conteggioTiri = 0;
}

Dadi::Dadi(int numeroFacceDado) {
  numeroFacce = numeroFacceDado;
  conteggioTiri = 0;
}

int Dadi::tiraDadi(int numeroDadi) {
  conteggioTiri = conteggioTiri + 1;
  sommaDadiLanciati = 0;
  for (int i = 0; i < numeroDadi; i++) {
    std::srand(time(0));
    int d = std::rand() % (numeroFacce - 1) + 1;
    sommaDadiLanciati = sommaDadiLanciati + d;
  }
  return sommaDadiLanciati;
}

int Dadi::getNumeroTiri() { return conteggioTiri; }
