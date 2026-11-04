#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include "Mano.h"
#include "Carta.h"

class Jugador {
private:
    std::vector<Mano> manos;
    double apuesta;

public:
    Jugador(double apuestaInicial);
    void pedirCarta(int indiceMano, Carta nuevaCarta);
    void plantarse(int indiceMano);
    void doblar(int indiceMano, Carta nuevaCarta);
    bool dividir(int indiceMano);

    // Getters y Setters
    std::vector<Mano>& getManos();
    double getApuesta() const;
    void setApuesta(double nuevaApuesta);
};

#endif
