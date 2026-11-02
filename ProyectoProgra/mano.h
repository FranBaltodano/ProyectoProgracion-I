#pragma once

#include "Carta.h"
#include <vector>
using namespace std;

enum EstadoMano {
    ACTIVA,
    PLANTADA,
    PERDIDA
};

class Mano {
private:
    vector<Carta> cartas;
    double apuesta;
    EstadoMano estado;

public:
    Mano();

    void agregarCarta(Carta carta);
    int calcularPuntos();
    bool esBlackjack();
    bool sePaso();
    bool estaPlantada();

    void setApuesta(double monto);
    double getApuesta();

    void setEstado(EstadoMano nuevoEstado);
}; #pragma once
