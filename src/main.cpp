// Autori: Chellin Davide, Perin Marco
// ------------------------------
#include "Casella.h"
#include "Dadi.h"
#include "Giocatore.h"
#include "Gioco.h"
#include "Tabellone.h"
#include <iostream>
#include <string>

void testGioco(std::string tipoPartita);

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

  enum tipo { human = 0, computer = 1 };
  testGioco(tipoPartita);

  return 0;
}

void testGioco(std::string tipoPartita) {
  Gioco g(tipoPartita);
  // Test per il metodo gioca
  g.gioca();
}
