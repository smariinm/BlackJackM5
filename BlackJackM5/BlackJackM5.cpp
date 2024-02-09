#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int valor_carta(int valor) {
    if (valor >= 2 && valor <= 10) {
        return valor;
    }
    else if (valor >= 11 && valor <= 13) {
        return 10;
    }
    else if (valor == 1) {
        int as_valor;
        cout << "¿Quieres que el As valga 1 u 11? ";
        cin >> as_valor;
        return as_valor;
    }
    return 0;
}


int repartir_carta() {
    return rand() % 13 + 1;
}


string obtener_palo(int carta) {
    int palo = (carta - 1) % 4;
    switch (palo) {
    case 0:
        return "Picas";
    case 1:
        return "Rombos";
    case 2:
        return "Treboles";
    case 3:
        return "Corazones";
    default:
        return "Desconocido";
    }
}


void mostrar_mano(int carta1, int carta2) {
    cout << "Cartas del jugador: ";
    if (carta1 >= 2 && carta1 <= 10) {
        cout << carta1;
    }
    else if (carta1 == 11) {
        cout << "J";
    }
    else if (carta1 == 12) {
        cout << "Q";
    }
    else if (carta1 == 13) {
        cout << "K";
    }
    else {
        cout << "A";
    }
    cout << " de " << obtener_palo(carta1) << " y ";

    if (carta2 >= 2 && carta2 <= 10) {
        cout << carta2;
    }
    else if (carta2 == 11) {
        cout << "J";
    }
    else if (carta2 == 12) {
        cout << "Q";
    }
    else if (carta2 == 13) {
        cout << "K";
    }
    else {
        cout << "A";
    }
    cout << " de " << obtener_palo(carta2) << endl;
}

int main() {
    srand(time(nullptr));


    int carta1_jugador = repartir_carta();
    int carta2_jugador = repartir_carta();

    mostrar_mano(carta1_jugador, carta2_jugador);


    int puntuacion_jugador = valor_carta(carta1_jugador) + valor_carta(carta2_jugador);

    cout << "Puntuacion del jugador: " << puntuacion_jugador << endl;


    if (puntuacion_jugador == 21) {
        cout << "Blackjack, Ganaste" << endl;
        return 0;
    }


    char opcion;
    cout << "Quieres otra carta? (s/n): ";
    cin >> opcion;


    while (opcion == 's') {

        int nueva_carta = repartir_carta();
        cout << "Nueva carta del jugador: ";
        if (nueva_carta >= 2 && nueva_carta <= 10) {
            cout << nueva_carta;
        }
        else if (nueva_carta == 11) {
            cout << "J";
        }
        else if (nueva_carta == 12) {
            cout << "Q";
        }
        else if (nueva_carta == 13) {
            cout << "K";
        }
        else {
            cout << "A";
        }
        cout << " de " << obtener_palo(nueva_carta) << endl;

        puntuacion_jugador += valor_carta(nueva_carta);
        cout << "Puntuacion del jugador: " << puntuacion_jugador << endl;

        if (puntuacion_jugador > 21) {
            cout << "Te has pasado de 21. ¡Croupier gana!" << endl;
            return 0;
        }

        cout << "Quieres otra carta? (s/n): ";
        cin >> opcion;
    }

    cout << "El jugador ha decidido parar." << endl;

    int carta_crupier = repartir_carta();
    cout << "Carta del crupier: ";
    if (carta_crupier >= 2 && carta_crupier <= 10) {
        cout << carta_crupier;
    }
    else if (carta_crupier == 11) {
        cout << "J";
    }
    else if (carta_crupier == 12) {
        cout << "Q";
    }
    else if (carta_crupier == 13) {
        cout << "K";
    }
    else {
        cout << "A";
    }
    cout << " de " << obtener_palo(carta_crupier) << endl;

    int puntuacion_crupier = valor_carta(carta_crupier);

    cout << "Puntuacion del crupier: " << puntuacion_crupier << endl;

    if (puntuacion_jugador > puntuacion_crupier || puntuacion_crupier > 21) {
        cout << "Ganaste" << endl;
    }
    else if (puntuacion_jugador < puntuacion_crupier) {
        cout << "Croupier gana." << endl;
    }
    else {
        cout << "Empate." << endl;
    }

    return 0;
}
