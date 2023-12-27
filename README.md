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
| Casella laterale di proprietà del giocatore, senza casa/albergo | Può decidere se comprare una casa (il passaggio diretto da terreno semplice ad albergo non è possibile), se possiede abbastanza soldi. Altrimentifinisce il turno. | Può comprare una casa (il passaggio diretto da terreno semplice ad albergo non è possibile) con una probabilità del 25%, se possiede abbastanza soldi. |
| Casella laterale con casa di proprietà  | Può decidere di migliorare la propria casa in albergo, se possiede abbastanza soldi. Altrimenti, finisce il turno | Può migliorare la propria casa in albergo con una probabilità del 25%, se possiede abbastanza soldi. |
|Deve pagare il pernottamento nella struttura Casella laterale con casa/albergo di proprietà di un altro giocatore | Deve pagare il pernottamento nella struttura. | Deve pagare il pernottamento nella struttura. |

* Se con il tiro di dado, un giocatore passa per la casella di partenza, ritira 20 fiorini (cioè il suo budget viene incrementato di 20)
* I prezzi (in fiorini) per l'acquisto di una casa, il miglioramento in albergo di una casa esistente e il pernottamento nelle due diverse strutture e nelle diverse categorie di caselle, è riportato di seguito:

| | economica | standard | lusso |
|---|---|---|---|
| Acquisto terreno | 6 | 10 | 20 |
| Acquisto casa | 3 | 5 | 10 |
| Miglioramento ad albergo | 3 | 5 | 10 |
| Pernottamento in casa | 2 | 4 | 7 |
| Pernottamento in albergo | 4 | 8 | 14 |

* Un giocatore viene eliminato se non ha abbastanza fiorini al momento del pagamento del pernottamento. Gli altri giocatori continuano a giocare. Le caselle di proprietà del giocatore eliminato vengono svuotate di possibili case o alberghi e i terreni tornano ad essere disponibili per la vendita.
* Vince l'ultimo giocatore che rimane in gioco.

### 1.5 Visualizzazione
Nel caso di partita con un giocatore umano, è possibile richiedere al programma la visualizzazione del tabellone corrente. Verranno visualizzate le caselle del tabellone, la presenza di eventuali case o alberghi e la posizione dei giocatori attualmente in gioco.

La visualizzazione avviene stampando un carattere con un eventuale suffisso per ciascuna posizione:

| Casella | Carattere |
|---|---|
| Angolare | spazio |
| Partenza | P |
| Economica | E |
| Standard | S |
| Lusso | L |

| Suffissi | Carattere |
|---|---|
| Casa | * |
| Albergo | ^ |
| Giocatore | 1-4 |

Esempio tabellone vuoto:

       *1       2       3       4       5       6       7       8*

*A*   \|   \|   | L |   | L |   | E |   | S |   | S |   | S |   |   |

*B*   \| L \|                                                   | S |

*C*   \| S \|                                                   | E |

*D*   \| L \|                                                   | S |

*E*   \| S \|                                                   | E |

*F*   \| E \|                                                   | L |

*G*   \| E \|                                                   | E |

*H*   \|   \|   \| S \|   \| S \|   \| L \|   \| S \|   \| E \|   \| E \|   \| P \|
