
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
int currentTurn = 1; //id del jugador con el turno actual
void inicializarJuego();
void turnoJugador(int jugadorId);
void salirJuego();
void guardarEstadoJuego(const std::string& nombreArchivo);
void guardarEstadoComprimido(const std::string& nombreArchivo);
void calcularCostoConquista(const std::string& territorio, const std::vector<std::string>& territorios);
void calcularConquistaMasBarata();

int main(/*Risk &risk*/) {

    string commandName;
    bool isRunning = true;
    do {
        // Imprimir el indicador de línea de comando
        cout << "$ ";

        // Leer la entrada del usuario
        getline(cin, commandName);

        vector<string> tokens;
        istringstream iss(commandName);
        string s;

        while (iss >> s) {
            tokens.push_back(s);
        }

        commandName= tokens[0];

        if (commandName == "inicializar") {
            inicializarJuego();
        } else if (commandName == "turno") {
            if (tokens.size() >= 2) {
                int jugadorId = std::stoi(tokens[1]);
                turnoJugador(jugadorId);
            } else {
                std::cout << "Falta el <id_jugador>.\n";
            }
        } else if (commandName == "salir") {
            salirJuego();
            isRunning = false;
        } else if (commandName == "guardar") {
            if (tokens.size() >= 2) {
                guardarEstadoJuego(tokens[1]);
            } else {
                std::cout << "Falta el <nombre_archivo>.\n";
            }
        } else if (commandName == "guardar_comprimido") {
            if (tokens.size() >= 2) {
                guardarEstadoComprimido(tokens[1]);
            } else {
                std::cout << "Falta el <nombre_archivo>.\n";
            }
        } else if (commandName == "costo_conquista") {
            if (tokens.size() >= 3) { // Verificar que haya al menos dos territorios
                std::vector<std::string> territoriosNecesarios;

                for (size_t i = 2; i < tokens.size(); ++i) {
                    territoriosNecesarios.push_back(tokens[i]);
                }

                calcularCostoConquista(tokens[1], territoriosNecesarios);
            } else {
                std::cout << "Comando costo_conquista requiere al menos 2 territorios.\n";
            }
        } else if (commandName == "conquista_mas_barata") {
            // Lógica para calcular la conquista más barata
        } else if (commandName== "ayuda") {
            if(tokens.size()==1){
                if(!isGameInitialized){
                    cout<< "inicializar                         Inicia un juego si el juego no esta iniciado"<<endl;
                    cout<< "inicializar <nombre_archivo>        Inicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo>"<<endl;
                }
                else{
                    cout<< "turno <id_jugador>                  Comienza el turno del jugador actual"<<endl;
                    cout<< "salir                               Termina la ejecucion de la aplicacion"<<endl;
                    cout<< "guardar <nombre_archivo>            El estado actual del juego es guardado en un archivo de texto"<<endl;
                    cout<< "guardar_comprimido <nombre_archivo> El estado actual del juego es guardado en un arhivo binario con la informacion comprimida"<<endl;
                    cout<< "costo_conquista <territorio>        Calcula el costo y la secuencia de territorios a ser conquistados para lograr "
                           "controlar el territorio dado por el jugador actual."<<endl;
                    cout<< "conquista_mas_barata                Calcula el territorio el cual implica una menor cantidad de unidades de ejericito perdidos del jugador actual"<<endl;
                }
            }
            else if(tokens.size() == 2) {
                if (tokens[1] == "inicializar") {
                    cout << "inicializar                         Inicia un juego si el juego no esta iniciado" << endl;
                    cout
                            << "inicializar <nombre_archivo>        Inicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo>,"
                               "el juego debe no haber sido iniciado"
                            << endl;
                } else if (tokens[1] == "turno") {
                    cout << "turno <id_jugador>                  Comienza el turno del jugador actual al dar su id correspondiente <id_jugador>" << endl;
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
            }
            else {
                cout << "Comando no reconocido, intente de nuevo. \n";
            }
        }else{
            cout << "Comando no reconocido, intente de nuevo. \n";
        }

    } while (isRunning);
    return 1;
}


// Implementa las funciones correspondientes a cada comando

// Implementa las funciones correspondientes a cada comando
void inicializarJuego() {
    if (isGameInitialized) {
        std::cout << "(Juego en curso) El juego ya ha sido inicializado.\n";
    } else {
        // Realiza la inicialización del juego aquí
        isGameInitialized = true;
        std::cout << "(Inicializacion satisfactoria) El juego se ha inicializado correctamente.\n";
    }
}

void turnoJugador(int jugadorId) {
    if (!isGameInitialized) {
        std::cout << "(Juego no inicializado) Esta partida no ha sido inicializada correctamente.\n";
    } else if (isGameOver) {
        std::cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    } else if (jugadorId < 1 || jugadorId > 4) { // Cambiar 4 al número máximo de jugadores
        std::cout << "(Jugador no valido) El jugador " << jugadorId << " no forma parte de esta partida.\n";
    } else if (jugadorId != currentTurn) {
        std::cout << "(Jugador fuera de turno) No es el turno del jugador " << jugadorId << ".\n";
    } else {
        // Realiza las acciones del turno aquí
        std::cout << "(Turno terminado correctamente) El turno del jugador " << jugadorId << " ha terminado.\n";
        // Cambiar el turno al siguiente jugador (ejemplo: ciclo entre 1, 2, 3, 4)
        currentTurn = (currentTurn % 4) + 1;
    }
}

void salirJuego() {
    isGameOver = true;
    std::cout << "El juego ha terminado. ¡Hasta luego!\n";
}


void guardarEstadoJuego(const std::string& nombreArchivo) {
    // Implementar la lógica para guardar el estado del juego en un archivo de texto
}

void guardarEstadoComprimido(const std::string& nombreArchivo) {
    // Implementar la lógica para guardar el estado del juego en un archivo binario comprimido
}

void calcularCostoConquista(const std::string& territorio, const std::vector<std::string>& territorios) {
    if (!isGameInitialized) {
        std::cout << "(Juego no inicializado) Esta partida no ha sido inicializada correctamente.\n";
    } else if (isGameOver) {
        std::cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    } else {
        // Mostrar el mensaje con los valores calculados
        std::cout << "(Comando correcto) Para conquistar el territorio " << territorio << ", debe atacar desde "
                  << territorios[0] << ", pasando por los territorios ";

        for (size_t i = 1; i < territorios.size(); ++i) {
            std::cout << territorios[i];
            if (i < territorios.size() - 1) {
                std::cout << ", ";
            }
        }

        std::cout << ". Debe conquistar " << territorios.size() << " unidades de ejército.\n";
    }
}



void calcularConquistaMasBarata() {
    // Implementar la lógica para calcular la conquista más barata
}
