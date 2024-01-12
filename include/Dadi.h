// Autore: Chellin Davide
// ------------------------------
#ifndef DADI_H
#define DADI_H

class Dadi {

private:
  int numeroFacce;
  int sommaDadiLanciati;

public:
  Dadi();
  Dadi(int numeroFacceDado);

  int tiraDadi(int numeroDadi);
};

#endif // DADI_H
