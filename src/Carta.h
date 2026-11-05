
#pragma once
#include <string>
using namespace std;

class Carta {
private:
    string valor;
    string palo;

public:
    Carta(string valor, string palo);

    int obtenerValor();
    string getValor();
    string getPalo();
};
