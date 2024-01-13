// Autore: Perin Marco
// ------------------------------
#include "Tabellone.h"
#include <algorithm>
#include <iostream>
#include <random>

Tabellone::Tabellone(std::string tipoPartita, Giocatore *g1, Giocatore *g2,
                     Giocatore *g3, Giocatore *g4)
    : cp1(g1), cp2(g2), cp3(g3), cp4(g4) {
  // Riempie la prima parte di tabellone con le caselle vuote
  riempiTabellone();
  // Riempie le caselle del tabellone in maniera randomica
  riempiCaselleRandom();
  // stampa fiorini giocatori
  std::cout << "Creazione di Tabellone" << std::endl;
  std::cout << "Giocatore 1: " << g1->getFiorini() << std::endl;
  std::cout << "Giocatore 2: " << g2->getFiorini() << std::endl;
  std::cout << "Giocatore 3: " << g3->getFiorini() << std::endl;
  std::cout << "Giocatore 4: " << g4->getFiorini() << std::endl;
}

void Tabellone::riempiTabellone() {
  // Riempie la prima parte di tabellone con le caselle vuote
  for (char riga = 'H'; riga > 'A'; riga--) {
    for (int colonna = 8; colonna >= 1; colonna--) {
      if (riga == 'H' || colonna == 1) {
        tabellone.push_back(new Casella(riga, colonna));
      }
    }
  }
  // Riempie la seconda parte di tabellone con le caselle vuote
  for (char riga = 'A'; riga < 'H'; riga++) {
    for (int colonna = 1; colonna <= 8; colonna++) {
      if (riga == 'A' || colonna == 8) {
        tabellone.push_back(new Casella(riga, colonna));
      }
    }
  }
}

void Tabellone::randomizzaVettore(std::vector<char> &v) {
  // Genera un seme casuale
  std::random_device randomSeed;
  // Genera numeri casuali a partire dal seme generato in precedenza
  std::mt19937 gen(randomSeed());
  // Mescola il vettore
  std::shuffle(v.begin(), v.end(), gen);
}

void Tabellone::riempiCaselleRandom() {
  // Creo un vettore di char con i tipi di caselle
  // 8 caselle economiche
  // 10 caselle standard
  // 6 caselle lusso
  std::vector<char> tipiCaselle = {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E',
                                   'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S',
                                   'S', 'S', 'L', 'L', 'L', 'L', 'L', 'L'};
  randomizzaVettore(tipiCaselle);
  // Inizializzo la casella di partenza
  tabellone[0]->setTipologia('P');
  int count = 0;
  for (int i = 1; i < 28; i++) {
    char rigaCasella = tabellone[i]->getRiga();
    int colonnaCasella = tabellone[i]->getColonna();
    // Salta le caselle agli angoli
    if (rigaCasella == 'A' && colonnaCasella == 1 ||
        rigaCasella == 'A' && colonnaCasella == 8 ||
        rigaCasella == 'H' && colonnaCasella == 1) {
      count++;
      tabellone[i]->setTipologia(' ');
      continue;
    }
    tabellone[i]->setTipologia(tipiCaselle[i - 1 - count]);
  }
}

