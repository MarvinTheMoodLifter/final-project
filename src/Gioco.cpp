#include "Gioco.h"
#include <string>

// Costruttore
Gioco::Gioco(std::string tipoPartita)
    : principale(tipoPartita, cp1, cp2, cp3, cp4), tipoGioco(tipoPartita) {
  // Se partita con 1 umano 3 computer
  if (tipoPartita == "human") {
    cp1 = GiocatoreUmano(1);
    // aggiungo i giocatori al vettore giocatoriInPartita
  } else if (tipoPartita == "computer") {
    // Se partita con 4 computer
    cp1 = GiocatoreNonUmano(1);
  }
  cp2 = GiocatoreNonUmano(2);
  cp3 = GiocatoreNonUmano(3);
  cp4 = GiocatoreNonUmano(4);
  // aggiungo i giocatori al vettore giocatoriInPartita
  giocatoriInPartita.push_back(&cp1);
  giocatoriInPartita.push_back(&cp2);
  giocatoriInPartita.push_back(&cp3);
  giocatoriInPartita.push_back(&cp4);
}

void Gioco::chiediGiocatore(std::string messaggio) {
  std::string risposta = "show";
  while (risposta != "s") {
    std::cout << messaggio << std::endl;
    std::cin >> risposta;
    // Rende le lettere minuscole
    for (int i = 0; i < risposta.length(); i++) {
      risposta[i] = tolower(risposta[i]);
    }
    if (risposta == "show") {
      principale.stampaTabellone();
    } else if (risposta != "s") {
      std::cout << "Risposta non valida" << std::endl;
    }
  }
}

void Gioco::turnoGiocatore(Giocatore &p) {
  // Creo un vettore con i giocatori da non muovere
  std::vector<Giocatore *> giocatoriDaNonMuovere;
  for (int i = 0; i < giocatoriInPartita.size(); i++) {
    if (giocatoriInPartita[i] != &p) {
      giocatoriDaNonMuovere.push_back(giocatoriInPartita[i]);
    }
  }
  if (ultimoGiocatore() && p.getInGioco()) {
    if (p.isUmano()) {
      // turno giocatore umano
      std::string messaggio = "È il turno di " +
                              std::to_string(p.getNumeroGiocatore()) +
                              "/n digita s per proseguire, altrimenti digita "
                              "show per mostrare lo "
                              "stato attuale della partita/n";
      chiediGiocatore(messaggio);
      // Chiamo muoviGiocatore di Tabellone
      principale.muoviGiocatore(p, *giocatoriDaNonMuovere[0],
                                *giocatoriDaNonMuovere[1],
                                *giocatoriDaNonMuovere[2]);
    } else {
      // turno giocatore computer
      principale.muoviGiocatore(p, *giocatoriDaNonMuovere[0],
                                *giocatoriDaNonMuovere[1],
                                *giocatoriDaNonMuovere[2]);
    }
  } else if (!ultimoGiocatore() && !p.getInGioco()) {
    return;
  } else {
    finePartita();
    return;
  }
}

void Gioco::gioca() {
  // 4 casi con 4 posizioni in cui giocatore umano può partecipare in base a
  // come viene dato al costruttore oppure trova modo diverso

  // oppure creo solo metodo turnoGiocatore con all'interno if else in base a
  // flag del giocatore
  ordineGioco();
  if (tipoGioco == "human") {
    while (umanoInGioco()) {
      for (int i = 0; i < 4; i++) {
        turnoGiocatore(*giocatoriInPartita[i]);
      }
      if (cp1.getInGioco())
        for (int i = 0; i < 20; i++) {
          for (int i = 0; i < 4; i++) {
            turnoGiocatore(*giocatoriInPartita[i]);
          }
        }
    }
  } else if (tipoGioco == "computer") {
    for (int i = 0; i < 20; i++) {
      for (int i = 0; i < 4; i++) {
        turnoGiocatore(*giocatoriInPartita[i]);
      }
    }
    finePartita();
  }
}

void Gioco::ordineGioco() {
  Dadi dadi(6);
  std::vector<Giocatore *> ordineGiocatoriPartita;
  // Faccio tirare i dadi a tutti i giocatori e li metto in un vettore in
  // ordine, con il primo che ha tirato il numero più alto e a seguire gli altri
  // in ordine casuale
  int max = 0;
  for (int i = 0; i < 4; i++) {
    int tiro = dadi.tiraDadi(2);
    if (tiro > max) {
      max = tiro;
      ordineGiocatoriPartita.insert(ordineGiocatoriPartita.begin(),
                                    giocatoriInPartita[i]);
    } else {
      ordineGiocatoriPartita.push_back(giocatoriInPartita[i]);
    }
  }
}

void Gioco::finePartita() {

  std::vector<int> vincitore = comparaFiorini();
  for (int i = 0; i < vincitore.size(); i++) {
    std::cout << "Fine partita, il vincitore è il giocatore numero: "
              << vincitore[i] << "/n";
  }
  // compara fiorini con il metodo
  // annuncia vincitore
  // termina programma
  // stampa su file terminale
  // stampa finale
}

std::vector<int> Gioco::comparaFiorini() {
  int piuRicco = 0;
  std::vector<int> vincitori;
  for (int i = 0; i < 4; i++) {
    if (giocatoriInPartita[i]->getInGioco() &&
        giocatoriInPartita[i]->getFiorini() > piuRicco) {
      vincitori.clear();
      vincitori.push_back(giocatoriInPartita[i]->getNumeroGiocatore());
      piuRicco = giocatoriInPartita[i]->getFiorini();
    } else if (giocatoriInPartita[i]->getInGioco() &&
               giocatoriInPartita[i]->getFiorini() == piuRicco) {
      vincitori.push_back(giocatoriInPartita[i]->getNumeroGiocatore());
    }
  }
  return vincitori;
}

bool Gioco::umanoInGioco() {
  for (int i = 0; i < 4; i++) {
    if (giocatoriInPartita[i]->isUmano() &&
        giocatoriInPartita[i]->getInGioco()) {
      return true;
    }
  }
  return false;
}

bool Gioco::ultimoGiocatore() {
  // controllo se il giocatore umano è l'ultimo rimasto
  if (giocatoriInPartita[0]->isUmano() && giocatoriInPartita[0]->getInGioco()) {
    return true;
  }
  return false;
}

void Gioco::stampaTabellone() { principale.stampaTabellone(); }
