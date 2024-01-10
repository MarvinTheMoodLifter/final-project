#import "Giocatore.h"

class Gioco{

    Gioco(flag da argv gicoatore umani e non);
    Gioco(flag da argv giocatore non umani);

    
    turnoGiocatore();    
    void gioca();

    std::vector<int> ordineGioco();

    //li definisco già come giocatore umano e non umano


    Giocatore cp1;
    Giocatore cp2;
    Giocatore cp3;
    Giocatore cp4;

   Giocatore[] giocatoriInPartita;

   Tabellone principale; 

   Giocatore[] aggiungiGiocatori();

   bool ultimoGiocatore();
   int comparaFiorini();
   bool umanoInGioco();
   void finePartita();


}

