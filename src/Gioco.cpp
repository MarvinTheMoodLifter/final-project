#include "Gioco.h"

Gioco::Gioco(){

    aggiungiGiocatori(Giocarore[] giocatori);



}

Gioco::Gioco(){


    aggiungiGiocatori(GiocaroreNonUmano[] giocatori);




}

void Gioco::turnoGiocatoreUmano(GiocatoreUmano umano) {
  Giocatore giocatoreCorrente = umano;
  std::cout << "È il turno di " << umano.getNumeroGiocatore() << "/n"
            << "digita s per proseguire, altrimenti digita show per mostrare "
               "lo stato attuale della partita"
            << "/n";
  std::string i;
  std::string show = "show";
  std::string s = "s";
  std::cin >> i;
  // è case sensitive
  if (i.compare(show) == 0) {
    Stampa.show(tab, a, b, c, d);
  } else if (i.compare(s) == 0) {
    tabellone.muoviGiocatore(giocatoreCorrente);
  } else {
    std::cout << "digita un comando valido"
              << "/n";
    turnoGiocatoreUmano(giocatoreCorrente);
  }
}

void Gioco::turnoGiocatoreNonUmano(GiocatoreNonUmano nonUmano) {
  Giocatore giocatoreCorrente = nonUmano;
  std::cout << "È il turno di " << nonUmano.getNumeroGiocatore() << "/n";
  if (a.umano || b.umano || c.umano || d.umano = !0) {
    numeroTurniGiocati++;
    if (numeroTurniGiocati / 3 == numeroTurni) {
      std::cout << "Fine partita"
                << "/n";
      comparaFiorini();
      // l'ho scritto su turno, adra riscritto su banchiere?
    }
  } else {
    tabellone.muoviGiocatore(giocatoreCorrente);
  }
}

