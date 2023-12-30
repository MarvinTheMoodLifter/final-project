#include "../include/Spostamento.h"

Spostamento::Spostamento(Tabellone tabellone) : tabellone(tabellone) {}

void Spostamento::mossaGiocatore(Giocatore &giocatore) {
  // Muove il giocatore di valoreDadi caselle
  // Se il giocatore supera la casella 27, riparte dalla casella di partenza e
  // finisce di muovere
  int valoreDadi = tiroDadi();
  std::cout << "Valore dadi: " << valoreDadi << std::endl;
  int posizioneGiocatore = giocatore.getPosizione();
  if (posizioneGiocatore + valoreDadi > 27) {
    int caselleRimanenti = 27 - posizioneGiocatore;
    int mossa = valoreDadi - caselleRimanenti;
    giocatore.setPosizione(mossa);
    passaDaVia = true;
  } else {
    giocatore.setPosizione(posizioneGiocatore + valoreDadi);
  }
}

int Spostamento::tiroDadi() {
  // Genera un numero random tra 2 e 12
  std::random_device randomSeed;
  std::mt19937 gen(randomSeed());
  std::uniform_int_distribution<> distribuzione(2, 12);
  return distribuzione(gen);
}
