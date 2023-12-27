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
* La partita inizia ***sempre*** con 4 giocatori, di cui solo 1 può essere umano

