// Autore: Perin Marco
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
  std::string tipoPartita;
  if (argc != 2) {
    std::cout << "Tipo di partita non valido" << std::endl;
    std::cout << "Uso: ./main [human|computer]\n" << std::endl;
    return 0;
  }
  tipoPartita = argv[1];
  if (tipoPartita == "human" | tipoPartita == "computer") {
    std::cout << "Partita " << tipoPartita << std::endl;
  } else {
    std::cout << "Tipo di partita non valido" << std::endl;
    std::cout << "Uso: ./main [human|computer]\n" << std::endl;
    return 0;
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
