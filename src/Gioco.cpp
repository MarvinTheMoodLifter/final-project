#include "Gioco.h"
#include <string>

// Costruttore
Gioco::Gioco(std::string tipoPartita) : tipoGioco(tipoPartita) {
  // Se partita con 1 umano 3 computer
  if (tipoPartita == "human") {
    cp1 = new GiocatoreUmano(1);
    // aggiungo i giocatori al vettore giocatoriInPartita
  } else if (tipoPartita == "computer") {
    // Se partita con 4 computer
    cp1 = new GiocatoreNonUmano(1);
  }
  cp2 = new GiocatoreNonUmano(2);
  cp3 = new GiocatoreNonUmano(3);
  cp4 = new GiocatoreNonUmano(4);
  // aggiungo i giocatori al vettore giocatoriInPartita
  giocatoriInPartita.push_back(cp1);
  giocatoriInPartita.push_back(cp2);
  giocatoriInPartita.push_back(cp3);
  giocatoriInPartita.push_back(cp4);
  principale = new Tabellone(tipoPartita, cp1, cp2, cp3, cp4);
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
      principale->stampaTabellone();
    } else if (risposta != "s") {
      std::cout << "Risposta non valida" << std::endl;
    }
  }
}

void Gioco::turnoGiocatore(Giocatore *p) {
  // Creo un vettore con i giocatori da non muovere
  std::vector<Giocatore *> giocatoriDaNonMuovere;
  for (int i = 0; i < giocatoriInPartita.size(); i++) {
    if (giocatoriInPartita[i] != p) {
      giocatoriDaNonMuovere.push_back(giocatoriInPartita[i]);
    }
  }
  if (umanoInGioco() && p->getInGioco()) {
    if (p->isUmano()) {
      // turno giocatore umano
      std::string messaggio =
          "È il tuo turno, giocatore " +
          std::to_string(p->getNumeroGiocatore()) +
          ": s->proseguire, show->stato attuale della partita";
      chiediGiocatore(messaggio);
      // Chiamo muoviGiocatore di Tabellone
      principale->muoviGiocatore(p, giocatoriDaNonMuovere[0],
                                 giocatoriDaNonMuovere[1],
                                 giocatoriDaNonMuovere[2]);
    } else {
      // turno giocatore computer
      std::cout << "È il turno di giocatore " << p->getNumeroGiocatore()
                << std::endl;
      principale->muoviGiocatore(p, giocatoriDaNonMuovere[0],
                                 giocatoriDaNonMuovere[1],
                                 giocatoriDaNonMuovere[2]);
    }
    return;
  } else if (umanoInGioco() && !p->getInGioco()) {
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
        turnoGiocatore(giocatoriInPartita[i]);
      }
      if (cp1->getInGioco())
        for (int i = 0; i < 20; i++) {
          for (int i = 0; i < 4; i++) {
            turnoGiocatore(giocatoriInPartita[i]);
          }
        }
    }
  } else if (tipoGioco == "computer") {
    for (int i = 0; i < 20; i++) {
      for (int i = 0; i < 4; i++) {
        turnoGiocatore(giocatoriInPartita[i]);
        std::cout << "Turno giocatore " << i << std::endl;
      }
      // Stampo il tabellone
      principale->stampaTabellone();
    }
    finePartita();
  }
}

void Gioco::ordineGioco() {
  Dadi dadi(6);
  std::vector<Giocatore *> ordineGiocatoriPartita;
  // Faccio tirare i dadi a tutti i giocatori e li metto in un vettore in
  // ordine, con il primo che ha tirato il numero più alto e a seguire gli
  // altri in ordine casuale
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
  std::vector<Giocatore *> vincitore = comparaFiorini();
  if (vincitore.size() == 1) {
    std::cout << "Fine partita, il vincitore è: Giocatore "
              << vincitore[0]->getNumeroGiocatore() << std::endl;
    return;
  } else {
    std::cout << "Fine partita, i vincitori sono: " << std::endl;
    for (int i = 0; i < vincitore.size(); i++) {
      std::cout << "Giocatore " << vincitore[i]->getNumeroGiocatore()
                << std::endl;
    }
    return;
  }
}

std::vector<Giocatore *> Gioco::comparaFiorini() {
  int piuRicco = 0;
  std::vector<Giocatore *> vincitori;
  for (int i = 0; i < 4; i++) {
    if (giocatoriInPartita[i]->getInGioco() &&
        giocatoriInPartita[i]->getFiorini() > piuRicco) {
      vincitori.clear();
      vincitori.push_back(giocatoriInPartita[i]);
      piuRicco = giocatoriInPartita[i]->getFiorini();
    } else if (giocatoriInPartita[i]->getInGioco() &&
               giocatoriInPartita[i]->getFiorini() == piuRicco) {
      vincitori.push_back(giocatoriInPartita[i]);
    }
  }
  return vincitori;
}

bool Gioco::umanoInGioco() {
  return giocatoriInPartita[0]->getInGioco() ? true : false;
}

bool Gioco::ultimoGiocatore() {
  // controllo se il giocatore umano è l'ultimo rimasto
  return umanoInGioco() && !giocatoriInPartita[1]->getInGioco() &&
                 !giocatoriInPartita[2]->getInGioco() &&
                 !giocatoriInPartita[3]->getInGioco()
             ? true
             : false;
}

void Gioco::stampaTabellone() { principale->stampaTabellone(); }

void Gioco::stampaGiocatori() {
  for (int i = 0; i < 4; i++) {
    // Se è umano stampa giocatore umano
    if (giocatoriInPartita[i]->isUmano()) {
      std::cout << "Giocatore umano numero: "
                << giocatoriInPartita[i]->getNumeroGiocatore() << std::endl;
    } else {
      std::cout << "Giocatore computer numero: "
                << giocatoriInPartita[i]->getNumeroGiocatore() << std::endl;
    }
  }
}

Gioco::~Gioco() {
  delete cp1;
  delete cp2;
  delete cp3;
  delete cp4;
}
