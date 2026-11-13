#pragma once

#include "Mano.h"
#include "Carta.h"
#include "Mazo.h"


class Crupier {
private:
    Mano mano;

public:
    Crupier();

    void recibirCarta(Carta carta);
    void jugarTurno(Mazo& mazo);
    bool puedePedirCarta();
    Mano& getMano();
    int getPuntos();
};