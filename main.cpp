#include "comandos.h"
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void comandosDisponibles(/*Risk &risk*/) {

    string command;
    bool isRunning = true;
    do {
        // Imprimir el indicador de línea de comando
        cout << "$ ";

        // Leer la entrada del usuario
        getline(cin, command);

        vector<string> tokens;

        istringstream iss(command);
        string s;
        while (iss >> s) {
            tokens.push_back(s);
        }
        command = tokens[0];

        if (command == "inicializar") {
            // Implementar la lógica para inicializar el juego
        } else if (command == "turno <id_jugador>") {
            // Implementar la lógica para el turno de un jugador
        } else if (command == "salir") {
            // Implementar la lógica para salir del juego
            isRunning = false;
        } else if (command == "guardar <nombre_archivo>") {
            // Implementar la lógica para guardar el estado del juego en un archivo de texto
        } else if (command == "guardar_comprimido <nombre_archivo>") {
            // Implementar la lógica para guardar el estado del juego en un archivo binario comprimido
        } else if (command == "costo_conquista <territorio>") {
            // Implementar la lógica para calcular el costo y la secuencia de territorios para conquistar un territorio
        } else if (command == "conquista_mas_barata") {
            // Implementar la lógica para calcular la conquista más barata
        } else {
            cout << "Comando no reconocido, intente de nuevo. \n";
        }

    } while (isRunning);
}

/*
#include <iostream>

using namespace std;

int main() {

    //Variables
    string comando;

    while(true){

        //Ejecucion del programa
        cout<<"$";
        getline(cin, comando);

        Switch:
            case(trorpa)

        std::cout << "Hello, World!" << std::endl;

        if(comando == "fin")
            break;
    }
    return 0;
}
*/