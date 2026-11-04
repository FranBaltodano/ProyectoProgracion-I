#include <iostream>
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"

using namespace std;

int main() {

    Mazo mazo;
    Jugador jugador(1000);
    Crupier crupier;

    int opcion = 0;

    cout << "Bienvenido al juego de Blackjack!" << endl;

    // Repartir cartas iniciales al jugador
    jugador.pedirCarta(0, mazo.repartirCarta());
    jugador.pedirCarta(0, mazo.repartirCarta());

    // Repartir dos cartas al crupier
    crupier.recibirCarta(mazo.repartirCarta());
    crupier.recibirCarta(mazo.repartirCarta());

    // Turno del jugador
    do {

        cout << "\nTu mano tiene "
            << jugador.getManos()[0].calcularPuntos()
            << " puntos." << endl;

        if (jugador.getManos()[0].esBlackjack()) {
            cout << "Blackjack!" << endl;
            break;
        }

        if (jugador.getManos()[0].sePaso()) {
            cout << "Te pasaste de 21!" << endl;
            break;
        }

        cout << "\n1. Pedir carta" << endl;
        cout << "2. Plantarse" << endl;
        cout << "3. Doblar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Salir" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            jugador.pedirCarta(0, mazo.repartirCarta());
            break;

        case 2:
            jugador.plantarse(0);
            break;

        case 3:
            jugador.doblar(0, mazo.repartirCarta());
            break;

        case 4:
            if (jugador.dividir(0)) {
                cout << "Mano dividida!" << endl;
                cout << "La opcion de jugar ambas manos requiere completar su turno." << endl;
                jugador.plantarse(0);
            }
            else {
                cout << "No puedes dividir esta mano." << endl;
            }
            break;

        case 5:
            cout << "Saliendo del juego..." << endl;
            return 0;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while (!jugador.getManos()[0].sePaso()
        && !jugador.getManos()[0].estaPlantada());

    // Turno del crupier
    if (!jugador.getManos()[0].sePaso()) {

        cout << "\n===== TURNO DEL CRUPIER =====" << endl;

        crupier.jugarTurno(mazo);

        // Mostrar resultados
        cout << "Crupier tiene "
            << crupier.getMano().calcularPuntos()
            << " puntos." << endl;

        cout << "Tu mano tiene "
            << jugador.getManos()[0].calcularPuntos()
            << " puntos." << endl;

        if (crupier.getMano().sePaso()) {
            cout << "El crupier se paso! Ganaste!" << endl;
        }
        else if (jugador.getManos()[0].calcularPuntos() >
            crupier.getMano().calcularPuntos()) {
            cout << "Ganaste!" << endl;
        }
        else if (jugador.getManos()[0].calcularPuntos() <
            crupier.getMano().calcularPuntos()) {
            cout << "Perdiste!" << endl;
        }
        else {
            cout << "Empate!" << endl;
        }
    }
    else {
        cout << "Te pasaste de 21. Perdiste!" << endl;
    }

    return 0;
}
