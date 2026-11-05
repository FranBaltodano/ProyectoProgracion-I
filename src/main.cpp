#include <iostream>
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"

using namespace std;

void mostrarCarta(Carta carta) {
    cout << carta.getValor() << " de " << carta.getPalo() << endl;
}

// Juega una mano del jugador. Devuelve -1 si el jugador decide salir.
int jugarMano(Jugador& jugador, Mazo& mazo, int i) {

    while (true) {

        // Se vuelve a pedir la referencia en cada vuelta porque dividir agrega manos
        Mano& mano = jugador.getManos()[i];

        cout << "\n--- Mano " << i + 1 << " ---" << endl;
        cout << "Puntos: " << mano.calcularPuntos() << endl;

        if (mano.sePaso()) {
            cout << "Te pasaste de 21 en esta mano." << endl;
            return 0;
        }

        if (mano.calcularPuntos() == 21) {
            cout << "21!" << endl;
            jugador.plantarse(i);
            return 0;
        }

        if (mano.estaPlantada()) {
            return 0;
        }

        cout << "1. Pedir carta" << endl;
        cout << "2. Plantarse" << endl;
        cout << "3. Doblar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";

        int opcion;
        cin >> opcion;

        switch (opcion) {

        case 1: {
            Carta carta = mazo.repartirCarta();
            jugador.pedirCarta(i, carta);
            cout << "Recibes: ";
            mostrarCarta(carta);
            break;
        }

        case 2:
            jugador.plantarse(i);
            return 0;

        case 3: {
            Carta carta = mazo.repartirCarta();
            jugador.doblar(i, carta);
            cout << "Doblas y recibes: ";
            mostrarCarta(carta);
            jugador.plantarse(i);
            return 0;
        }

        case 4:
            if (jugador.dividir(i)) {
                cout << "Mano dividida! Ahora juegas 2 manos." << endl;

                // Una carta nueva para cada mano
                Carta c1 = mazo.repartirCarta();
                jugador.pedirCarta(i, c1);
                cout << "Mano " << i + 1 << " recibe: ";
                mostrarCarta(c1);

                Carta c2 = mazo.repartirCarta();
                jugador.pedirCarta(1, c2);
                cout << "Mano 2 recibe: ";
                mostrarCarta(c2);
            }
            else {
                cout << "No puedes dividir esta mano." << endl;
            }
            break;

        case 5:
            cout << "Saliendo del juego..." << endl;
            return -1;

        default:
            cout << "Opcion invalida." << endl;
        }
    }
}

int main() {

    Mazo mazo;
    Jugador jugador(1000);
    Crupier crupier;

    cout << "Bienvenido al juego de Blackjack!" << endl;

    // Cartas iniciales del jugador
    for (int i = 0; i < 2; i++) {
        Carta carta = mazo.repartirCarta();
        jugador.pedirCarta(0, carta);
        cout << "Recibes: ";
        mostrarCarta(carta);
    }

    // Cartas del crupier
    Carta visible = mazo.repartirCarta();
    crupier.recibirCarta(visible);
    cout << "El crupier muestra: ";
    mostrarCarta(visible);
    crupier.recibirCarta(mazo.repartirCarta()); // carta oculta

    // Blackjack de entrada
    if (jugador.getManos()[0].esBlackjack()) {
        cout << "\nBLACKJACK! Ganaste "
            << jugador.getManos()[0].getApuesta() * 1.5 << endl;
        return 0;
    }

    // Turno del jugador: juega cada mano en orden (si dividio, son 2)
    for (int i = 0; i < jugador.getManos().size(); i++) {
        if (jugarMano(jugador, mazo, i) == -1) {
            return 0;
        }
    }

    int totalManos = jugador.getManos().size();

    // Si solo hay una mano y llego a 21, gana de una vez
    if (totalManos == 1 && jugador.getManos()[0].calcularPuntos() == 21) {
        cout << "\n21! Ganaste " << jugador.getManos()[0].getApuesta() << endl;
        return 0;
    }

    // Revisar si todas las manos se pasaron
    bool algunaViva = false;
    for (int i = 0; i < totalManos; i++) {
        if (!jugador.getManos()[i].sePaso()) {
            algunaViva = true;
        }
    }

    if (!algunaViva) {
        cout << "\nTe pasaste en todas tus manos. Perdiste!" << endl;
        return 0;
    }

    // Turno del crupier
    cout << "\n===== TURNO DEL CRUPIER =====" << endl;
    crupier.jugarTurno(mazo);
    int puntosCrupier = crupier.getMano().calcularPuntos();
    cout << "Crupier tiene " << puntosCrupier << " puntos." << endl;

    // Resultado de cada mano
    cout << "\n===== RESULTADOS =====" << endl;
    for (int i = 0; i < totalManos; i++) {

        Mano& mano = jugador.getManos()[i];
        int puntos = mano.calcularPuntos();

        cout << "Mano " << i + 1 << " (" << puntos << " puntos): ";

        if (mano.sePaso()) {
            cout << "Te pasaste. Perdiste " << mano.getApuesta() << endl;
        }
        else if (crupier.getMano().sePaso() || puntos > puntosCrupier) {
            cout << "Ganaste " << mano.getApuesta() << endl;
        }
        else if (puntos < puntosCrupier) {
            cout << "Perdiste " << mano.getApuesta() << endl;
        }
        else {
            cout << "Empate. Recuperas tu apuesta." << endl;
        }
    }

    return 0;
}