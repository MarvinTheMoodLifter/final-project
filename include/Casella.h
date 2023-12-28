// Autore: Perin Marco
// ------------------------------
#ifndef CASELLA_H
#define CASELLA_H

class Casella {
public:
  // Costruttore di default
  Casella();
  // Metodi get
  int getValore();
  int getRiga();
  int getColonna();
  // Stampa il valore della casella (con giocatori e immobili se presenti)
  void stampaCasella();

  // Distruttore
  ~Casella();

private:
  int valore;
  int riga;
  int colonna;
};

#endif // CASELLA_H
