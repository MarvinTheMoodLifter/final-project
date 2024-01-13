// Autore: Perin Marco
// ------------------------------
#ifndef CASELLA_H
#define CASELLA_H
#include <string>
#include <vector>

class Giocatore;

class Casella {
public:
  // Costruttore con parametri
  Casella(char riga, int colonna);

  // Funzioni get
  char getRiga() { return riga; };
  int getColonna() { return colonna; };
  std::vector<std::string> getCoordinate() { return coordinate; };
  char getImmobile() { return immobile; };
  int getProprietarioCasella() { return proprietarioCasella; };
  Giocatore *getProprietario() { return proprietario; };
  int getPrezzoProprietà();
  int getAffitto();
  int prezzoMiglioramentoImmobile();
  void miglioraImmobile();

  // Funzioni set
  void setImmobile(char immobile);
  void setTipologia(char tipologia);
  void setProprietarioCasella(int nuovoProprietario);
  void setProprietario(Giocatore *nuovoProprietario);

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
  bool isAngolare();

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
  int proprietarioCasella = 0;
  Giocatore *proprietario = nullptr;
  std::vector<std::string> coordinate;
  char immobile = ' ';
  char tipologia = ' ';
  std::string giocatoriPresenti = " ";
  int prezzoProprietà = 0;
};

#endif // CASELLA_H
