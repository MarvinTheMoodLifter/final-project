// Autore: Perin Marco
// ------------------------------
#include "Tabellone.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <string>

Tabellone::Tabellone(std::string tipoPartita, Giocatore *g1, Giocatore *g2,
                     Giocatore *g3, Giocatore *g4)
    : cp1(g1), cp2(g2), cp3(g3), cp4(g4) {
  // Riempie la prima parte di tabellone con le caselle vuote
  riempiTabellone();
  // Riempie le caselle del tabellone in maniera randomica
  riempiCaselleRandom();
  // stampa fiorini giocatori
  std::cout << "Creazione del Tabellone..." << std::endl;
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
  // Se il giocatore non è in gioco non fare nulla
  if (!giocatore->getInGioco()) {
    return;
  }
  // Dati del giocatore
  int vecchiaPosizione = giocatore->getPosizione();
  int numGiocatore = giocatore->getNumeroGiocatore();
  // Creo dadi e li tiro
  Dadi dadi(6);
  int mossa = dadi.tiraDadi(2);
  std::string inizioTurno =
      ":: Turno giocatore " + std::to_string(numGiocatore) + " ::\n";
  std::string tiroDadi = "- Giocatore " + std::to_string(numGiocatore) +
                         " ha tirato i dadi ottenendo un valore di " +
                         std::to_string(mossa) + "\n";
  stampaLog(inizioTurno);
  stampaLog(tiroDadi);
  // Creo l'oggetto Dadi che si occupa di generare la probabilità di azione dei
  // computer
  Dadi dadiComputer(4);
  // Genero l'indice della nuova posizione
  // Nel caso in cui la nuova posizione sia maggiore di 27, il giocatore passa
  // dal via
  int nuovaPosizione = vecchiaPosizione + mossa;
  if (nuovaPosizione > 27) {
    nuovaPosizione -= 27;
    std::string passaggioVia = "- Giocatore " + std::to_string(numGiocatore) +
                               " è passato dal via e ha ritirato 20 fiorini\n";
    giocatore->setFiorini(giocatore->getFiorini() + 20);
    stampaLog(passaggioVia);
  }
  // Prendo le caselle di partenza e di arrivo
  Casella *vecchiaCasella = tabellone[vecchiaPosizione];
  Casella *nuovaCasella = tabellone[nuovaPosizione];
  // Sposto il Giocatore e cambio il valore della casella
  giocatore->setPosizione(nuovaPosizione);
  vecchiaCasella->rimuoviGiocatore(std::to_string(numGiocatore));
  nuovaCasella->aggiungiGiocatore(std::to_string(numGiocatore));
  // Messaggio di spostamento
  std::string spostamento = "- Giocatore " + std::to_string(numGiocatore) +
                            " è arrivato alla casella " +
                            nuovaCasella->getRiga() +
                            std::to_string(nuovaCasella->getColonna()) + "\n";
  stampaLog(spostamento);
  if (nuovaCasella->getProprietarioCasella() == numGiocatore) {
    // Caso in cui la casella è posseduta dal giocatore stesso
    // Controllo che immobili ci sono, se presenti.
    if (giocatore->isUmano()) {
      std::string messaggio = "Vuoi acquistare un immobile? s->si, n->no, "
                              "show->mostra il tabellone";
      std::string risposta = chiediGiocatore(messaggio);
      if (risposta == "s" && nuovaCasella->getImmobile() == '^') {
        // Se è un albergo non fare nulla
        std::cout << "Possiedi già un albergo in questa casella!" << std::endl;
      } else if (risposta == "s" &&
                 giocatore->getFiorini() >=
                     nuovaCasella->prezzoMiglioramentoImmobile()) {
        // Acquista l'immobile
        nuovaCasella->miglioraImmobile();
        giocatore->setFiorini(giocatore->getFiorini() -
                              nuovaCasella->prezzoMiglioramentoImmobile());
        std::string acquistoImmobile = "";
        if (nuovaCasella->getImmobile() == '^') {
          acquistoImmobile = "- Giocatore " + std::to_string(numGiocatore) +
                             " ha migliorato una casa in albergo sul terreno " +
                             nuovaCasella->getRiga() +
                             std::to_string(nuovaCasella->getColonna()) + "\n";
        } else {
          acquistoImmobile = "- Giocatore " + std::to_string(numGiocatore) +
                             " ha costruito una casa sul terreno " +
                             nuovaCasella->getRiga() +
                             std::to_string(nuovaCasella->getColonna()) + "\n";
        }
        stampaLog(acquistoImmobile);
        return;
      }
    } else {
      // Se è un albergo non fare nulla
      if (nuovaCasella->getImmobile() == '^') {
        std::string albergoPosseduto =
            "- Giocatore" + std::to_string(numGiocatore) +
            " possiede già un albergo in questa casella!\n";
        stampaLog(albergoPosseduto);
      } else {
        if (giocatore->getFiorini() >=
            nuovaCasella->prezzoMiglioramentoImmobile()) {
          std::string acquistoImmobile = "";
          // Prova ad acquistare l'immobile
          if (dadiComputer.tiraDadi(1) == 1) {
            nuovaCasella->miglioraImmobile();
            giocatore->setFiorini(giocatore->getFiorini() -
                                  nuovaCasella->prezzoMiglioramentoImmobile());
            if (nuovaCasella->getImmobile() == '^') {
              acquistoImmobile =
                  "- Giocatore " + std::to_string(numGiocatore) +
                  " ha migliorato una casa in albergo sul terreno " +
                  nuovaCasella->getRiga() +
                  std::to_string(nuovaCasella->getColonna()) + "\n";
            } else {
              acquistoImmobile = "- Giocatore " + std::to_string(numGiocatore) +
                                 " ha costruito una casa sul terreno " +
                                 nuovaCasella->getRiga() +
                                 std::to_string(nuovaCasella->getColonna()) +
                                 "\n";
            }
          }
          stampaLog(acquistoImmobile);
        }
        return;
      }
    }
  } else if (nuovaCasella->getProprietarioCasella() == 0) {
    // Caso in cui la casella è libera
    if (nuovaCasella->isAngolare()) {
      if (giocatore->isUmano()) {
        std::string messaggio =
            "Casella vuota, non puoi acquistarla. Vuoi "
            "vedere il tabellone? show->mostra il tabellone";
        std::string risposta = chiediGiocatore(messaggio);
      }
      return;
    }
    if (giocatore->isUmano()) {
      std::string messaggio = "La casella è libera, vuoi acquistarla? s->si, "
                              "n->no, show-> mostra il tabellone";
      std::string risposta = chiediGiocatore(messaggio);
      if (risposta == "s" &&
          giocatore->getFiorini() >= nuovaCasella->getPrezzoProprietà()) {
        // Acquista la casella
        nuovaCasella->setProprietarioCasella(numGiocatore);
        nuovaCasella->setProprietario(giocatore);
        aggiungiProprietario(giocatore, nuovaCasella);
        giocatore->setFiorini(giocatore->getFiorini() -
                              nuovaCasella->getPrezzoProprietà());
        std::string acquisto =
            "- Giocatore " + std::to_string(numGiocatore) +
            " ha acquistato il terreno " + nuovaCasella->getRiga() +
            std::to_string(nuovaCasella->getColonna()) + " per " +
            std::to_string(nuovaCasella->getPrezzoProprietà()) + "\n";
        stampaLog(acquisto);
        return;
      } else {
        // Non acquista la casella
        std::string messaggio = "Casella non acquistata\n";
        stampaLog(messaggio);
        return;
      }
    } else {
      // Acquista la casella
      if (giocatore->getFiorini() >= nuovaCasella->getPrezzoProprietà()) {
        // Prova ad acquistare l'immobile
        if (dadiComputer.tiraDadi(1) == 1) {
          nuovaCasella->setProprietarioCasella(numGiocatore);
          nuovaCasella->setProprietario(giocatore);
          aggiungiProprietario(giocatore, nuovaCasella);
          giocatore->setFiorini(giocatore->getFiorini() -
                                nuovaCasella->getPrezzoProprietà());
          std::string acquisto =
              "- Giocatore " + std::to_string(numGiocatore) +
              " ha acquistato il terreno " + nuovaCasella->getRiga() +
              std::to_string(nuovaCasella->getColonna()) + " per " +
              std::to_string(nuovaCasella->getPrezzoProprietà()) + "\n";
          stampaLog(acquisto);
        }
        return;
      }
    }
  } else if (nuovaCasella->getProprietarioCasella() != numGiocatore) {
    // Caso in cui la casella è posseduta da un altro giocatore
    if (nuovaCasella->getImmobile() == ' ') {
      return;
    }
    if (giocatore->getFiorini() >= nuovaCasella->getAffitto()) {
      // Paga l'affitto
      giocatore->setFiorini(giocatore->getFiorini() -
                            nuovaCasella->getAffitto());
      // Aggiunge i fiorini al proprietario della casella
      Giocatore *proprietario = nuovaCasella->getProprietario();
      proprietario->setFiorini(proprietario->getFiorini() +
                               nuovaCasella->getAffitto());
      std::string pagamentoAffitto =
          "- Giocatore " + std::to_string(numGiocatore) + " ha pagato " +
          std::to_string(nuovaCasella->getAffitto()) +
          " fiorini al giocatore " +
          std::to_string(nuovaCasella->getProprietarioCasella()) +
          " per pernottamento nella casella " + nuovaCasella->getRiga() +
          std::to_string(nuovaCasella->getColonna()) + "\n";
      stampaLog(pagamentoAffitto);
    } else {
      // Caso in cui il giocatore non riesce a pagare l'affitto
      giocatore->setFiorini(0);
      giocatore->setInGioco(false);
      rimuoviGiocatore(giocatore);
      std::string giocatoreEliminato = "- Giocatore " +
                                       std::to_string(numGiocatore) +
                                       " è stato eliminato\n";
      stampaLog(giocatoreEliminato);
      // Rimuove il giocatore dal vettore giocatoriInPartita
    }
  }
}

