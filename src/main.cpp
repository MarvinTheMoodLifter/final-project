// Autori: Perin Marco, Chellin Davide
// ------------------------------
#include "../include/Tabellone.h"
#include <string>

int main(int argc, char **argv) {
  // Se argc == computer allora la partita è 4 computer
  // Se argc == human allora la partita è 1 giocatore e 3 computer
  // Inizializzo il tipo di partita di default a computer
  std::string tipoPartita = "computer";
  // Se argc == 2 allora leggo il tipo di partita da argv[1]
  tipoPartita = argv[1];

  return 0;
}
