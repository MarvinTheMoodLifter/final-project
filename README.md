# final-project

Vi viene richiesto di sviluppare un programma in C++ che implementi una versione semplificata del gioco Monopoly. Chi non ha familiarità con questo gioco può trovare la descrizione al link seguente:

* [wikipedia](https://it.wikipedia.org/wiki/Monopoly)
* [regole ufficiali](https://www.wikihow.it/Giocare-a-Monopoly)

## 1. Regole per la versione semplificata
Per semplificare il design e l’implementazione vi forniamo di seguito delle regole semplificate a cui il vostro programma *deve* attenersi.

### 1.1 Tabellone
* Il tabellone è composto da 8 x 8 caselle
* Le caselle sono di due tipi: 4 angolari e 24 laterali
* Una delle caselle angolari corrisponde alla casella di partenza, le altre tre sono vuote
* Le caselle laterali possono essere di tre categorie:
    * economica
    * standard
    * lusso
* Il tabellone sarà quindi formato da:
    * 4 caselle angolari (di cui una è una casella di partenza)
    * 8 caselle laterali di categoria economica
    * 10 caselle laterali di categoria standard
    * 6 caselle laterali di categoria lusso
* Ogni terreno può essere migliorato costruendo una casa, oppure un albergo (per semplicità, si suppone che su ogni proprietà esista al massimo una casa, e il passaggio successivo sia l'albergo).
* A parte le caselle angolari, le restanti sono posizionate in modo casuale all’inizio di ogni partita

### 1.2 Giocatori
* Esistono due tipi di giocatori:
    * giocatore umano
    * computer
* La partita inizia **_sempre_** con 4 giocatori, di cui solo 1 **_può_** essere umano
### 1.3 Tiro di dadi
* Un tiro di dadi corrisponde alla somma di 2 numeri casuali compresi fra 1 e 6
### 1.4 Meccaniche di gioco
* Ogni giocatore possiede un budget iniziale di 100 fiorini
* All’inizio di ogni partita, ogni giocatore tira i dadi. Il giocatore con il numero più alto inizierà la partita e poi si seguirà un ordine decrescente (in caso di parità di punteggio fra due o più giocatori, i giocatori interessati dovranni ritirare il dado)
* Una volta determinato l’ordine di gioco, il primo giocatore tirerà di nuovo i dadi e muoverà la sua pedina di un numero di caselle pari al numero uscito
* A questo punto possono verificarsi le seguenti condizioni:

|   | Giocatore Umano | Computer |
|---|---|---|
| Casella angolare | Non succede nulla, il turno del giocatore finisce. | Non succede nulla, il turno del giocatore finisce. |
| Casella laterale non appartenente a nessuno dei giocatori | Può decidere se comprare il terreno (la casella), se possiede abbastanza soldi. Altrimenti finisce il turno. | Può comprare il terreno (la casella) con una probabilità del 25%, se possiede abbastanza soldi. Altrimenti, finisce il turno |
| Casella laterale di proprietà del giocatore, senza casa/albergo | Può decidere se comprare una casa (il passaggio diretto da terreno semplice ad albergo non è possibile), se possiede abbastanza soldi. Altrimentifinisce il turno. |  |
| Casella laterale con casa di proprietà  |  |  |
| Casella laterale con casa/albergo di proprietà di un altro giocatore |  |  |
