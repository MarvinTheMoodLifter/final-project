#include "Gioco.h"
#include <algorithm> 

Gioco::Gioco(std::string controlla se humano o computer ){
  
  principale(tipo di partita); //forse necessario assignment copy

  std::vector<int> ordine = ordineGioco();
  cp1 = GiocatoreUmano(ordine.pop_back());
  cp1 = GiocatoreNonUmano(ordine.pop_back());
  cp2 =GiocatoreNonUmano(ordine.pop_back());
  cp4 =GiocatoreNonUmano(ordine.pop_back());

  giocatoriInPartita = aggiungiGiocatori(cp1,cp2,cp3,cp4); 

}

Gioco::Gioco(tipo di partita){

   principale(tipo di partita); 

  std::vector<int> ordine = ordineGioco();

  GiocatoreNonUmano(ordine.pop_back());
  GiocatoreNonUmano(ordine.pop_back());
  GiocatoreNonUmano(ordine.pop_back());
  GiocatoreNonUmano(ordine.pop_back());

  giocatoriInPartita = aggiungiGiocatori(cp1,cp2,cp3,cp4);

}

turnoGiocatore(Giocatore p){

if(!ultimoGiocatore()){

if(p.umano)


  if(p.inGioco){

  std::cout << "È il turno di " << p.getNumeroGiocatore() << "/n"
            << "digita s per proseguire, altrimenti digita show per mostrare "
               "lo stato attuale della partita"
            << "/n";
  std::string i;
  std::string show = "show";
  std::string s = "s";
  std::cin >> i;
  // è case sensitive
  if (i.compare(show) == 0) {
    //Stampa.show(tab, a, b, c, d);
    
  } else if (i.compare(s) == 0) {
    principale.muoviGiocatore(p);
  } else {
    std::cout << "digita un comando valido"
              << "/n";
    turnoGiocatore(p);
  }

  }

  else{

    return;

  }




else{

  if(p.inGioco){
std::cout << "È il turno di " << p.getNumeroGiocatore() << "/n";
  
    principale.muoviGiocatore(p);
    }

  else{

    return;
    
    }
  }

}

else(ultimoGiocatore()){

finePartita();

}




}




gioca(flag tipop giooco){

//4 casi con 4 posizioni in cui fgiocatore umano può partecipare in base a come viene dato al costruttore oppure trova modo diverso


// oppure creo solo metodfo turnoGiocatore con allinterno if else in base a flag del giocatore


while(umanoInGioco()){
for(int i=0, i< 4, i++ ){
  
  turnoGiocatore(giocatoriInPartita[i]);

}

}


if(cp1.inGioco &&  )

for(int i=0, i<20, i++){

  for(int i=0, i< 4, i++ ){
  
  turnoGiocatore(giocatoriInPartita[i]);

  }

}



}





gioca(flag su Gioco){

for(int i=0, i<20, i++){

  for(int i=0, i< 4, i++ ){
  
  turnoGiocatore(giocatoriInPartita[i]);

  }

}

finePartita();

 
}


void finePartita(){

int vincitore;

vincitore=comparaFiorini();

std::cout << "Fine partita, il vincitore è il giocatore numero: "<< vincitore << "/n";
 
//compara fiorini con il metodo
//annuncia vincitore
//termina programma
//stampa su file terminale
//stampa finale


  
}


bool umanoInGioco(){

  for(int i=0, i< 4, i++ ){
  
  
  if (giocatoriInPartita[i].umano){

    if(giocatoriInPartita[i].inGioco){

      return true;

    }

    else{

      return false;

    }

  }

 }
}



int comparaFiorini(){


    int fp1 = giocatoriInPartita[0].getFiorini();
    int fp2 = giocatoriInPartita[1].getFiorini();
    int fp3 = giocatoriInPartita[2].getFiorini();
    int fp4 = giocatoriInPartita[3].getFiorini();
    
    if (fp1 >= fp2 && fp1 >= fp3 && fp1 >= fp4){ 
        return 0; 
    }
    
    else if (fp2 >= fp1 && fp2 >= fp3 && fp2 >= fp4) {
        return 1; 
    }

    else if (fp3 >= fp1 && fp3 >= fp2 && fp3 >= fp4){
        return 2; 
    }
    else{
        return 3; 
    }


  }

std::vector<int> ordineGioco(){

int a Dadi.tiraDadi();
int b Dadi.tiraDadi();
int c Dadi.tiraDadi();
int d Dadi.tiraDadi();

int[] ordineGiocatori = [a,b,c,d];
std::vector<int> ordinePartita(ordineGiocatori,ordineGiocatori+4);

return ordinePartita;

}

Giocatore[] aggiungiGiocatori(Giocatore p1, Giocatore p2, Giocatore p3, Giocatore p4){


Giocatore[4] arrayOrdinatoGiocatore;

arrayOrdinatoGiocatore[p1.getNumeroGiocatore-1] = p1;
arrayOrdinatoGiocatore[p2.getNumeroGiocatore-1] = p2;
arrayOrdinatoGiocatore[p3.getNumeroGiocatore-1] = p3;
arrayOrdinatoGiocatore[p4.getNumeroGiocatore-1] = p4;

return arrayOrdinatoGiocatore;

}



bool ultimoGiocatore(){

if(cp1.inGioco && cp2.inGioco || cp1.inGioco && cp3.inGioco ||cp1.inGioco && cp4.inGioco ||cp2.inGioco && cp3.inGioco ||cp2.inGioco && cp4.inGioco ||cp3.inGioco && cp4.inGioco)}{

return false;

}

else{

return true;

}



}