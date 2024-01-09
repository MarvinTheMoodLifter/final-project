// Autore: Chellin Davide
// ------------------------------

#include "Dadi.h"
#include <random>



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

    std::random_device randomSeed;
    std::mt19937 gen{randomSeed()};
    std::uniform_int_distribution<int> dist{1,numeroFacce};
    int d= dist(gen);

    sommaDadiLanciati = sommaDadiLanciati + d;

  }

  return sommaDadiLanciati;
}

int Dadi::getNumeroTiri() { return conteggioTiri; }
