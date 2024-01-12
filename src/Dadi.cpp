// Autore: Chellin Davide
// ------------------------------

#include "Dadi.h"
#include <random>

Dadi::Dadi() { numeroFacce = 6; }

Dadi::Dadi(int numeroFacceDado) { numeroFacce = numeroFacceDado; }

int Dadi::tiraDadi(int numeroDadi) {

  sommaDadiLanciati = 0;
  for (int i = 0; i < numeroDadi; i++) {

    std::random_device randomSeed;
    std::mt19937 gen{randomSeed()};
    std::uniform_int_distribution<int> dist{1, numeroFacce};
    int d = dist(gen);

    sommaDadiLanciati = sommaDadiLanciati + d;
  }

  return sommaDadiLanciati;
}
