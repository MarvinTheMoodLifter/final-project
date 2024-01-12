// Autori: Chellin Davide, Perin Marco
// ------------------------------
#include "Casella.h"
#include "Dadi.h"
#include "Giocatore.h"
#include "Gioco.h"
#include "Tabellone.h"
#include <iostream>
#include <string>

void testCaselle() {
  Casella test('A', 1);
  Casella test2('B', 1);
  test.stampaCasella();
  test2.stampaCasella();
}

void testSpostamento(Giocatore &giocatore, Tabellone &tabellone) {}

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

  // testCaselle();

  Tabellone tabellone(tipoPartita);
  std::vector<Casella> tabelloneVector = tabellone.getTabellone();
  Giocatore giocatore1(1);
  tabellone.stampaTabellone();
  std::cout << giocatore1.getPosizione() << std::endl;
  tabellone.stampaTabellone();
  Gioco gioco(tipoPartita);

  return 0;
}
