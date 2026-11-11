#include <iostream>
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"

using namespace std;

// Muestra todas las manos del jugador (si dividio, salen las 2)
void mostrarManos(Jugador& jugador) {
    cout << "\n--- TUS MANOS ---" << endl;
    for (int i = 0; i < jugador.getManos().size(); i++) {
        cout << "Mano " << i + 1 << ": ";
        jugador.getManos()[i].mostrar();
    }
}

// Juega una mano. Devuelve true si el jugador quiere salir.
bool jugarMano(Jugador& jugador, Mazo& mazo, int i) {
    while (true) {
        Mano& mano = jugador.getManos()[i];   // se pide en cada vuelta porque dividir agrega manos

        mostrarManos(jugador);
        cout << "Jugando mano " << i + 1 << endl;

        if (mano.sePaso()) {
            cout << "Te pasaste de 21!" << endl;
            return false;
        }
        if (mano.calcularPuntos() == 21) {
            return false;
        }

        cout << "1.Pedir  2.Plantarse  3.Doblar  4.Dividir  5.Salir: ";
        int opcion = 0;
        if (!(cin >> opcion)) {               // si escribe una letra, limpiamos el error
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (opcion == 1) {
            jugador.pedirCarta(i, mazo.repartirCarta());
        }
        else if (opcion == 2) {
            jugador.plantarse(i);
            return false;
        }
        else if (opcion == 3) {
            jugador.doblar(i, mazo.repartirCarta());
            return false;
        }
        else if (opcion == 4) {
            if (jugador.dividir(i)) {         // cada mano recibe una carta nueva
                jugador.pedirCarta(0, mazo.repartirCarta());
                jugador.pedirCarta(1, mazo.repartirCarta());
            }
            else {
                cout << "No se puede dividir: necesitas 2 cartas iguales." << endl;
            }
        }
        else if (opcion == 5) {
            return true;
        }
        else {
            cout << "Opcion invalida." << endl;
        }
    }
}

int main() {
    Mazo mazo;
    Jugador jugador(1000);
    Crupier crupier;

    // Reparto inicial
    jugador.pedirCarta(0, mazo.repartirCarta());
    jugador.pedirCarta(0, mazo.repartirCarta());
    Carta visible = mazo.repartirCarta();
    crupier.recibirCarta(visible);
    crupier.recibirCarta(mazo.repartirCarta());   // carta oculta
    cout << "El crupier muestra: " << visible.getValor() << " de " << visible.getPalo() << endl;

    // Blackjack de entrada
    if (jugador.getManos()[0].esBlackjack()) {
        mostrarManos(jugador);
        cout << "BLACKJACK! Ganaste " << jugador.getManos()[0].getApuesta() * 1.5 << endl;
        return 0;
    }

    // Turno del jugador (si dividio, juega las 2 manos en orden)
    for (int i = 0; i < jugador.getManos().size(); i++) {
        if (jugarMano(jugador, mazo, i)) {
            return 0;
        }
    }

    // Turno del crupier
    crupier.jugarTurno(mazo);
    cout << "\nCrupier: ";
    crupier.getMano().mostrar();

    // Resultados
    mostrarManos(jugador);
    cout << "\n--- RESULTADOS ---" << endl;
    int puntosCrupier = crupier.getMano().calcularPuntos();
    for (int i = 0; i < jugador.getManos().size(); i++) {
        Mano& mano = jugador.getManos()[i];
        int puntos = mano.calcularPuntos();
        cout << "Mano " << i + 1 << ": ";

        if (mano.sePaso()) {
            cout << "Perdiste " << mano.getApuesta() << endl;
        }
        else if (crupier.getMano().sePaso() || puntos > puntosCrupier) {
            cout << "Ganaste " << mano.getApuesta() << endl;
        }
        else if (puntos < puntosCrupier) {
            cout << "Perdiste " << mano.getApuesta() << endl;
        }
        else {
            cout << "Empate." << endl;
        }
    }

    return 0;
}