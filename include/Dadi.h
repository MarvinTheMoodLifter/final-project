// Autore: Chellin Davide
// ------------------------------

#ifndef DADI_H
#define DADI_H


class Dadi {
	
	private:
	
	int numeroFacce;
	int sommaDadiLanciati;
	int conteggioTiri;
	
	public: 
	
	Dadi();
	Dadi(int numeroFacceDado);
	
	int tiraDadi(int numeroDadi);
	int getNumeroTiri();
	
	};



#endif //DADI_H