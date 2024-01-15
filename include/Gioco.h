// Autore: Chellin Davide
// ------------------------------
#ifndef GIOCO_H
#define GIOCO_H
#include "Tabellone.h"
#include <chrono>
#include <iostream>
#include <thread>

class Gioco {
public:
  // Costruttore
  Gioco(std::string tipoPartita);
  void turnoGiocatore(Giocatore *p);
  void gioca();
  void chiediGiocatore(std::string messaggio);
  void ordineGioco();
  void stampaTabellone();
  Giocatore *aggiungiGiocatori();
  bool ultimoGiocatore();
  std::vector<Giocatore *> comparaFiorini();
  bool umanoInGioco();
  void finePartita();
  void stampaGiocatori();

  ~Gioco();

private:
  std::vector<Giocatore *> giocatoriInPartita;
  std::vector<Giocatore *> ordineGiocatoriPartita;
  std::string tipoGioco;
  Giocatore *cp1;
  Giocatore *cp2;
  Giocatore *cp3;
  Giocatore *cp4;
  Tabellone *principale;
};

#endif // GIOCO_H
