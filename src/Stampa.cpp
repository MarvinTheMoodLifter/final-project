include "Tabellone"
include "Giocatore"
include <iostream>


	
	Stampa(){
		
		
		
		
		}
	
	void show(Tabellone tab, Giocatore a, Giocatore b, Giocatore c, Giocatore d){
		
		tab.stampaTabelloneGiocatori();
		stampaPossedimenti(Giocatore a, Giocatore b, Giocatore c, Giocatore d);
		stampaFiorini(Giocatore a, Giocatore b, Giocatore c, Giocatore d);
		
		
		}

	
	void stampaFiorini(Giocatore a, Giocatore b, Giocatore c, Giocatore d){
		
		int giocatoreA = a.getFiorini();
		int giocatoreB = b.getFiorini();
		int giocatoreC = c.getFiorini();
		int giocatoreD = d.getFiorini();
		
		std::cout<< a.getNumeroGiocatore << "possiede" << giocatoreA << "/n" 
		<< b.getNumeroGiocatore << "possiede" << giocatoreB << "fiorini" << "/n" 
		<< c.getNumeroGiocatore << "possiede" << giocatoreC << "fiorini" << "/n" 
		<< d.getNumeroGiocatore << "possiede" << giocatoreD << "fiorini" << "/n";
		
		
				
		
		}
	
	void stampaPossedimenti(){
		
		
		
		
		}
