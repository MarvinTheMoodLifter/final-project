#include "Gioco.h"
#include <algorithm> 

Gioco::Gioco(std::string //controlla se humano o computer ){

  std::vector<int> ordine = ordineGioco();computer

  GiocatoreUmano(ordine.pop_back());
  GiocatoreNonUmano(ordine.pop_back());
  GiocatoreNonUmano(ordine.pop_back());
  GiocatoreNonUmano(ordine.pop_back());

}

Gioco::Gioco(){

  std::vector<int> ordine = ordineGioco();

  GiocatoreNonUmano(ordine.pop_back());
  GiocatoreNonUmano(ordine.pop_back());
  GiocatoreNonUmano(ordine.pop_back());
  GiocatoreNonUmano(ordine.pop_back());

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

gioca(argsv da terminale){

//4 casi con 4 posizioni in cui fgiocatore umano può partecipare in base a come viene dato al costruttore oppure trova modo diverso


// oppure creo solo metodfo turnoGiocatore con allinterno if else in base a flag del giocatore
turnoGiocatoreUmano
turnoGiocatoreNonUmano
turnoGiocatoreNonUmano
turnoGiocatoreNonUmano

oppure


turnoGiocatoreNonUmano
turnoGiocatoreUmano
turnoGiocatoreNonUmano
turnoGiocatoreNonUmano

oppure

turnoGiocatoreNonUmano
turnoGiocatoreNonUmano
turnoGiocatoreUmano
turnoGiocatoreNonUmano

turnoGiocatoreUmano
turnoGiocatoreNonUmano
turnoGiocatoreNonUmano
turnoGiocatoreNonUmano








}

gioca(argsv da terminale){

//while con numero totale turno non umano diviso 4 poi annuncia fine partita

turnoGiocatoreNonUmano();


}

std::vector<int> ordineGioco(){

int a Dadi.tiraDadi();
int b Dadi.tiraDadi();
int c Dadi.tiraDadi();
int d Dadi.tiraDadi();

//riordino i numeri e li associo 
int[] ordineGiocatori = [a,b,c,d];

std::vector<int> giocatoriRiordinati(ordineGiocatori, ordineGiocatori+4);
std::sort (giocatoriRiordinati.begin(), giocatoriRiordinati.begin()+4);

return giocatoriRiordinati;








}