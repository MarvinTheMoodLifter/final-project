// Autore: Chellin Davide
// ------------------------------
#ifndef GIOCATORE_H
#define GIOCATORE_H

class Tabellone;

class Giocatore {
private:
  int numeroGiocatore;
  int fiorini;
  int posizione;
  bool inGioco;

public:
  Giocatore(int numeroGiocatore);
  int getPosizione() const { return posizione; };
  int getNumeroGiocatore() const { return numeroGiocatore; };
  int getFiorini() const { return fiorini; };
  void setPosizione(int posizione);
  void mossa(Tabellone &tabellone);
  // Copy constructor
  Giocatore(const Giocatore &g);
  // Assegnatore di copia (per l'uso in Tabellone)
  Giocatore &operator=(const Giocatore &g);
};

#endif // GIOCATORE_H
