#include "Jugador.h"

Jugador::Jugador(double apuestaInicial) {
    apuesta = apuestaInicial;
    Mano primera;
    primera.setApuesta(apuestaInicial);
    manos.push_back(primera);
}

void Jugador::pedirCarta(int indiceMano, Carta nuevaCarta) {
    if (indiceMano >= 0 && indiceMano < manos.size()) {
        manos[indiceMano].agregarCarta(nuevaCarta);
    }
}

void Jugador::plantarse(int indiceMano) {
    if (indiceMano >= 0 && indiceMano < manos.size()) {
        manos[indiceMano].setEstado(PLANTADA);
    }
}

void Jugador::doblar(int indiceMano, Carta nuevaCarta) {
    if (indiceMano >= 0 && indiceMano < manos.size()) {
        manos[indiceMano].setApuesta(manos[indiceMano].getApuesta() * 2);
        pedirCarta(indiceMano, nuevaCarta);
    }
}

// Separa las dos cartas iguales en dos manos (maximo 2 manos)
bool Jugador::dividir(int indiceMano) {
    if (manos.size() >= 2) {
        return false;
    }
    if (indiceMano >= 0 && indiceMano < manos.size()) {
        if (manos[indiceMano].puedeDividirse()) {
            Carta movida = manos[indiceMano].quitarUltimaCarta();
            Mano nueva;
            nueva.agregarCarta(movida);
            nueva.setApuesta(manos[indiceMano].getApuesta());
            manos.push_back(nueva);
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