#include "Crupier.h"

Crupier::Crupier() {
}

void Crupier::recibirCarta(Carta carta) {
    mano.agregarCarta(carta);
}

bool Crupier::puedePedirCarta() {
    return mano.calcularPuntos() < 17;
}

// El crupier pide carta hasta llegar a 17 o mas
void Crupier::jugarTurno(Mazo& mazo) {
    while (puedePedirCarta() && !mazo.zapatoAgotado()) {
        mano.agregarCarta(mazo.repartirCarta());
    }
}

Mano& Crupier::getMano() {
    return mano;
}

int Crupier::getPuntos() {
    return mano.calcularPuntos();
}