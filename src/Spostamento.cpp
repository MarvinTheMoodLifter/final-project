#include "Spostamento.h"

Spostamento::Spostamento() {}

int Spostamento::spostamentoGiocatore(std::vector<Casella> &tabellone,
                                      int giocatore, int posizione) {
  int valoreDadi = tiraDadi();
  int posizioneInizialeGiocatore = posizione;
  int posizioneFinaleGiocatore = posizioneInizialeGiocatore + valoreDadi;
  if (posizioneFinaleGiocatore > 27) {
    posizioneFinaleGiocatore -= 28;
  }
  return posizioneFinaleGiocatore;
}

int Spostamento::tiraDadi() {
  // Genera due numeri casuali tra 1 e 6 e li somma
  int dado1 = rand() % 6 + 1;
  int dado2 = rand() % 6 + 1;
  return dado1 + dado2;
}
