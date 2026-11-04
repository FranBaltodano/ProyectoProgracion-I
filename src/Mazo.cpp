

#include "Mazo.h"

using namespace std;

// Constructor
Mazo::Mazo() {
    siguiente = 0;
    construirBaraja();
}

// Crear las cartas del mazo
void Mazo::construirBaraja() {

    cartas.clear();
    siguiente = 0;

    // Crear las cartas de los 4 palos
    for (int palo = 0; palo < 4; palo++) {

        for (int valor = 1; valor <= 13; valor++) {

            Carta nuevaCarta((Palo)palo, valor);

            cartas.push_back(nuevaCarta);
        }
    }
}

// Repartir una carta
Carta Mazo::repartirCarta() {

    if (zapatoAgotado()) {
        return cartas[0];
    }

    Carta carta = cartas[siguiente];

    siguiente++;

    return carta;
}

// Revisar si se acabaron las cartas
bool Mazo::zapatoAgotado() {

    if (siguiente >= cartas.size()) {
        return true;
    }
    else {
        return false;
    }
}
