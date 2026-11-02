
#pragma once
#include "Carta.h"
#include <vector>
using namespace std;

class Baraja {
private:
    vector<Carta> cartas;

public:
    void crearBarajas();
    void barajar();
    Carta repartirCarta();
    int cartasRestantes();
};
#pragma once
