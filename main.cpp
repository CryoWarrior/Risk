/*#include "comandos.h"*/
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(/*Risk &risk*/) {

    string command;
    string command2;
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
        command2 = tokens[1];

        if(tokens.size()==2){
            //things
        }

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
        } else if (command == "ayuda") {
            if(tokens.size()==1){
                cout<< "inicializar                         Inicia un juego si el juego no esta iniciado"<<endl;
                cout<< "inicializar <nombre_archivo>        Inicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo>"<<endl;
                cout<< "turno <id_jugador>                  Comienza el turno del jugador al que le toca"<<endl;
                cout<< "salir                               Termina la ejecucion de la aplicacion"<<endl;
                cout<< "guardar <nombre_archivo>            El estado actual del juego es guardado en un archivo de texto"<<endl;
                cout<< "guardar_comprimido <nombre_archivo> El estado actual del juego es guardado en un arhivo binario con la informacion comprimida"<<endl;
                cout<< "costo_conquista <territorio>        Calcula el costo y la secuencia de territorios a ser conquistados para lograr "
                       "controlar el territorio dado por el jugador actual."<<endl;
                cout<< "conquista_mas_barata                Calcula el territorio el cual implica una menor cantidad de unidades de ejericito perdidos del jugador actual"<<endl;
            }
        } else {
            if (command2 == "inicializar") {
                cout << "inicializar                         Inicia un juego si el juego no esta iniciado" << endl;
                cout << "inicializar <nombre_archivo>        Inicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo>" << endl;
            } else if (command2 == "turno") {
                cout << "turno <id_jugador>                  Comienza el turno del jugador al que le toca" << endl;
            } else if (command2 == "salir") {
                cout << "salir                               Termina la ejecucion de la aplicacion" << endl;
            } else if (command2 == "guardar") {
                cout << "guardar <nombre_archivo>            El estado actual del juego es guardado en un archivo de texto"<< endl;
            } else if (command2 == "guardar_comprimido") {
                cout << "guardar_comprimido <nombre_archivo> El estado actual del juego es guardado en un arhivo binario con la informacion comprimida"<< endl;
            } else if (command2 == "costo_conquista") {
                cout<< "costo_conquista <territorio>        Calcula el costo y la secuencia de territorios a ser conquistados para lograr "
                       "controlar el territorio dado por el jugador actual." << endl;
            } else if (command2 == "conquista_mas_barata") {
                cout<< "conquista_mas_barata                Calcula el territorio el cual implica una menor cantidad de unidades de ejericito "
                       "perdidos del jugador actual"<< endl;
            } else {
                cout << "No existe ningun comando con ese nombre"<<endl;
            }

        }
        cout << "Comando no reconocido, intente de nuevo. \n";

    } while (isRunning);
    return 1;
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