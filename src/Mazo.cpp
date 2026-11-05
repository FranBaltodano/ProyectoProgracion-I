#include "Mazo.h"
#include <algorithm>
#include <random>

using namespace std;

Mazo::Mazo() {
    siguiente = 0;
    construirBaraja();
}

void Mazo::construirBaraja() {

    cartas.clear();
    siguiente = 0;

    string palos[4] = { "Corazones", "Diamantes", "Treboles", "Picas" };
    string valores[13] = { "A", "2", "3", "4", "5", "6", "7",
                           "8", "9", "10", "J", "Q", "K" };

    for (int p = 0; p < 4; p++) {
        for (int v = 0; v < 13; v++) {
            Carta nuevaCarta(valores[v], palos[p]);
            cartas.push_back(nuevaCarta);
        }
    }

    // Barajar (para probar dividir, comenta estas 3 lineas)
    random_device rd;
    mt19937 generador(rd());
    shuffle(cartas.begin(), cartas.end(), generador);
}

Carta Mazo::repartirCarta() {

    if (zapatoAgotado()) {
        return cartas[0];
    }

    Carta carta = cartas[siguiente];
    siguiente++;

    return carta;
}

bool Mazo::zapatoAgotado() {
    return siguiente >= cartas.size();
}