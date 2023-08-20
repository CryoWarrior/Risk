#include "Comandos.h"
#include <string>
#include <iostream>

using namespace std;

void Comandos::inicializarJuego() {
    if (isGameInitialized) {
        cout << "(Juego en curso) El juego ya ha sido inicializado.\n";
    } else {
        // Realiza la inicializacion del juego aqui
        isGameInitialized = true;
        cout << "(Inicializacion satisfactoria) El juego se ha inicializado "
                     "correctamente.\n";
    }
}

void Comandos::turnoJugador(int jugadorId) {
    if (!isGameInitialized) {
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
                     "correctamente.\n";
    } else if (isGameOver) {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    } else if (jugadorId < 1 ||
               jugadorId > 4) { // Cambiar 4 al número maximo de jugadores
        cout << "(Jugador no valido) El jugador " << jugadorId
                  << " no forma parte de esta partida.\n";
    } else if (jugadorId != currentTurn) {
        cout << "(Jugador fuera de turno) No es el turno del jugador "
                  << jugadorId << ".\n";
    } else {
        // Realiza las acciones del turno aqui
        cout << "(Turno terminado correctamente) El turno del jugador "
                  << jugadorId << " ha terminado.\n";
        // Cambiar el turno al siguiente jugador 
        currentTurn = (currentTurn % 4) + 1;
    }
}

void Comandos::salirJuego() {
    isGameOver = true;
    cout << "El juego ha terminado. ¡Hasta luego!\n";
}

void Comandos::guardarEstadoJuego(const string &nombreArchivo) {
    if (!isGameInitialized) {
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
                     "correctamente.\n";
    } else if (isGameOver) {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    } else {

        bool guardo_bien = false;
        if(guardo_bien){

        } else {
            cout <<"(Error al guardar) La partida no ha sido guardada correctamente.\n";
        }
    }
}

void Comandos::guardarEstadoComprimido(const string &nombreArchivo) {
    if (!isGameInitialized) {
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
                     "correctamente.\n";
    } else if (isGameOver) {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    } else {

        bool guardo_archivo_binario = false;
        if(guardo_archivo_binario){

        } else {
            cout <<"(Error al codificar y/o guardar) La partida no ha sido codificada ni guardada correctamente.\n";
        }
    }
}

void Comandos::inicializar(string nombre_archivo) {}

string Comandos::costoConquista(const string &territorio,const vector<string> &territorios) {
    if (!isGameInitialized) {
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
                     "correctamente.\n";
    } else if (isGameOver) {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    } else {
        // Mostrar el mensaje con los valores calculados
        cout << "(Comando correcto) Para conquistar el territorio "
                  << territorio;

        if (!territorios.empty()) {
            cout << ", debe atacar desde " << territorios[0]
                      << ", pasando por los territorios ";

            for (size_t i = 1; i < territorios.size(); ++i) {
                cout << territorios[i];
                if (i < territorios.size() - 1) {
                    cout << ", ";
                }
            }
        }

        cout << ". Debe conquistar " << territorios.size()
                  << " unidades de ejercito.\n";
    }
}

string Comandos::conquistaMasBarata(const vector<string> &territorios) {
    if (!isGameInitialized) {
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
                     "correctamente.\n";
    } else if (isGameOver) {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    } else {
        // Mostrar el mensaje con los valores calculados
        cout <<"(Comando correcto) El territorio con menor costo de conquista es: \n";

        if (!territorios.empty()) {
            cout << ", debe avanzar sobre el territorio " << territorios[0]
                      << ", desde el territorio ";

            for (size_t i = 1; i < territorios.size(); ++i) {
                cout << territorios[i];
                if (i < territorios.size() - 1) {
                    cout << ", ";
                }
            }
        }
    }
};

bool Comandos::getIsGameInitialized() const {
    return isGameInitialized;
};

void Comandos::setIsGameInitialized(bool value) {
    isGameInitialized = value;
};

bool Comandos::getIsGameOver() const {
    return isGameOver;
};

void Comandos::setIsGameOver(bool value) {
    isGameOver = value;
};