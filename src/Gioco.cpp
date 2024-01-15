// Autore: Chellin Davide
// ------------------------------
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
  // Messaggio di benvenuto e spiegazione del gioco (cout e file di log)
  std::string titolo =
      "Benvenuto in Monopoly, il gioco inizia ora, buona fortuna!";
  std::ofstream log;
  log.open("../log/log.txt", std::ios::out | std::ios::trunc);
  log << titolo << std::endl;
  log.close();
  std::cout << titolo << std::endl;
  principale->stampaTabellone();
}

void Gioco::chiediGiocatore(std::string messaggio) {
  // Chiede al giocatore se vuole vedere lo stato attuale della partita o
  // continuare
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
  // Chiama muoviGiocatore di Tabellone per il giocatore p
  // Creo un vettore con i giocatori da non muovere
  std::vector<Giocatore *> giocatoriDaNonMuovere;
  for (int i = 0; i < giocatoriInPartita.size(); i++) {
    if (giocatoriInPartita[i] != p) {
      // Se il giocatore non è p allora lo aggiungo al vettore dei giocatori da
      // non muovere
      giocatoriDaNonMuovere.push_back(giocatoriInPartita[i]);
    }
  }
  if (umanoInGioco() && p->getInGioco()) {
    // Se il giocatore umano e il giocatore p sono in gioco
    if (p->isUmano()) {
      // turno giocatore umano
      std::string messaggio =
          "È il tuo turno, giocatore " +
          std::to_string(p->getNumeroGiocatore()) +
          ": s->tira i dadi, show->stato attuale della partita";
      chiediGiocatore(messaggio);
      // Chiamo muoviGiocatore di Tabellone
      principale->muoviGiocatore(p, giocatoriDaNonMuovere[0],
                                 giocatoriDaNonMuovere[1],
                                 giocatoriDaNonMuovere[2]);
    } else {
      // turno giocatore computer
      principale->muoviGiocatore(p, giocatoriDaNonMuovere[0],
                                 giocatoriDaNonMuovere[1],
                                 giocatoriDaNonMuovere[2]);
    }
  } else if (!umanoInGioco() && p->getInGioco()) {
    // turno giocatore computer se l'umano non è in gioco
    principale->muoviGiocatore(p, giocatoriDaNonMuovere[0],
                               giocatoriDaNonMuovere[1],
                               giocatoriDaNonMuovere[2]);
  }
  return;
}