void Tabellone::muoviGiocatore(Giocatore *giocatore, Giocatore *giocatore2,
                               Giocatore *giocatore3, Giocatore *giocatore4) {
  // Dati del giocatore
  int vecchiaPosizione = giocatore->getPosizione();
  int numGiocatore = giocatore->getNumeroGiocatore();
  // Creo dadi e li tiro
  Dadi dadi(6);
  int mossa = dadi.tiraDadi(2);
  std::cout << "Il giocatore " << numGiocatore << " ha tirato " << mossa
            << std::endl;

  // Creo l'oggetto Dadi che si occupa di generare la probabilità di azione dei
  // computer
  Dadi dadiComputer(4);

  // Genero l'indice della nuova posizione
  // Nel caso in cui la nuova posizione sia maggiore di 27, il giocatore passa
  // dal via
  int nuovaPosizione = vecchiaPosizione + mossa;
  if (nuovaPosizione > 27) {
    nuovaPosizione -= 27;
    std::cout << "Giocatore " << numGiocatore
              << " è passato dal via e ha ritirato " << 20 << " fiorini"
              << std::endl;
    giocatore->setFiorini(giocatore->getFiorini() + 20);
  }

  // Prendo le caselle di partenza e di arrivo
  Casella *vecchiaCasella = tabellone[vecchiaPosizione];
  Casella *nuovaCasella = tabellone[nuovaPosizione];
  // Sposto il Giocatore e cambio il valore della casella
  giocatore->setPosizione(nuovaPosizione);
  vecchiaCasella->rimuoviGiocatore(std::to_string(numGiocatore));
  nuovaCasella->aggiungiGiocatore(std::to_string(numGiocatore));

  if (nuovaCasella->getProprietarioCasella() == numGiocatore) {
    // Caso in cui la casella è posseduta dal giocatore stesso
    // Controllo che immobili ci sono, se presenti.
    if (giocatore->isUmano()) {
      std::string messaggio = "Vuoi acquistare un immobile? (s->si, n->no, "
                              "show->mostra il tabellone)";
      std::string risposta = chiediGiocatore(messaggio);
      if (risposta == "s" && nuovaCasella->getImmobile() == '^') {
        // Se è un albergo non fare nulla
        std::cout << "Possiedi già un albergo in questa casella!" << std::endl;
      } else if (risposta == "s" &&
                 giocatore->getFiorini() >=
                     nuovaCasella->prezzoMiglioramentoImmobile()) {
        // Acquista l'immobile
        std::cout << "Acquisto dell'immobile in corso..." << std::endl;
        nuovaCasella->miglioraImmobile();
        giocatore->setFiorini(giocatore->getFiorini() -
                              nuovaCasella->prezzoMiglioramentoImmobile());
        std::cout << "Il giocatore " << numGiocatore
                  << " ha acquistato l'immobile in questa casella per "
                  << nuovaCasella->prezzoMiglioramentoImmobile() << std::endl;
        return;
      }
    } else {
      // Se è un albergo non fare nulla
      if (nuovaCasella->getImmobile() == '^') {
        std::cout << "Giocatore" << numGiocatore
                  << " possiede già un albergo in questa casella!" << std::endl;
      } else {
        if (giocatore->getFiorini() >=
            nuovaCasella->prezzoMiglioramentoImmobile()) {
          // Prova ad acquistare l'immobile
          if (dadiComputer.tiraDadi(1) == 1) {
            std::cout << "Acquisto dell'immobile in corso..." << std::endl;
            nuovaCasella->miglioraImmobile();
            giocatore->setFiorini(giocatore->getFiorini() -
                                  nuovaCasella->prezzoMiglioramentoImmobile());
            std::cout << "Il giocatore " << numGiocatore
                      << " ha acquistato l'immobile in questa casella"
                      << std::endl;
          }
        }
        return;
      }
    }
  } else if (nuovaCasella->getProprietarioCasella() == 0) {
    // Caso in cui la casella è libera
    if (nuovaCasella->isAngolare()) {
      std::string risposta;
      std::string messaggio = "Casella vuota, non puoi acquistarla. Vuoi "
                              "vedere il tabellone? show->mostra il tabellone)";
      return;
    }
    if (giocatore->isUmano()) {
      std::string messaggio = "La casella è libera, vuoi acquistarla? (s->si, "
                              "n->no, show-> mostra il tabellone)";
      std::string risposta = chiediGiocatore(messaggio);
      if (risposta == "s" &&
          giocatore->getFiorini() >= nuovaCasella->getPrezzoProprietà()) {
        // Acquista la casella
        std::cout << "Acquisto della casella in corso..." << std::endl;
        nuovaCasella->setProprietarioCasella(numGiocatore);
        nuovaCasella->setProprietario(giocatore);
        giocatore->setFiorini(giocatore->getFiorini() -
                              nuovaCasella->getPrezzoProprietà());
        std::cout << "Il giocatore " << numGiocatore
                  << " ha acquistato la casella per "
                  << nuovaCasella->getPrezzoProprietà() << std::endl;
        return;
      } else {
        // Non acquista la casella
        std::cout << "Casella non acquistata" << std::endl;
        return;
      }
    } else {
      // Acquista la casella
      if (giocatore->getFiorini() >= nuovaCasella->getPrezzoProprietà()) {
        // Prova ad acquistare l'immobile
        if (dadiComputer.tiraDadi(1) == 1) {
          nuovaCasella->setProprietarioCasella(numGiocatore);
          nuovaCasella->setProprietario(giocatore);
          giocatore->setFiorini(giocatore->getFiorini() -
                                nuovaCasella->getPrezzoProprietà());
          std::cout << "Il giocatore " << numGiocatore
                    << " ha acquistato la casella per "
                    << nuovaCasella->getPrezzoProprietà() << std::endl;
        }
        return;
      }
    }
  } else {
    // Caso in cui la casella è posseduta da un altro giocatore
    if (giocatore->getFiorini() >= nuovaCasella->getAffitto()) {
      // Paga l'affitto
      giocatore->setFiorini(giocatore->getFiorini() -
                            nuovaCasella->getAffitto());
      // Aggiunge i fiorini al proprietario della casella
      Giocatore *proprietario = nuovaCasella->getProprietario();
      proprietario->setFiorini(proprietario->getFiorini() +
                               nuovaCasella->getAffitto());
    } else {
      // Caso in cui il giocatore non riesce a pagare l'affitto
      giocatore->setFiorini(0);
      giocatore->setInGioco(false);
      return;
    }
  }
}

