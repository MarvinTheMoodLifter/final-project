#include "Turno.h"
#include <iostream>



	Turno::Turno(Tabellone tab){
		
		numeroTurni=20;
		

				
		}
		
	Turno::Turno(Tabellone tab, int n){
		
		numeroTurni=n;
			
		
		}








	Turno::turnoGiocatoreUmano(Giocatore umano){
	
	
		Giocatore giocatoreCorrente = umano;
		
		std::cout<< "È il turno di " <<umano.getNumeroGiocatore<< "/n" << "digita s per proseguire, altrimenti digita show per mostrare lo stato attuale della partita" <<"/n";
		
		string i;
		string show = "show";
		string s = "s";

		
		std::cin>> i;
		
		//è case sensitive
		
		if(i.compare(show) ==0){
			
			Stampa.show(Tabellone tab, Giocatore a, Giocatore b, Giocatore c, Giocatore d);
			
			}
		
		else if (i.compare(s) ==0){
			
			tab.muoviGiocatore(giocatoreCorrente);
						
			
			}
		
		else () {
			
			std::cout<< "digita un comando valido" << "/n";
			
			turnoGiocatoreUmano(giocatoreCorrente);
			
			}
		
		
	}
	
	Turno::turnoGiocatoreNonUmano(Giocatore nonUmano){
		
		
		Giocatore giocatoreCorrente = nonUmano;
		
		std::cout<< "È il turno di " <<nonUmano.getNumeroGiocatore<< "/n";
		
		if(a.umano || b.umano || c.umano || d.umano =!0){
			
			numeroTurniGiocati++;
			
			if(numeroTurniGiocati/3==numeroTurni){
				
				std::cout<< "Fine partita" <<"/n";
				
				comparaFiorini();   
				
				// l'ho scritto su turno, adra riscritto su banchiere?

				
				}
			
			
			}
			
			
		else(){
			
			
			tab.muoviGiocatore(giocatoreCorrente);
					
			
			
			}	
			
					
		
		}
		
		int numeroTurniGiocati=0;

		
		