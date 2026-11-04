#include "Crupier.h"

Crupier::Crupier() {
    // La mano inicia vacía
}

bool Crupier::puedePedirCarta() {
    // Regla clásica de Blackjack: el crupier pide si tiene menos de 17
    return mano.valor() < 17;
}

void Crupier::jugarTurno(Mazo& mazo) {
    while (puedePedirCarta()) {
        Carta c = mazo.repartirCarta();
        mano.agregarCarta(c);
    }
}

Mano Crupier::getMano() {
    return mano;
}
