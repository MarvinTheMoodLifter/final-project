// Autore: Chellin Davide
// ------------------------------

#include "Dadi.h"
#include <random>

// Costruttore di default
Dadi::Dadi() { numeroFacce = 6; }
// Costruttore con parametro numero di facce
Dadi::Dadi(int numeroFacceDado) { numeroFacce = numeroFacceDado; }

int Dadi::tiraDadi(int numeroDadi) {
  sommaDadiLanciati = 0;
  for (int i = 0; i < numeroDadi; i++) {
    // Generazione numero casuale
    std::random_device randomSeed;
    // Generatore di numeri casuali
    std::mt19937 gen{randomSeed()};
    // Distribuzione uniforme
    std::uniform_int_distribution<int> dist{1, numeroFacce};
    int d = dist(gen);
    // Somma dei dadi lanciati
    sommaDadiLanciati = sommaDadiLanciati + d;
  }
  return sommaDadiLanciati;
}
