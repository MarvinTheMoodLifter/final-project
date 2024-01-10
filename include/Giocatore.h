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
  Giocatore();
  Giocatore(int numeroGiocatore);
  int getPosizione();
  int getNumeroGiocatore() const;
  int getFiorini() const;
  bool getInGioco() const { return inGioco; };
  void setFiorini(int valore) { fiorini = valore; }
  void setPosizione(int posizione);

  void setPerso(bool v) { inGioco = v; }

  // Copy constructor
  Giocatore(const Giocatore &g);
  // Assegnatore di copia (per l'uso in Tabellone)
  Giocatore &operator=(const Giocatore &g);
  bool umano;
};

#endif // GIOCATORE_H
