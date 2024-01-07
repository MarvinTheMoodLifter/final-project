#include "Tabellone.h"
#include "Giocatore.h"



class Turno{
	
	public:
	
	Turno(Tabellone tab);

	Turno(Tabellone tab, int n);
	
	turnoGiocatoreUmano(Giocatore umano);
	
	turnoGiocatoreNonUmano(Giocatore nonUmano);

	private:
	
	int numeroTurniGiocati;
	
	
	
}