void Tabellone::aggiungiProprietario(Giocatore *giocatore, Casella *casella) {
  // Aggiunge il giocatore al vettore proprietà
  if (giocatore->getNumeroGiocatore() == 1) {
    proprietàcp1.push_back(casella);
  }
  if (giocatore->getNumeroGiocatore() == 2) {
    proprietàcp2.push_back(casella);
  }
  if (giocatore->getNumeroGiocatore() == 3) {
    proprietàcp3.push_back(casella);
  }
  if (giocatore->getNumeroGiocatore() == 4) {
    proprietàcp4.push_back(casella);
  }
}

// Aggiungo controllo input
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
  // Stampa la prima riga con i numeri di colonna
  std::cout << "     ";
  for (int i = 1; i <= 8; i++) {
    std::cout << i << "      ";
  }
  std::cout << std::endl << "A  ";
  // Stampa il tabellone a partire dalla prima riga, poi le righe intermedie
  // ed infine l'ultima riga Stampa la prima riga Prima riga
  for (int i = tabellone.size() - 14; i < tabellone.size() - 6; i++) {
    tabellone[i]->stampaCasella();
  }
  std::cout << std::endl;
  // Righe intermedie
  for (int i = 0; i < 6; i++) {
    // Stampa la colonna di sinistra
    std::cout << tabellone[13 - i]->getRiga() << "  ";
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
    tabellone[22 + i]->stampaCasella();
    std::cout << std::endl;
  }
  // Ultima riga
  std::cout << "H  ";
  for (int i = 0; i < 8; i++) {
    tabellone[7 - i]->stampaCasella();
  }
  std::cout << std::endl;
  // stampa i fiorini giocatori
  stampaFiorini();
  // Stampa le proprietà dei giocatori dal vettore proprietà
  stampaPossedimenti();
}

