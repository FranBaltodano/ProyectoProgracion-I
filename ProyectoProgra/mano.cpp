#include "Mano.h"

Mano::Mano() {
    apuesta = 0;
    estado = ACTIVA;
}

void Mano::agregarCarta(Carta carta) {
    cartas.push_back(carta);
}

int Mano::calcularPuntos() {

    int total = 0;
    int ases = 0;

    for (int i = 0; i < cartas.size(); i++) {

        total += cartas[i].obtenerValor();

        if (cartas[i].getValor() == "A") {
            ases++;
        }
    }

    // Cambiar los Ases de 11 a 1 si es necesario
    while (total > 21 && ases > 0) {
        total -= 10;
        ases--;
    }

    return total;
}

bool Mano::esBlackjack() {

    return cartas.size() == 2 && calcularPuntos() == 21;
}

bool Mano::sePaso() {

    return calcularPuntos() > 21;
}

bool Mano::estaPlantada() {

    return estado == PLANTADA;
}

void Mano::setApuesta(double monto) {
    apuesta = monto;
}

double Mano::getApuesta() {
    return apuesta;
}

void Mano::setEstado(EstadoMano nuevoEstado) {
    estado = nuevoEstado;
}