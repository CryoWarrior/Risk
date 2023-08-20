#include "Comandos.h"
#include <string>
#include <iostream>
#include <cstdlib>

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
   // Verificar si el jugador es válido
    if (jugadorId < 1 || jugadorId > 4) {
        cout << "(Jugador no válido) El jugador " << jugadorId << " no forma parte de esta partida.\n";
        return;
    }

    // Verificar si es el turno del jugador
    if (jugadorId != currentTurn) {
        cout << "(Jugador fuera de turno) No es el turno del jugador " << jugadorId << ".\n";
        return;
    }

    cout << "Es el turno del jugador " << jugadorId << ".\n";

    // Obtener nuevas unidades para el jugador
    int nuevasUnidades = obtenerNuevasUnidades(jugadorId);
    cout << "El jugador " << jugadorId << " ha obtenido " << nuevasUnidades << " nuevas unidades.\n";

    // Atacar territorios y realizar las operaciones necesarias
    string territorioAtacante, territorioDefensor;
    int unidadesAtaque;

    cout << "Ingrese el nombre del territorio atacante: ";
    cin >> territorioAtacante;

    cout << "Ingrese el nombre del territorio defensor: ";
    cin >> territorioDefensor;

    cout << "Ingrese la cantidad de unidades para el ataque: ";
    cin >> unidadesAtaque;

   
// Obtener territorios del jugador
vector<string> territoriosJugador = obtenerTerritoriosJugador(jugadorId);

// Mostrar territorios del jugador
cout << "Territorios del jugador " << jugadorId << ": ";
for (const string &territorio : territoriosJugador) {
    cout << territorio << " ";
}
cout << "\n";

// Seleccionar territorio atacante
string territorioAtacante;
cout << "Selecciona el territorio para atacar: ";
cin >> territorioAtacante;

// Seleccionar territorio defensor
string territorioDefensor;
cout << "Selecciona el territorio a atacar: ";
cin >> territorioDefensor;

// Obtener número de dados para atacante y defensor (simplificado)
int dadosAtacante = 3;
int dadosDefensor = 2;

// Simular lanzamiento de dados y determinar resultados
vector<int> resultadosAtacante = lanzarDados(dadosAtacante);
vector<int> resultadosDefensor = lanzarDados(dadosDefensor);

// Calcular pérdidas de unidades para atacante y defensor
int perdidasAtacante = calcularPerdidas(resultadosAtacante, resultadosDefensor);
int perdidasDefensor = calcularPerdidas(resultadosDefensor, resultadosAtacante);

// Actualizar estado de los territorios (simplificado)
if (perdidasDefensor > 0) {
    // El defensor pierde unidades
    disminuirUnidades(territorioDefensor, perdidasDefensor);
} else {
    // El atacante conquista el territorio
    conquistarTerritorio(territorioDefensor, jugadorId);
    disminuirUnidades(territorioAtacante, perdidasAtacante);
}
    
    // Fortificar la posición del jugador
    string territorioOrigen, territorioDestino;
    int unidadesFortificacion;

    cout << "Ingrese el nombre del territorio de origen para la fortificación: ";
    cin >> territorioOrigen;

    cout << "Ingrese el nombre del territorio de destino para la fortificación: ";
    cin >> territorioDestino;

    cout << "Ingrese la cantidad de unidades para la fortificación: ";
    cin >> unidadesFortificacion;

    // Realizar la fortificación y actualizar el estado de los territorios
    // ...

    // Cambiar el turno al siguiente jugador
    currentTurn = (currentTurn % 4) + 1;
    cout << "Turno del jugador " << currentTurn << ".\n";
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

int Comandos::obtenerNuevasUnidades(int jugadorId) {
    int nuevasUnidades = 0;

    // Obtener la cantidad de territorios ocupados por el jugador
    int territoriosOcupados = obtenerCantidadTerritoriosOcupados(jugadorId);

    // Calcular las unidades basadas en territorios ocupados
    nuevasUnidades += territoriosOcupados / 3;

    // Calcular las unidades por continentes ocupados
    nuevasUnidades += obtenerUnidadesPorContinentes(jugadorId);

    // Calcular las unidades por cartas de territorios
    nuevasUnidades += obtenerUnidadesPorCartas(jugadorId);

    return nuevasUnidades;
}

vector<string> Comandos::obtenerTerritoriosJugador(int jugadorId, const vector<string> &territorios) {
    vector<string> territoriosJugador;

    for (const auto &territorio : territorios) {
        int propietario = obtenerPropietarioTerritorio(territorio); // Implementar esta función
        if (propietario == jugadorId) {
            territoriosJugador.push_back(territorio);
        }
    }

    return territoriosJugador;
}



