// Autore: Perin Marco
// ------------------------------
#ifndef CASELLA_H
#define CASELLA_H
#include <iostream>
#include <vector>

class Casella {
public:
  // Costruttore con parametri
  Casella(char riga, int colonna);
  // Metodi get
  char getRiga();
  int getColonna();
  std::vector<std::string> getCoordinate();
  std::string getValore();
  void setValore(std::string valore);

  void setImmobile(std::string immobile);
  void unsetImmobile(std::string immobile);

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
  std::vector<std::string> coordinate;
  std::string valore;
};

#endif // CASELLA_H