void Tabellone::stampaPossedimenti() const {
  // Stampa le proprietà dei giocatori dal vettore proprietà
  std::cout << "Giocatore 1 possiede: " << std::endl << " · ";
  for (int i = 0; i < proprietàcp1.size(); i++) {
    std::cout << proprietàcp1[i]->getRiga() << proprietàcp1[i]->getColonna()
              << " " << proprietàcp1[i]->getTipologia()
              << proprietàcp1[i]->getImmobile() << " · ";
  }
  std::cout << std::endl;
  std::cout << "Giocatore 2 possiede: " << std::endl << " · ";
  for (int i = 0; i < proprietàcp2.size(); i++) {
    std::cout << proprietàcp2[i]->getRiga() << proprietàcp2[i]->getColonna()
              << " " << proprietàcp2[i]->getTipologia()
              << proprietàcp2[i]->getImmobile() << " · ";
  }
  std::cout << std::endl;
  std::cout << "Giocatore 3 possiede: " << std::endl << " · ";
  for (int i = 0; i < proprietàcp3.size(); i++) {
    std::cout << proprietàcp3[i]->getRiga() << proprietàcp3[i]->getColonna()
              << " " << proprietàcp3[i]->getTipologia()
              << proprietàcp3[i]->getImmobile() << " · ";
  }
  std::cout << std::endl;
  std::cout << "Giocatore 4 possiede: " << std::endl << " · ";
  for (int i = 0; i < proprietàcp4.size(); i++) {
    std::cout << proprietàcp4[i]->getRiga() << proprietàcp4[i]->getColonna()
              << " " << proprietàcp4[i]->getTipologia()
              << proprietàcp4[i]->getImmobile() << " · ";
  }
  std::cout << std::endl;
}

