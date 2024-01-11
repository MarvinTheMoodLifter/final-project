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
  Giocatore(int numeroGiocatore, bool inGioco = true, int fiorini = 100,
            int posizione = 0);
  int getPosizione() const;
  int getNumeroGiocatore() const;
  int getFiorini() const;
  bool getInGioco() const { return inGioco; };
  void setFiorini(int valore);
  void setPosizione(int p);
  void setInGioco(bool v);

  // Copy constructor
  Giocatore(const Giocatore &g);
  // Assegnatore di copia (per l'uso in Tabellone)
  Giocatore &operator=(const Giocatore &g);
  // bool umano;
  virtual bool isUmano() const;

  // Distruttore virtuale
  virtual ~Giocatore() = default;
};

#endif // GIOCATORE_H
