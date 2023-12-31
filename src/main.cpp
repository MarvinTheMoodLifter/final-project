// Autori: Chellin Davide, Perin Marco
// ------------------------------
#include "../include/Casella.h"
#include "../include/Giocatore.h"
#include "../include/Tabellone.h"
#include <iostream>
#include <string>

void testCaselle() {
  Casella test('A', 1);
  Casella test2('B', 1);
  test.setValore("^");
  test2.setValore("^2");
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

  // testCaselle();

  Tabellone tabellone;
  tabellone.inizializzaCaselleRandom();
  std::vector<Casella> tabelloneVector = tabellone.getTabellone();
  Giocatore giocatore1(1);
  tabellone.stampaTabellone();
  giocatore1.setPosizionePartenza(tabellone);
  tabellone.stampaTabellone();
  giocatore1.mossa(tabellone);
  std::cout << giocatore1.getPosizione() << std::endl;
  tabellone.stampaTabellone();

  return 0;
}