void Tabellone::stampaFiorini() const {
  std::string g1 = cp1->isUmano() ? "(umano)" : "(computer)";
  // Crea i messaggi da stampare
  // Poi chiama la funzione stampaLog per scrivere il messaggio a schermo e in
  // un file di log
  std::string messaggio1 = "Fiorini giocatore 1 " + g1 + ": " +
                           std::to_string(cp1->getFiorini()) + "\n";
  std::string messaggio2 =
      "Fiorini giocatore 2 (computer): " + std::to_string(cp2->getFiorini()) +
      "\n";
  std::string messaggio3 =
      "Fiorini giocatore 3 (computer): " + std::to_string(cp3->getFiorini()) +
      "\n";
  std::string messaggio4 =
      "Fiorini giocatore 4 (computer): " + std::to_string(cp4->getFiorini()) +
      "\n";
  stampaLog(messaggio1);
  stampaLog(messaggio2);
  stampaLog(messaggio3);
  stampaLog(messaggio4);
}

void Tabellone::stampaLog(std::string messaggio) const {
  // Scrive il messaggio in un file di log
  std::cout << messaggio;
  std::ofstream log;
  log.open("../log/log.txt", std::ios::app);
  log << messaggio;
  log.close();
}

std::vector<Casella *> Tabellone::getTabellone() const { return tabellone; }

void Tabellone::assegnaProprietario(Giocatore *giocatore, int posizione) {
  tabellone[posizione]->setProprietario(giocatore);
  switch (giocatore->getNumeroGiocatore()) {
    if (giocatore->getNumeroGiocatore() == 1) {
      proprietàcp1.push_back(tabellone[posizione]);
    }
    if (giocatore->getNumeroGiocatore() == 2) {
      proprietàcp2.push_back(tabellone[posizione]);
    }
    if (giocatore->getNumeroGiocatore() == 3) {
      proprietàcp3.push_back(tabellone[posizione]);
    }
    if (giocatore->getNumeroGiocatore() == 4) {
      proprietàcp4.push_back(tabellone[posizione]);
    }
  }
}

void Tabellone::rimuoviGiocatore(Giocatore *giocatore) {
  // Rimuove tutte le proprietà del giocatore
  int dimensioneVettoreProprietà;
  if (giocatore->getNumeroGiocatore() == 1) {
    dimensioneVettoreProprietà = proprietàcp1.size();
    for (int i = 1; i <= dimensioneVettoreProprietà; i++) {
      proprietàcp1[dimensioneVettoreProprietà - i]->setProprietarioCasella(0);
      proprietàcp1[dimensioneVettoreProprietà - i]->setProprietario(nullptr);
      proprietàcp1[dimensioneVettoreProprietà - i]->setImmobile(' ');
      proprietàcp1.pop_back();
    }
  } else if (giocatore->getNumeroGiocatore() == 2) {
    dimensioneVettoreProprietà = proprietàcp2.size();
    for (int i = 1; i <= dimensioneVettoreProprietà; i++) {
      proprietàcp2[dimensioneVettoreProprietà - i]->setProprietarioCasella(0);
      proprietàcp2[dimensioneVettoreProprietà - i]->setProprietario(nullptr);
      proprietàcp2[dimensioneVettoreProprietà - i]->setImmobile(' ');
      proprietàcp2.pop_back();
    }
  } else if (giocatore->getNumeroGiocatore() == 3) {
    dimensioneVettoreProprietà = proprietàcp3.size();
    for (int i = 1; i <= dimensioneVettoreProprietà; i++) {
      proprietàcp3[dimensioneVettoreProprietà - i]->setProprietarioCasella(0);
      proprietàcp3[dimensioneVettoreProprietà - i]->setProprietario(nullptr);
      proprietàcp3[dimensioneVettoreProprietà - i]->setImmobile(' ');
      proprietàcp3.pop_back();
    }
  } else if (giocatore->getNumeroGiocatore() == 4) {
    dimensioneVettoreProprietà = proprietàcp4.size();
    for (int i = 1; i <= dimensioneVettoreProprietà; i++) {
      proprietàcp4[dimensioneVettoreProprietà - i]->setProprietarioCasella(0);
      proprietàcp4[dimensioneVettoreProprietà - i]->setProprietario(nullptr);
      proprietàcp4[dimensioneVettoreProprietà - i]->setImmobile(' ');
      proprietàcp4.pop_back();
    }
  }
}

// Distruttore
Tabellone::~Tabellone() {
  for (int i = 0; i < tabellone.size(); i++) {
    delete tabellone[i];
  }
}
