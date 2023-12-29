// Autori: Perin Marco, Chellin Davide
// ------------------------------
#include "../include/Casella.h"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  // Se argc == computer allora la partita è 4 computer
  // Se argc == human allora la partita è 1 giocatore e 3 computer
  // Inizializzo il tipo di partita di default a computer
  std::string tipoPartita = "computer";
  // Se argc == 2 allora leggo il tipo di partita da argv[1]
  if (argc == 2) {
    tipoPartita = argv[1];
  }
  if (tipoPartita == "human" | tipoPartita == "computer") {
    std::cout << "Partita " << tipoPartita << std::endl;
  }

  Casella test('A', 1, "^");
  Casella test2('B', 1, "^2");
  test.stampaCasella();
  test2.stampaCasella();

  return 0;
}
