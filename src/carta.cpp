
#include "Carta.h"

Carta::Carta(string valor, string palo) {
    this->valor = valor;
    this->palo = palo;
}

int Carta::obtenerValor() {

    if (valor == "A") {
        return 11;
    }
    else if (valor == "J" || valor == "Q" || valor == "K") {
        return 10;
    }
    else {
        return stoi(valor);
    }
}

string Carta::getValor() {
    return valor;
}

string Carta::getPalo() {
    return palo;
}