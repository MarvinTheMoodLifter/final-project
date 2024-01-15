// Autore: Perin Marco
// ------------------------------
#ifndef CASELLA_H
#define CASELLA_H
#include <string>
#include <vector>

class Giocatore;

class Casella {
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

public:
  // Costruttore con parametri
  Casella(char riga, int colonna);

  // Getters
  char getRiga() { return riga; };
  int getColonna() { return colonna; };
  std::vector<std::string> getCoordinate() { return coordinate; };
  char getTipologia() { return tipologia; };
  char getImmobile() { return immobile; };
  int getProprietarioCasella() { return proprietarioCasella; };
  Giocatore *getProprietario() { return proprietario; };
  int getPrezzoProprietà();
  int getAffitto();
  int prezzoMiglioramentoImmobile();
  bool isVuota();
  bool isAngolare();

  // Setters
  void setImmobile(char immobile);
  void setTipologia(char tipologia);
  void setProprietarioCasella(int nuovoProprietario);
  void setProprietario(Giocatore *nuovoProprietario);
  void aggiungiGiocatore(std::string giocatore);
  void rimuoviGiocatore(std::string giocatore);
  void miglioraImmobile();

  // Stampa
  void stampaCasella();

  bool operator==(const Casella &c) const {
    // Overloading dell'operatore di uguaglianza
    return (riga == c.riga && colonna == c.colonna);
  }
  bool operator!=(const Casella &c) const {
    // Overloading dell'operatore di disuguaglianza
    return (riga != c.riga || colonna != c.colonna);
  }
  // Copy assignment operator
  Casella operator=(const Casella &c);

  // Distruttore
  ~Casella() = default;
};

#endif // CASELLA_H
