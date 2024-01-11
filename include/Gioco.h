#include "Giocatore.h"
#include <algorithm>
#include <vector>

class Gioco {

  Gioco(std::string tipoPartita);
  
  void turnoGiocatore(Giocatore &p);
  void gioca();

  std::vector<int> ordineGioco();

  // li definisco già come giocatore umano e non umano

  Giocatore cp1;
  Giocatore cp2;
  Giocatore cp3;
  Giocatore cp4;

  

  Tabellone principale();

  Giocatore* aggiungiGiocatori();
  std::string tipoGioco;

  bool ultimoGiocatore();
  int comparaFiorini();
  bool umanoInGioco();
  void finePartita();
  Giocatore giocatoriInPartita[];
 
};
