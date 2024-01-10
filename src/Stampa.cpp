#include "Stampa.h"
#include <iostream>

Stampa::Stampa() {}

void Stampa::show(Tabellone &tab, Giocatore a, Giocatore b, Giocatore c,
                  Giocatore d) {

  tab.stampaTabelloneGiocatori();
  stampaPossedimenti(a, b, c, d);
  stampaFiorini(a, b, c, d);
}

void Stampa::stampaFiorini(Giocatore a, Giocatore b, Giocatore c, Giocatore d) {

  int giocatoreA = a.getFiorini();
  int giocatoreB = b.getFiorini();
  int giocatoreC = c.getFiorini();
  int giocatoreD = d.getFiorini();

  std::cout << a.getNumeroGiocatore() << "possiede" << giocatoreA << "/n"
            << b.getNumeroGiocatore()  << "possiede" << giocatoreB << "fiorini"
            << "/n" << c.getNumeroGiocatore() << "possiede" << giocatoreC
            << "fiorini"
            << "/n" << d.getNumeroGiocatore() << "possiede" << giocatoreD
            << "fiorini"
            << "/n";
}

void Stampa::stampaPossedimenti(Giocatore a, Giocatore b, Giocatore c,
                                Giocatore d) {}
