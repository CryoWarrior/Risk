#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Declaraciones de funciones
bool isGameInitialized = false;
bool isGameOver = false;
int currentTurn = 1; // id del jugador con el turno actual
void inicializarJuego();
void turnoJugador(int jugadorId);
void salirJuego();
void guardarEstadoJuego(const string &nombreArchivo);
void guardarEstadoComprimido(const string &nombreArchivo);
void costoConquista(const string &territorio,
                    const vector<string> &territorios);
void conquistaMasBarata(const vector<string> &territorios);

int main() {
    string command;
    bool isRunning = true;

    do {
        // Imprimir el indicador de linea de comando
        cout << "$ ";

        // Leer la entrada del usuario
        getline(cin, command);

        if(command != "") {

            vector<string> tokens;
            istringstream iss(command);
            string s;

            while (iss >> s) {
                tokens.push_back(s);
            }

            string commandName = tokens[0];

            if (commandName == "inicializar") {
                inicializarJuego();
            } else if (commandName == "turno") {

                if (tokens.size() >= 2) {
                    int jugadorId = stoi(tokens[1]);
                    turnoJugador(jugadorId);
                } else {
                    cout << "Falta el <id_jugador>.\n";
                }
            } else if (commandName == "salir") {
                salirJuego();
                isRunning = false;
            } else if (commandName == "guardar") {
                if (tokens.size() >= 2) {
                    guardarEstadoJuego(tokens[1]);
                } else {
                    cout << "Falta el <nombre_archivo>.\n";
                }
            } else if (commandName == "guardar_comprimido") {
                if (tokens.size() >= 2) {
                    guardarEstadoComprimido(tokens[1]);
                } else {
                    cout << "Falta el <nombre_archivo>.\n";
                }
            } else if (commandName == "costo_conquista") {
                if (tokens.size() >= 2) { // Verificar que haya un territorio
                    vector<string> territoriosNecesarios;

                    for (size_t i = 2; i < tokens.size(); ++i) {
                        territoriosNecesarios.push_back(tokens[i]);
                    }
                    costoConquista(tokens[1], territoriosNecesarios);
                } else {
                    cout << "Comando costo_conquista requiere un territorio.\n";
                }
            } else if (commandName == "conquista_mas_barata") {
                vector<string> territorios(0);
                // TO DO: Logica

                conquistaMasBarata(territorios);
            } else if (commandName == "ayuda") {
                if (tokens.size() == 1) {
                    if (!isGameInitialized) {
                        cout << "inicializar                         Inicia un juego si el juego no esta iniciado"
                             << endl;
                        cout
                                << "inicializar <nombre_archivo>        Inicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo>"
                                << endl;
                        cout << "salir                               Termina la ejecucion de la aplicacion" << endl;
                    } else {
                        cout << "turno <id_jugador>                  Comienza el turno del jugador actual" << endl;
                        cout << "salir                               Termina la ejecucion de la aplicacion" << endl;
                        cout
                                << "guardar <nombre_archivo>            El estado actual del juego es guardado en un archivo de texto"
                                << endl;
                        cout
                                << "guardar_comprimido <nombre_archivo> El estado actual del juego es guardado en un arhivo binario con la informacion comprimida"
                                << endl;
                        cout
                                << "costo_conquista <territorio>        Calcula el costo y la secuencia de territorios a ser conquistados para lograr "
                                   "controlar el territorio dado por el jugador actual." << endl;
                        cout
                                << "conquista_mas_barata                Calcula el territorio el cual implica una menor cantidad de unidades de ejericito perdidos del jugador actual"
                                << endl;
                    }
                } else if (tokens.size() == 2) {
                    if (tokens[1] == "inicializar") {
                        cout << "inicializar                         Inicia un juego si el juego no esta iniciado"
                             << endl;
                        cout
                                << "inicializar <nombre_archivo>        Inicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo>,"
                                   "el juego debe no haber sido iniciado"
                                << endl;
                    } else if (tokens[1] == "turno") {
                        cout
                                << "turno <id_jugador>                  Comienza el turno del jugador actual al dar su id correspondiente <id_jugador>"
                                << endl;
                    } else if (tokens[1] == "salir") {
                        cout << "salir                               Termina la ejecucion de la aplicacion" << endl;
                    } else if (tokens[1] == "guardar") {
                        cout
                                << "guardar <nombre_archivo>            El estado actual del juego es guardado en un archivo de texto que tiene como nombre <nombre_archivo>"
                                << endl;
                    } else if (tokens[1] == "guardar_comprimido") {
                        cout
                                << "guardar_comprimido <nombre_archivo> El estado actual del juego es guardado en un arhivo binario con la informacion comprimida, qeu tiene"
                                   "como nombre <nombre_archivo>"
                                << endl;
                    } else if (tokens[1] == "costo_conquista") {
                        cout
                                << "costo_conquista <territorio>        Calcula el costo y la secuencia de territorios a ser conquistados para lograr "
                                   "controlar el territorio <territorio> dado por el jugador actual." << endl;
                    } else if (tokens[1] == "conquista_mas_barata") {
                        cout
                                << "conquista_mas_barata                Calcula el territorio el cual implica una menor cantidad de unidades de ejericito "
                                   "perdidos del jugador actual" << endl;
                    } else {
                        cout << "No existe ningun comando con ese nombre" << endl;
                    }
                } else {
                    cout << "Comando no reconocido, intente de nuevo. \n";
                }
            } else {
                cout << "Comando no reconocido, intente de nuevo. \n";
            }
        }

    } while (isRunning);
    return 0;
}



// Implementa las funciones correspondientes a cada comando
void inicializarJuego() {
    if (isGameInitialized) {
        cout << "(Juego en curso) El juego ya ha sido inicializado.\n";
    } else {
        // Realiza la inicializacion del juego aqui
        isGameInitialized = true;
        cout << "(Inicializacion satisfactoria) El juego se ha inicializado "
                     "correctamente.\n";
    }
}

void turnoJugador(int jugadorId) {
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
        // Cambiar el turno al siguiente jugador (ejemplo: ciclo entre 1, 2, 3, 4)
        currentTurn = (currentTurn % 4) + 1;
    }
}

void salirJuego() {
    isGameOver = true;
    cout << "El juego ha terminado. ¡Hasta luego!\n";
}

void guardarEstadoJuego(const string &nombreArchivo) {
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

void guardarEstadoComprimido(const string &nombreArchivo) {
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

void costoConquista(const string &territorio,
                    const vector<string> &territorios) {
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

void conquistaMasBarata( const vector<string> &territorios) {
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
}
