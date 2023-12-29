// Autore: Perin Marco
// ------------------------------
#ifndef CASELLA_H
#define CASELLA_H
#include <iostream>
#include <string>

class Casella {
public:
  // Costruttore di default
  Casella();
  // Costruttore con parametri
  Casella(char riga, int colonna, std::string valore);
  // Metodi get
  char getRiga();
  int getColonna();
  std::string getValore();
  // Stampa il valore della casella (con giocatori e immobili se presenti)
  void stampaCasella();

  // Distruttore
  ~Casella();

private:
  char riga;
  int colonna;
  std::string valore;
};

#endif // CASELLA_H
