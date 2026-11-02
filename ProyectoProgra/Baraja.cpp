
#include "Baraja.h"
#include <algorithm>
#include <random>
#include <stdexcept>

void Baraja::crearBarajas() {

    cartas.clear();

    string valores[] = {
        "A", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "J", "Q", "K"
    };

    string palos[] = {
        "Corazones", "Diamantes", "Treboles", "Picas"
    };

    // Crear 6 mazos
    for (int mazo = 0; mazo < 6; mazo++) {

        for (int i = 0; i < 13; i++) {

            for (int j = 0; j < 4; j++) {

                Carta nuevaCarta(valores[i], palos[j]);

                cartas.push_back(nuevaCarta);
            }
        }
    }
}

void Baraja::barajar() {

    random_device rd;
    mt19937 generador(rd());

    shuffle(cartas.begin(), cartas.end(), generador);
}

Carta Baraja::repartirCarta() {

    if (cartas.empty()) {
        throw runtime_error("No quedan cartas en la baraja");
    }

    Carta carta = cartas.back();

    cartas.pop_back();

    return carta;
}

int Baraja::cartasRestantes() {
    return cartas.size();
}