void Gioco::gioca() {
  // Stabilisco l'ordine di gioco
  ordineGioco();
  if (tipoGioco == "human") {
    while (umanoInGioco()) {
      // Gioco finchè il giocatore umano non perde
      principale->stampaTabellone();
      for (int i = 0; i < 4; i++) {
        // Chiamo turnoGiocatore per ogni giocatore
        if (ordineGiocatoriPartita[i]->getInGioco()) {
          turnoGiocatore(ordineGiocatoriPartita[i]);
          // Aspetto 1 secondo prima di passare al prossimo giocatore
          std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        if (ultimoGiocatore()) {
          // Se l'ultimo giocatore è l'umano allora la partita è finita
          finePartita();
          return;
        } else if (!umanoInGioco()) {
          // Se l'umano non è più in gioco allora la partita continua con i
          // giocatori computer
          std::cout
              << "Hai perso, la partita continua con i giocatori computer."
              << std::endl;
          break;
        }
      }
    }
    if (ordineGiocatoriPartita.size() > 1) {
      // Se almeno due computer sono in gioco allora continuo a giocare 20
      // turni
      for (int i = 0; i < 20; i++) {
        principale->stampaTabellone();
        for (int i = 0; i < 4; i++) {
          turnoGiocatore(ordineGiocatoriPartita[i]);
          std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
      }
    }
  } else if (tipoGioco == "computer") {
    // Gioco 20 turni con i 4 computer
    for (int i = 0; i < 20; i++) {
      for (int i = 0; i < 4; i++) {
        turnoGiocatore(ordineGiocatoriPartita[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      }
      // Stampo il tabellone
      principale->stampaTabellone();
    }
  }
  finePartita();
}

void Gioco::ordineGioco() {
  Dadi dadi(6);
  // Faccio tirare i dadi a tutti i giocatori e li metto in un vettore in
  // ordine, con il primo che ha tirato il numero più alto e a seguire gli
  // altri in ordine casuale
  int max = 0;
  int pareggi = 0;
  int count = 3;
  // Copio il vettore giocatoriInPartita in ordineGiocatoriPartita
  ordineGiocatoriPartita = giocatoriInPartita;
  while (count != 0) {
    for (int i = 0; i <= count; i++) {
      // Faccio tirare i dadi a tutti i giocatori
      int tiro = dadi.tiraDadi(2);
      std::string messaggio =
          "Giocatore " +
          std::to_string(ordineGiocatoriPartita[i]->getNumeroGiocatore()) +
          " ha tirato i dadi per stabilire l'ordine di gioco e ha ottenuto " +
          std::to_string(tiro) + "\n";
      principale->stampaLog(messaggio);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      // Se il tiro è maggiore del massimo allora lo metto in prima posizione
      if (tiro > max) {
        max = tiro;
        pareggi = 0;
        // Sposto il giocatore che ha tirato il numero più alto in prima
        // posizione
        Giocatore *temp = ordineGiocatoriPartita[i];
        ordineGiocatoriPartita[i] = ordineGiocatoriPartita[0];
        ordineGiocatoriPartita[0] = temp;
      } else if (tiro == max) {
        // Se il tiro è uguale al massimo allora lo cambio con il giocatore in
        // posizione count
        pareggi++;
        Giocatore *temp = ordineGiocatoriPartita[i];
        ordineGiocatoriPartita[i] = ordineGiocatoriPartita[pareggi];
        ordineGiocatoriPartita[pareggi] = temp;
      }
      // Se il tiro è minore del massimo allora lo lascio nella posizione
    }
    if (pareggi != 0) {
      // Se non ci sono pareggi allora ho finito
      std::string messaggio = ":. Pareggio, si ripete il tiro dei dadi .:\n";
      principale->stampaLog(messaggio);
    }
    count = pareggi;
    pareggi = 0;
    max = 0;
  }
  // Stampo l'ordine di gioco
  std::cout << "L'ordine di gioco è: " << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cout << "Giocatore " << ordineGiocatoriPartita[i]->getNumeroGiocatore()
              << std::endl;
  }
}

void Gioco::finePartita() {
  // Controllo chi ha più fiorini chiamando comparaFiorini e stampo il vincitore
  std::vector<Giocatore *> vincitore = comparaFiorini();
  std::string messaggioVincitore = "";
  if (vincitore.size() == 1) {
    messaggioVincitore += "- Giocatore " +
                          std::to_string(vincitore[0]->getNumeroGiocatore()) +
                          " ha vinto la partita";
  } else {
    messaggioVincitore = "- Pareggio tra i giocatori, i vincitori "
                         "sono:\n";
    for (int i = 0; i < vincitore.size(); i++) {
      messaggioVincitore += "- Giocatore " +
                            std::to_string(vincitore[i]->getNumeroGiocatore()) +
                            "\n";
    }
  }
  principale->stampaLog(messaggioVincitore);
  return;
}

std::vector<Giocatore *> Gioco::comparaFiorini() {
  // Controllo chi ha più fiorini e restituisco un vettore con i vincitori
  int piuRicco = 0;
  std::vector<Giocatore *> vincitori;
  for (int i = 0; i < 4; i++) {
    // Controllo se il giocatore è in gioco e se ha più fiorini del precedente
    if (giocatoriInPartita[i]->getInGioco() &&
        giocatoriInPartita[i]->getFiorini() > piuRicco) {
      // Se è in gioco e ha più fiorini del precedente allora svuoto il vettore
      // vincitori
      vincitori.clear();
      vincitori.push_back(giocatoriInPartita[i]);
      piuRicco = giocatoriInPartita[i]->getFiorini();
    } else if (giocatoriInPartita[i]->getInGioco() &&
               giocatoriInPartita[i]->getFiorini() == piuRicco) {
      // Se è in gioco e ha lo stesso numero di fiorini del precedente allora lo
      // aggiungo al vettore vincitori
      vincitori.push_back(giocatoriInPartita[i]);
    }
  }
  return vincitori;
}

bool Gioco::umanoInGioco() {
  // controllo se il giocatore umano è in gioco
  return cp1->getInGioco() ? true : false;
}

bool Gioco::ultimoGiocatore() {
  // controllo se il giocatore umano è l'ultimo rimasto
  return umanoInGioco() && !cp2->getInGioco() && !cp3->getInGioco() &&
                 !cp4->getInGioco()
             ? true
             : false;
}

void Gioco::stampaTabellone() { principale->stampaTabellone(); }

void Gioco::stampaGiocatori() {
  for (int i = 0; i < 4; i++) {
    // Stampo i giocatori in partita
    if (giocatoriInPartita[i]->isUmano()) {
      std::cout << "Giocatore umano numero: "
                << giocatoriInPartita[i]->getNumeroGiocatore() << std::endl;
    } else {
      std::cout << "Giocatore computer numero: "
                << giocatoriInPartita[i]->getNumeroGiocatore() << std::endl;
    }
  }
}

// Distruttore
Gioco::~Gioco() {
  delete cp1;
  delete cp2;
  delete cp3;
  delete cp4;
}
