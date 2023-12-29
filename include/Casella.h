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

  void setValore(std::string valore);

  // Stampa il valore della casella (con giocatori e immobili se presenti)
  void stampaCasella();
  bool validaCasella();

  bool operator==(const Casella &c) const {
    return (riga == c.riga && colonna == c.colonna);
  }
  bool operator!=(const Casella &c) const {
    return (riga != c.riga || colonna != c.colonna);
  }
  Casella operator=(const Casella &c);

private:
  char riga;
  int colonna;
  std::string valore;
};

#endif // CASELLA_H
