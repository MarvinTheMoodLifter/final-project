#ifndef SPOSTAMENTO_H
#define SPOSTAMENTO_H
#include "Casella.h"

class Spostamento {
private:
  int giocatore;
  int posizioneGiocatore;

public:
  Spostamento();
  int spostamentoGiocatore(std::vector<Casella> &tabellone, int giocatore,
                           int posizione);
  int tiraDadi();
};

#endif // !SPOSTAMENTO_H
