#include "GiocatoreNonUmano.h"
#include <random>


GiocatoreNonUmano::GiocatoreNonUmano(int numGio){
	
	setFiorini(100);
	inGioco=true;
    umano=false;
	setPosizione(0);
    numeroGiocatore=numGio;
	
	}

char GiocatoreNonUmano::scelte(){

   int d = generatore();
   

    if(d=0){

        char s = "s";
        return s;


    }

    else{

         char n = "n";
        return n;




    }


}

int generatore(){
    std::random_device randomSeed;
    std::mt19937 gen{randomSeed()};
    std::uniform_int_distribution<int> dist{1, 4};
    

return dist(gen);

}