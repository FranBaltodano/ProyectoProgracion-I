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
    Carta quitarUltimaCarta();
    int calcularPuntos();
    int valor();
    bool esBlackjack();
    bool sePaso();
    bool estaPlantada();
    bool puedeDividirse();

    void setApuesta(double monto);
    double getApuesta();

    void setEstado(EstadoMano nuevoEstado);
};