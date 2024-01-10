#include "Giocatore.h"

class GiocatoreNonUmano : private Giocatore {
	
	public:
	GiocatoreNonUmano(int numGio);
    char scelte();
	private:
	bool umano;
	
	
	};


int generatore();
