#include "Dadi.h"
#include "Turno.h"


	
	Turno::Turno(){
		
		numeroTurni=20;
		
		}
		
	Turno::Turno(int n){
		
		numeroTurni=n;
		
		}
	
	void Turno::statoPartita(Dadi DadoPartita){
		
		if(DadoPartita.getNumeroTiri() == numeroTurni){
			
			comparaFiorini();
			
			}
		
		
		}
	
	void Turno::comparaFiorini(){
		
		int tmp1=PrimoGiocatore.getFiorini();
		int tmp2=SecondoGiocatore.getFiorini();
		int tmp3=TerzoGiocatore.getFiorini();
		int tmp4=QuartoGiocatore.getFiorini();
		
		int max;
		max=tmp1;
		
		if(max<tmp2){
			
			max=tmp2;
			
			}
			
		if(max<tmp3){
			
			max=tmp3;
			
			}
			
		if(max<tmp4){
			
			max=tmp4;
			
			}
		
		
		//comando che annuncia vincitore della funzione print
				
		exit();
		
				
		}
	
	
	};