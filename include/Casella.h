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
  void setValore(std::string v);
  void addValore(std::string v);

  void setImmobile(std::string immobile);
  void unsetImmobile(std::string immobile);

  // Stampa il valore della casella (con giocatori e immobili se presenti)
  void stampaCasella();

  // Metodi per la gestione dei giocatori e degli immobili
  // ----------------------------------
  // Restituisce true se la casella è vuota
  bool isVuota();
  // Aggiunge un giocatore alla Casella
  void aggiungiGiocatore(std::string giocatore);
  // Rimuove un giocatore dalla Casella
  void rimuoviGiocatore(std::string giocatore);
  // Aggiunge un immobile alla Casella
  void aggiungiImmobile(int giocatore);

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
  int proprietarioCasella;
  std::vector<std::string> coordinate;
  std::string valore;
};

#endif // CASELLA_H
