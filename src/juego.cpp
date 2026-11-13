#include "Juego.h"
#include <iostream>
using namespace std;
Juego::Juego() : jugador(0), saldo(1000), apuesta(0), seguro(0) {}
int Juego::leerEnteroValido(int min, int max, string mensaje) {
    int v = 0;
    while (true) {
        cout << mensaje;
        if (cin >> v && v >= min && v <= max) return v;
        cout << "Valor invalido. Debe ser entre " << min << " y " << max << "." << endl;
        cin.clear(); cin.ignore(1000, '\n');
    }
}
bool Juego::esAs(Carta c) { return c.getValor() == "A"; }
void Juego::mostrarManos() {
    cout << " TUS MANOS " << endl;
    for (int i = 0; i < (int)jugador.getManos().size(); i++) {
        cout << "Mano " << i + 1 << ": ";
        jugador.getManos()[i].mostrar();
    }
}
bool Juego::jugarMano(int i) {
    while (true) {
        Mano& mano = jugador.getManos()[i];
        mostrarManos();
        cout << "Jugando mano " << i + 1 << endl;
        if (mano.sePaso()) { cout << "Te pasaste de 21!" << endl; return false; }
        if (mano.calcularPuntos() == 21) return false;
        cout << "1.Pedir  2.Plantarse  3.Doblar  4.Dividir  5.Salir: ";
        int opcion = 0;
        if (!(cin >> opcion)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Opcion invalida." << endl; continue; }
        if (opcion == 1) jugador.pedirCarta(i, mazo.repartirCarta());
        else if (opcion == 2) { jugador.plantarse(i); return false; }
        else if (opcion == 3) {
            double apuestaMano = mano.getApuesta();
            if (saldo >= apuestaMano) { saldo -= apuestaMano; jugador.doblar(i, mazo.repartirCarta()); }
            else cout << "No tienes saldo para doblar." << endl;
            return false;
        }
        else if (opcion == 4) {
            double apuestaMano = mano.getApuesta();
            if (saldo < apuestaMano) { cout << "No tienes saldo para dividir." << endl; }
            else if (jugador.dividir(i)) {
                saldo -= apuestaMano;
                jugador.pedirCarta(0, mazo.repartirCarta());
                jugador.pedirCarta(1, mazo.repartirCarta());
            }
            else cout << "No se puede dividir: necesitas 2 cartas iguales." << endl;
        }
        else if (opcion == 5) return true;
        else cout << "Opcion invalida." << endl;
    }
}
double Juego::pedirApuesta() {
    int ap = leerEnteroValido(10, 500, "Cuanto quieres apostar? (10 a 500): ");
    while (ap > saldo) {
        cout << "No tienes saldo suficiente. Tu saldo es " << saldo << endl;
        ap = leerEnteroValido(10, 500, "Cuanto quieres apostar? (10 a 500): ");
    }
    saldo -= ap;
    jugador.setApuesta(ap);
    jugador.getManos()[0].setApuesta(ap);
    return ap;
}
bool Juego::ofrecerSeguro(Carta visible) {
    if (!esAs(visible)) return false;
    cout << "\nEl crupier muestra un As. Puedes pagar seguro (max " << apuesta / 2 << ")." << endl;
    cout << "1.Si  2.No: ";
    int op = 0;
    if (!(cin >> op)) { cin.clear(); cin.ignore(1000, '\n'); return false; }
    if (op == 1) {
        seguro = apuesta / 2;
        if (seguro > saldo) { cout << "No tienes saldo para el seguro." << endl; seguro = 0; return false; }
        saldo -= seguro;
        cout << "Pagaste " << seguro << " de seguro. Saldo: " << saldo << endl;
        return true;
    }
    return false;
}
void Juego::resolverBlackjackInicial(bool bjJ, bool bjC, bool quiereSeguro) {
    if (bjC) {
        cout << "\nCrupier: "; crupier.getMano().mostrar();
        cout << "El crupier tiene BLACKJACK!" << endl;
        if (quiereSeguro) { double pago = seguro * 2; saldo += seguro + pago; cout << "Ganas el seguro: +" << pago << endl; }
        if (bjJ) { cout << "Tu tambien tienes Blackjack. Empate. Se devuelve tu apuesta." << endl; saldo += apuesta; }
        else cout << "Perdiste tu apuesta de " << apuesta << endl;
        cout << "Saldo final: " << saldo << endl;
    }
    else {
        if (quiereSeguro) cout << "El crupier NO tiene Blackjack. Pierdes el seguro de " << seguro << endl;
        if (bjJ) {
            mostrarManos();
            double ganancia = apuesta * 1.5;
            saldo += apuesta + ganancia;
            cout << "BLACKJACK! Ganaste " << ganancia << ". Saldo final: " << saldo << endl;
        }
    }
}
void Juego::jugarTurnoCrupier() { crupier.jugarTurno(mazo); cout << "\nCrupier: "; crupier.getMano().mostrar(); }
void Juego::resolverResultados() {
    mostrarManos();
    cout << "\n--- RESULTADOS ---" << endl;
    int puntosCrupier = crupier.getMano().calcularPuntos();
    for (int i = 0; i < (int)jugador.getManos().size(); i++) {
        Mano& mano = jugador.getManos()[i];
        int puntos = mano.calcularPuntos();
        double apuestaMano = mano.getApuesta();
        cout << "Mano " << i + 1 << " (" << puntos << " puntos): ";
        if (mano.sePaso()) cout << "Perdiste " << apuestaMano << endl;
        else if (crupier.getMano().sePaso() || puntos > puntosCrupier) { cout << "Ganaste " << apuestaMano << endl; saldo += apuestaMano * 2; }
        else if (puntos < puntosCrupier) cout << "Perdiste " << apuestaMano << endl;
        else { cout << "Empate. Se devuelve tu apuesta de " << apuestaMano << endl; saldo += apuestaMano; }
    }
    cout << "Saldo final: " << saldo << endl;
}
void Juego::jugar() {
    cout << " BLACKJACK " << endl;
    cout << "Tu saldo: " << saldo << endl;
    apuesta = pedirApuesta();
    cout << "Apostaste " << apuesta << ". Saldo restante: " << saldo << endl;
    jugador.pedirCarta(0, mazo.repartirCarta());
    jugador.pedirCarta(0, mazo.repartirCarta());
    Carta visible = mazo.repartirCarta();
    crupier.recibirCarta(visible);
    crupier.recibirCarta(mazo.repartirCarta());
    cout << "El crupier muestra: " << visible.getValor() << " de " << visible.getPalo() << endl;
    bool quiereSeguro = ofrecerSeguro(visible);
    bool bjJ = jugador.getManos()[0].esBlackjack();
    bool bjC = crupier.getMano().esBlackjack();
    if (bjC || bjJ) { resolverBlackjackInicial(bjJ, bjC, quiereSeguro); return; }
    for (int i = 0; i < (int)jugador.getManos().size(); i++) {
        if (jugarMano(i)) { cout << "Saliste del juego. Saldo: " << saldo << endl; return; }
    }
    jugarTurnoCrupier();
    resolverResultados();
}