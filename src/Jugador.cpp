#include "Jugador.h"

Jugador::Jugador(double apuestaInicial) {
    apuesta = apuestaInicial;
    manos.push_back(Mano()); // Inicia con una mano por defecto
}

void Jugador::pedirCarta(int indiceMano, Carta nuevaCarta) {
    if (indiceMano >= 0 && indiceMano < manos.size()) {
        manos[indiceMano].agregarCarta(nuevaCarta);
    }
}

void Jugador::plantarse(int indiceMano) {
    // Lógica básica de turno finalizado para esta mano
}

void Jugador::doblar(int indiceMano, Carta nuevaCarta) {
    apuesta *= 2;
    pedirCarta(indiceMano, nuevaCarta);
}

bool Jugador::dividir(int indiceMano) {
    if (indiceMano >= 0 && indiceMano < manos.size()) {
        if (manos[indiceMano].puedeDividirse()) {
            Mano nuevaMano;
            manos.push_back(nuevaMano);
            return true;
        }
    }
    return false;
}

std::vector<Mano>& Jugador::getManos() {
    return manos;
}

double Jugador::getApuesta() const {
    return apuesta;
}

void Jugador::setApuesta(double nuevaApuesta) {
    apuesta = nuevaApuesta;
}
