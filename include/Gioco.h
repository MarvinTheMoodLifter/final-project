#include "Tabellone.h"
#include <iostream>

class Gioco {
public:
  Gioco(std::string tipoPartita);
  void turnoGiocatore(Giocatore &p);
  void gioca();
  void chiediGiocatore(std::string messaggio);
  void ordineGioco();
  Giocatore *aggiungiGiocatori();
  bool ultimoGiocatore();
  std::vector<int> comparaFiorini();
  bool umanoInGioco();
  void finePartita();

private:
  std::vector<Giocatore *> giocatoriInPartita;
  std::vector<Giocatore *> ordineGiocatoriPartita;
  std::string tipoGioco;
  Giocatore cp1;
  Giocatore cp2;
  Giocatore cp3;
  Giocatore cp4;
  Tabellone principale;
};
