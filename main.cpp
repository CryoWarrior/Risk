#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include "Comandos.h"
#include "Risk.h"

using namespace std;

int main() {

    Risk risk = Risk();
    Comandos comandos;


    string command;
    bool isRunning = true;

    cout << "Digite 'ayuda', para conocer los comandos que puede ejecutar\n";
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
                comandos.inicializarJuego(risk);
            } else if (commandName == "turno") {

                if (tokens.size() >= 2) {
                    int jugadorId = stoi(tokens[1]);
                    comandos.turnoJugador(jugadorId, risk);
                } else {
                    cout << "Falta el <id_jugador>.\n";
                }
            } else if (commandName == "salir") {
                comandos.salirJuego(risk);
                isRunning = false;
            } else if (commandName == "guardar") {
                if (tokens.size() >= 2) {
                    comandos.guardarEstadoJuego(risk, tokens[1]);
                } else {
                    cout << "Falta el <nombre_archivo>.\n";
                }
            } else if (commandName == "guardar_comprimido") {
                if (tokens.size() >= 2) {
                    comandos.guardarEstadoComprimido(risk, tokens[1]);
                } else {
                    cout << "Falta el <nombre_archivo>.\n";
                }
            } else if (commandName == "costo_conquista") {
                if (tokens.size() >= 2) { // Verificar que haya un territorio
                    vector<string> territoriosNecesarios;

                    for (size_t i = 2; i < tokens.size(); ++i) {
                        territoriosNecesarios.push_back(tokens[i]);
                    }
                    comandos.costoConquista(risk, tokens[1], territoriosNecesarios);
                } else {
                    cout << "Comando costo_conquista requiere un territorio.\n";
                }
            } else if (commandName == "conquista_mas_barata") {
                vector<string> territorios(0);

                comandos.conquistaMasBarata(risk, territorios);
            } else if (commandName == "ayuda") {
                if (tokens.size() == 1) {
                    if (!risk.isGameInitialized1()) {
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