std::string Tabellone::chiediGiocatore(std::string messaggio) {
  std::string risposta = "show";
  while (risposta != "s" && risposta != "n") {
    std::cout << messaggio << std::endl;
    std::cin >> risposta;
    // Rende le lettere minuscole
    for (int i = 0; i < risposta.length(); i++) {
      risposta[i] = tolower(risposta[i]);
    }
    if (risposta == "show") {
      stampaTabellone();
    }
  }
  return risposta;
}

void Tabellone::stampaTabellone() {
  // Stampa il tabellone a partire dalla prima riga, poi le righe intermedie
  // ed infine l'ultima riga Stampa la prima riga Prima riga
  for (int i = tabellone.size() - 14; i < tabellone.size() - 6; i++) {
    tabellone[i]->stampaCasella();
  }
  std::cout << std::endl;
  // Righe intermedie
  for (int i = 0; i < 6; i++) {
    // Stampa la colonna di sinistra
    tabellone[13 - i]->stampaCasella();
    // Stampa il logo centrale
    switch (i) {
    case 0:
      std::cout << "     .. ..                     .          ";
      break;
    case 1:
      std::cout << "     ::::: ::: ::: ::: ::: ::: : : :      ";
      break;
    case 2:
      std::cout << "     : : : : : : : : : : : : : : : :      ";
      break;
    case 3:
      std::cout << "     :. .: ::: : : ::: ::: ::: :  ::      ";
      break;
    case 4:
      std::cout << "                       :          :       ";
      break;
    case 5:
      std::cout << "                       \'         \'        ";
      break;
    }
    // Stampa la colonna di destra
    tabellone[27 - i]->stampaCasella();
    std::cout << std::endl;
  }
  // Ultima riga
  for (int i = 0; i < 8; i++) {
    tabellone[7 - i]->stampaCasella();
  }
  std::cout << std::endl;
  // stampa i fiorini giocatori
  std::string g1 = cp1->isUmano() ? "(umano)" : "(computer)";
  std::cout << "Fiorini giocatore 1 " << g1 << ": " << cp1->getFiorini()
            << std::endl;
  std::cout << "Fiorini giocatore 2 (computer): " << cp2->getFiorini()
            << std::endl;
  std::cout << "Fiorini giocatore 3 (computer): " << cp3->getFiorini()
            << std::endl;
  std::cout << "Fiorini giocatore 4 (computer): " << cp4->getFiorini()
            << std::endl;
}

std::vector<Casella *> Tabellone::getTabellone() const { return tabellone; }

void Tabellone::assegnaProprietario(Giocatore *giocatore, int posizione) {
  tabellone[posizione]->setProprietario(giocatore);
  switch (giocatore->getNumeroGiocatore()) {
  case 1:
    proprietàcp1.push_back(tabellone[posizione]);
    break;
  case 2:
    proprietàcp2.push_back(tabellone[posizione]);
    break;
  case 3:
    proprietàcp3.push_back(tabellone[posizione]);
    break;
  case 4:
    proprietàcp4.push_back(tabellone[posizione]);
    break;
  }
}

void Tabellone::rimuoviGiocatore(Giocatore *giocatore) {
  // Rimuove tutte le proprietà del giocatore
  switch (giocatore->getNumeroGiocatore()) {
  case 1:
    for (int i = 0; i < proprietàcp1.size(); i++) {
      proprietàcp1[i]->setProprietarioCasella(0);
      proprietàcp1[i]->setProprietario(nullptr);
    }
    break;
  case 2:
    for (int i = 0; i < proprietàcp2.size(); i++) {
      proprietàcp2[i]->setProprietarioCasella(0);
      proprietàcp2[i]->setProprietario(nullptr);
    }
    break;
  case 3:
    for (int i = 0; i < proprietàcp3.size(); i++) {
      proprietàcp3[i]->setProprietarioCasella(0);
      proprietàcp3[i]->setProprietario(nullptr);
    }
    break;
  case 4:
    for (int i = 0; i < proprietàcp4.size(); i++) {
      proprietàcp4[i]->setProprietarioCasella(0);
      proprietàcp4[i]->setProprietario(nullptr);
    }
    break;
  }
}

// Distruttore
Tabellone::~Tabellone() {
  for (int i = 0; i < tabellone.size(); i++) {
    delete tabellone[i];
  }
}
