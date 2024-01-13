#include "Tabellone.h"
#include <iostream>

class Gioco {
public:
  Gioco(std::string tipoPartita);
  void turnoGiocatore(Giocatore &p);
  void gioca();
  void chiediGiocatore(std::string messaggio);
  void ordineGioco();
  void stampaTabellone();
  Giocatore *aggiungiGiocatori();
  bool ultimoGiocatore();
  std::vector<int> comparaFiorini();
  bool umanoInGioco();
  void finePartita();
  void stampaGiocatori();
  ~Gioco();

private:
  std::vector<Giocatore *> giocatoriInPartita;
  std::vector<Giocatore *> ordineGiocatoriPartita;
  std::string tipoGioco;
  Giocatore *cp1;
  Giocatore *cp2;
  Giocatore *cp3;
  Giocatore *cp4;
  Tabellone *principale;
};
