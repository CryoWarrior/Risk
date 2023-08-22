#include "Comandos.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

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

void Comandos::turnoJugador(int jugadorId, Risk risk) {
    bool condicional = false;

    //Encontrar usuario y verificar si es valido
    Jugador jugadorActual;
    for(const Jugador& jugadorX: risk.getListaJugadores()){
        if(jugadorId == jugadorX.getIdJugador()){
            jugadorActual = jugadorX;
            condicional = true;
            break;
        }
    }
    if(!condicional){
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


//Elegir territorio de ataque ---------------

    // Obtener nombres territorio del jugador
    vector<string> territoriosJugador;
    for(const Territorio& t: jugadorActual.getTerritoriosOcupados()){
        territoriosJugador.push_back(t.getNombre());
    }

    // Mostrar territorios del jugador
    cout << "Territorios del jugador " << jugadorId << ": ";
    for (const string &territorio : territoriosJugador) {
        cout << territorio << " ";
    }
    cout << "\n";


    // Territorio atacante
    condicional = true;
    Territorio territorioAtacante;
    string SterritorioAtacante;

    do{
    cout << "Selecciona el territorio desde el que se ataca: ";
    cin >> SterritorioAtacante;
    for(Territorio& t: risk.getListaTerritorios()){
        if(SterritorioAtacante==t.getNombre()){
            territorioAtacante = t;
            condicional = false;
            break;
        }
    }
    if(condicional){
        std::cout<<"Este territorio no existe\n";
    }
    }while (condicional);


//Elegir territorio para atacar --------------

    // Obtener nombres territorio del jugador
    vector<string> territoriosColindantes;
    for(const Territorio& t: territorioAtacante.getTerritoriosColindantes()){
        territoriosColindantes.push_back(t.getNombre());
    }

    // Mostrar territorios colindantes
    cout << "Territorios que puede atacar " << jugadorId << ": ";
    for (const string &territorio : territoriosJugador) {
        cout << territorio << " ";
    }
    cout << "\n";

    // Territorio defensor

    condicional = true;
    Territorio territorioDefensor;
    string SterritorioDefensor;

    do{
        cout << "Selecciona el territorio a atacar: ";
        cin >> SterritorioDefensor;
        for(Territorio& t: territorioAtacante.getTerritoriosColindantes()){
            if(SterritorioDefensor==t.getNombre()){
                territorioDefensor = t;
                condicional = false;
                break;
            }
        }
        if(condicional){
            std::cout<<"Este territorio no colinda con su territorio atacante\n";
        }
    }while (condicional);

// Elegir cantidad de tropas para atacar:

    //Cuenta disponibilidad de tropas
    int contInfanteria = 0;
    int contCaballeria = 0;
    int contArtilleria = 0;

    for(Tropa tropa: territorioAtacante.getTropas()){
        if(tropa.getTipoTropa() == "Infanteria"){

        }else if(tropa.getTipoTropa() == "Caballeria"){

        }else if(tropa.getTipoTropa() == "Artilleria"){

        }else cout << " ñóñáñáíóú \"Hay tipos de tropa no valida :(\"\n";
    }

    //Imprime tropas disponibles
    std::cout << "Tropas con las que puedes atacar:\n";
    std::cout << "Infanteria: "<<contInfanteria<<endl;
    std::cout << "Caballeria: "<<contCaballeria<<endl;
    std::cout << "Artilleria: "<<contArtilleria<<endl;

    //Pregunta por las tropas que quiere atacar
    int infanteriaAtaque;
    int caballeriaAtaque;
    int artilleriaAtaque;

    do{
        std::cout <<"Cuantas tropas de infanteria quieres atacar: ";
        std::cin >> infanteriaAtaque;
        if(infanteriaAtaque > contInfanteria|| artilleriaAtaque < 0){
            std::cout<<"No tienes esa cantidad de unidades de infanteria\n";
            condicional = true;
        } else{
            condicional = false;
        }
    }while (condicional);


    do{
        std::cout <<"Cuantas tropas de caballeria quieres atacar: ";
        std::cin >> caballeriaAtaque;
        if(caballeriaAtaque > contCaballeria|| artilleriaAtaque < 0){
            std::cout<<"No tienes esa cantidad de unidades de caballeria\n";
            condicional = true;
        } else{
            condicional = false;
        }
    }while (condicional);

    do{
        std::cout <<"Cuantas tropas de artilleria quieres atacar: ";
        std::cin >> artilleriaAtaque;
        if(artilleriaAtaque > contArtilleria || artilleriaAtaque < 0){
            std::cout<<"No tienes esa cantidad de unidades de artilleria\n";
            condicional = true;
        } else{
            condicional = false;
        }
    }while (condicional);

    int contQuitarInfanteria = infanteriaAtaque;
    int contQuitarCaballeria = caballeriaAtaque;
    int contQuitarArtilleria = artilleriaAtaque;

    //Quitar las tropas del pais atacante
    std::vector<Tropa>::iterator iterador;

    for(iterador = territorioAtacante.getTropas().begin(); iterador != territorioAtacante.getTropas().end();){
        if(iterador->getTipoTropa() == "Infanteria"){
            if(contQuitarInfanteria > 0){
                territorioAtacante.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }else if(iterador->getTipoTropa() == "Caballeria"){
            if(contQuitarCaballeria > 0){
                territorioAtacante.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }else if(iterador->setTipoTropa() == "Artilleria"){
            if(contQuitarArtilleria > 0){
                territorioAtacante.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }
    }


// Número de dados para atacante y defensor (Dados por el enunciado)
    int dadosAtacante = 3;
    int dadosDefensor = 2;

// Ciclo de conquista
    condicional = true;

    //Cacular valor de tropas (En medidas de infateria) iniciales
    int valorAtacante = 0;
    valorAtacante += infanteriaAtaque;
    valorAtacante += 5 * caballeriaAtaque;
    valorAtacante += 10 * artilleriaAtaque;

    int valorDefensor = 0;
    for(Tropa tropa: territorioDefensor.getTropas()){
        if(tropa.getTipoTropa() == "Infanteria"){
            valorDefensor += 1;
        }else if(tropa.getTipoTropa() == "Caballeria"){
            valorDefensor += 5;
        }else if(tropa.getTipoTropa() == "Artilleria"){
            valorDefensor += 10;
        }
    }


    condicional = true;
    while(condicional){
        // Simular lanzamiento de dados y determinar resultados
        vector<int> resultadosAtacante = lanzarDados(dadosAtacante);
        vector<int> resultadosDefensor = lanzarDados(dadosDefensor);

        // Calcular pérdidas de unidades para atacante y defensor (Ataque se devuelve en [1] y defensa en [0]
        vector<int> perdidas = calcularPerdidas(resultadosAtacante, resultadosDefensor);

        // Actualizar valor de tropas de la batalla (Provisional)
        valorDefensor - perdidas[0];
        valorAtacante - perdidas[1];

        //Comprobar si la batalla esta terminada y Ajustar el estado actual de la partida dependiendo del resultado de la partida
        if(valorAtacante <= 0 || valorDefensor <= 0){
            if(valorAtacante <= 0 && valorDefensor <= 0){
                territorioDefensor.setTropas(new list<Tropa>);
            } else if(valorAtacante <= 0){
                cout<<"No lograste conquistar el territorio\n";

            } else if(valorDefensor <= 0){
                cout<<"Lograste controlar el territorio, felicitaciones :)\n";
            }

            condicional = false;
        }
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


vector<int> Comandos::lanzarDados(int cantidad){
    vector<int> resultados;
    //Poner los resultados en el vector
    std::srand(std::time(nullptr));
    for(int i=0; i< cantidad;i++){
        resultados.push_back((std::rand() % 6) + 1);
    }

    //Ordenar los resultados de mayor a menor
    int aux;
    for(int i=0; i<cantidad; i++){
        for(int j=0; j<cantidad; j++){
            if(resultados[i]<resultados[j]){
                aux = resultados[j];
                resultados[j]=resultados[i];
                resultados[i] = aux;
            }
        }
    }

    return resultados;
}

vector<int> Comandos::calcularPerdidas(const vector<int>& resultadosA, const vector<int>& resultadosD) {
    int perdidasA = 0;
    int perdidasD = 0;

    //Calcula la cantidad de dados a comparar
    int menorCantidad;
    if(resultadosD.size() <= resultadosA.size()){
        menorCantidad = resultadosD.size();
    }else menorCantidad = resultadosA.size();

    for(int i=0; i<menorCantidad; i++){
        if(resultadosD[i] >= resultadosA[i]){
            perdidasA++;
        }
        else perdidasD++;
    }

    //El vector de vuelta devuelve primero las perdidas del defensor y luego las del atacante
    vector<int> perdidas;
    perdidas.push_back(perdidasD);
    perdidas.push_back(perdidasA);

    return perdidas;
}

void Comandos::eliminarPerdidas(Territorio& territorio, int infanteria, int caballaria, int artilleria, int valorPerido){
    //Organizar tropas
    for(iterador = territorioAtacante.getTropas().begin(); iterador != territorioAtacante.getTropas().end();){
        if(iterador->getTipoTropa() == "Infanteria"){
            if(contQuitarInfanteria > 0){
                territorioAtacante.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }else if(iterador->getTipoTropa() == "Caballeria"){
            if(contQuitarCaballeria > 0){
                territorioAtacante.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }else if(iterador->setTipoTropa() == "Artilleria"){
            if(contQuitarArtilleria > 0){
                territorioAtacante.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }
    }
}


// SERA QUE SI IMPLEMENTAMOS ESTA FUNCION?????????????????????

vector<string> Comandos::obtenerTerritoriosJugador(int jugadorId, const vector<string> &territorios) {
    vector<string> territoriosJugador;
/*
    for (const auto &territorio : territorios) {
        int propietario = obtenerPropietarioTerritorio(territorio); // Implementar esta función
        if (propietario == jugadorId) {
            territoriosJugador.push_back(territorio);
        }
    }
*/
    return territoriosJugador;
}



