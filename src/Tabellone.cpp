// Autore: Perin Marco
// ------------------------------
#include "../include/Tabellone.h"
#include <vector>

Tabellone::Tabellone() {
  // Inizializza il tabellone
  for (char riga = 'H'; riga >= 'A'; riga--) {
    for (int colonna = 8; colonna >= 1; colonna--) {
      if (riga == 'A' || riga == 'H' || colonna == 1 || colonna == 8) {
        tabellone.push_back(Casella(riga, colonna, " "));
      }
    }
  }
}
