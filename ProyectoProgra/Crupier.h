#ifndef CRUPIER_H
#define CRUPIER_H

#include "Mano.h"
#include "Mazo.h"

class Crupier {
private:
    Mano mano;

public:
    Crupier();
    void jugarTurno(Mazo& mazo);
    bool puedePedirCarta();
    Mano getMano();
};

#endif
