
#pragma once

#include <vector>
#include "Carta.h"

using namespace std;

class Mazo {

private:
    vector<Carta> cartas;
    int siguiente;

public:
    Mazo();

    void construirBaraja();
    Carta repartirCarta();
    bool zapatoAgotado();

};