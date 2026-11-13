#pragma once
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"
#include <string>
class Juego {
private:
    Mazo mazo;
    Jugador jugador;
    Crupier crupier;
    double saldo;
    double apuesta;
    double seguro;

    int leerEnteroValido(int min, int max, std::string mensaje);
    bool esAs(Carta c);
    void mostrarManos();
    bool jugarMano(int i);
    double pedirApuesta();
    bool ofrecerSeguro(Carta visible);
    void resolverBlackjackInicial(bool bjJ, bool bjC, bool quiereSeguro);
    void jugarTurnoCrupier();
    void resolverResultados();

public:
    Juego();
    void jugar();
};
