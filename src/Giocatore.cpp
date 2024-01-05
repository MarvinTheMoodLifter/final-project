#include "../include/Giocatore.h"

Giocatore::Giocatore(int numeroGiocatore){
	
	numeroGiocatore(numeroGiocatore);
	fiorini(100);
	inGioco(true);
	posizione(0);

void Giocatore::setPosizionePartenza(Tabellone &tabellone) {
  tabellone[0].aggiungiGiocatore(std::to_string(numeroGiocatore));
}

void Giocatore::mossa(Tabellone &tabellone) {
	
  tabellone.muoviGiocatore(numeroGiocatore, posizione);
  
}

int Giocatore::getPosizione() const { 
	
	return posizione; 
	
	}

int Giocatore::getNumeroGiocatore() {
	
	return numeroGiocatore;
	
	}
