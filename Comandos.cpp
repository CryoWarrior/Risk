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

void Comandos::turnoJugador(int jugadorId, Risk& risk) {
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
    int nuevasUnidades = obtenerNuevasUnidades(jugadorActual);
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
    for(Territorio& t: jugadorActual.getTerritoriosOcupados()){
        if(SterritorioAtacante==t.getNombre()){
            territorioAtacante = t;
            condicional = false;
            break;
        }
    }
    if(condicional){
        std::cout<<"Este territorio no existe o no es suyo\n";
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
    for (const string &territorio : territoriosColindantes) {
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

// Elegir de tropas para atacar:

    //Cuenta disponibilidad de tropas
    int contInfanteria = 0;
    int contCaballeria = 0;
    int contArtilleria = 0;

    for(Tropa tropa: territorioAtacante.getTropas()){
        if(tropa.getTipoTropa() == "Infanteria"){
            contInfanteria++;
        }else if(tropa.getTipoTropa() == "Caballeria"){
            contCaballeria++;
        }else if(tropa.getTipoTropa() == "Artilleria"){
            contArtilleria++;
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
        std::cout <<"Con cuantas tropas de infanteria quieres atacar: ";
        std::cin >> infanteriaAtaque;
        if(infanteriaAtaque > contInfanteria|| artilleriaAtaque < 0){
            std::cout<<"No tienes esa cantidad de unidades de infanteria\n";
            condicional = true;
        } else{
            condicional = false;
        }
    }while (condicional);


    do{
        std::cout <<"Con cuantas tropas de caballeria quieres atacar: ";
        std::cin >> caballeriaAtaque;
        if(caballeriaAtaque > contCaballeria|| artilleriaAtaque < 0){
            std::cout<<"No tienes esa cantidad de unidades de caballeria\n";
            condicional = true;
        } else{
            condicional = false;
        }
    }while (condicional);

    do{
        std::cout <<"Con cuantas tropas de artilleria quieres atacar: ";
        std::cin >> artilleriaAtaque;
        if(artilleriaAtaque > contArtilleria || artilleriaAtaque < 0){
            std::cout<<"No tienes esa cantidad de unidades de artilleria\n";
            condicional = true;
        } else{
            condicional = false;
        }
    }while (condicional);



    //Quitar las tropas del pais atacante y se almacenan en el vector tropas atacantes
    int contQuitarInfanteria = infanteriaAtaque;
    int contQuitarCaballeria = caballeriaAtaque;
    int contQuitarArtilleria = artilleriaAtaque;

    vector<Tropa> tropasAtacantes;
    std::vector<Tropa>::iterator iterador;

    for(iterador = territorioAtacante.getTropas().begin(); iterador != territorioAtacante.getTropas().end();){
        if(iterador->getTipoTropa() == "Infanteria"){
            if(contQuitarInfanteria > 0){
                tropasAtacantes.push_back(*iterador);
                iterador = territorioAtacante.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }else if(iterador->getTipoTropa() == "Caballeria"){
            if(contQuitarCaballeria > 0){
                tropasAtacantes.push_back(*iterador);
                iterador = territorioAtacante.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }else if(iterador->getTipoTropa() == "Artilleria"){
            if(contQuitarArtilleria > 0){
                tropasAtacantes.push_back(*iterador);
                iterador = territorioAtacante.getTropas().erase(iterador);
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

    //ADicionalemente de calcular el valor contamos la cantidad de tropas actuales para mas tarde
    int valorDefensor = 0;

    int infanteriaDefensa = 0;
    int caballeriaDefensa = 0;
    int artilleriaDefensa = 0;

    for(Tropa tropa: territorioDefensor.getTropas()){
        if(tropa.getTipoTropa() == "Infanteria"){
            valorDefensor += 1;
            infanteriaDefensa++;
        }else if(tropa.getTipoTropa() == "Caballeria"){
            valorDefensor += 5;
            caballeriaDefensa++;
        }else if(tropa.getTipoTropa() == "Artilleria"){
            valorDefensor += 10;
            artilleriaDefensa++;
        }
    }


    int valorPerdidoAtacantes = 0;
    int valorPerdidoDefensores = 0;
    condicional = true;
    while(condicional){
        // Simular lanzamiento de dados y determinar resultados
        vector<int> resultadosAtacante = lanzarDados(dadosAtacante);
        vector<int> resultadosDefensor = lanzarDados(dadosDefensor);

        // Calcular pérdidas de unidades para atacante y defensor (Ataque se devuelve en [1] y defensa en [0]
        vector<int> perdidas = calcularPerdidas(resultadosAtacante, resultadosDefensor);
        valorPerdidoDefensores += perdidas[0];
        valorPerdidoAtacantes += perdidas[1];

        // Actualizar valor de tropas de la batalla (Provisional)
        valorDefensor - perdidas[0];
        valorAtacante - perdidas[1];

        //Comprobar si la batalla esta terminada y Ajustar el estado actual de la partida dependiendo del resultado de la partida
        if(valorAtacante <= 0 || valorDefensor <= 0){
            if(valorAtacante <= 0 && valorDefensor <= 0){
                territorioDefensor.setTropas(new list<Tropa>);
            } else if(valorAtacante <= 0){
                cout<<"No lograste conquistar el territorio\n";
                eliminarPerdidas(territorioDefensor, infanteriaDefensa, caballeriaDefensa, artilleriaDefensa, valorPerdidoDefensores);
            } else if(valorDefensor <= 0){
                cout<<"Lograste controlar el territorio, felicitaciones :)\n";
                jugadorActual.getTerritoriosOcupados().push_back(territorioDefensor);
                auto it = territorioDefensor.getTropas().begin();
                string color = it->color();
                eliminarPropiedadConColor(risk, color, territorioDefensor.getNombre()); //Eliminar el pais de la lista del defensor

                territorioDefensor.setTropas(tropasAtacantes);
                eliminarPerdidas(territorioDefensor, infanteriaAtaque, caballeriaAtaque, artilleriaAtaque, valorPerdidoAtacantes);

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

    fortificarPosicion(jugadorActual, risk);

    // Cambiar el turno al siguiente jugador
    currentTurn = (currentTurn % 4) + 1;
    cout << "Turno del jugador " << currentTurn << ".\n";

    // Cambiar el turno al siguiente jugador
    currentTurn = (currentTurn % totalPlayers) + 1;
    cout << "Turno del jugador " << currentTurn << ".\n";
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

int Comandos::obtenerNuevasUnidades(Jugador jugador) {
    int nuevasUnidades = 0;

    // Obtener la cantidad de territorios ocupados por el jugador
    int cantidadTerritoriosOcupados = jugador.getTerritoriosOcupados().size();

    // Calcular las unidades basadas en territorios ocupados
    nuevasUnidades += cantidadTerritoriosOcupados / 3;

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

void Comandos::eliminarPerdidas(Territorio& territorio, int infanteria, int caballaria, int artilleria, int valorPerdido){
    //Organizar tropas
    for(auto iterador = territorio.getTropas().begin(); iterador != territorio.getTropas().end();){
        if(iterador->getTipoTropa() == "Infanteria"){
            if(valorPerdido > 0){
                iterador = territorio.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }else if(iterador->getTipoTropa() == "Caballeria"){
            if(valorPerdido >= 5){
                iterador = territorio.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }else if(iterador->getTipoTropa() == "Artilleria"){
            if(valorPerdido >= 10){
                iterador = territorio.getTropas().erase(iterador);
            }
            else{
                iterador++;
            }
        }
    }
}

void Comandos::eliminarPropiedadConColor(Risk& risk,const string& color, string nombreTerritorio){
    for(Jugador jugador:risk.getListaJugadores()){
        if(jugador.getColor()== color){
            for(auto iterador = jugador.getTerritoriosOcupados().begin();
            iterador != jugador.getTerritoriosOcupados().end();iterador++) {
                if(nombreTerritorio == iterador->getNombre()){
                    jugador.getTerritoriosOcupados().erase(iterador);
                    break;
            }
            }
        }
    }
}


void Comandos::fortificarPosicion(Jugador& jugadorActual, Risk& risk) {
    bool condicional;

    // Mostrar los territorios del jugador
    cout << "Territorios del jugador " << jugadorActual.getNombre() << ": ";
    for (const Territorio& territorio : jugadorActual.getTerritoriosOcupados()) {
        cout << territorio.getNombre() << " ";
    }
    cout << "\n";


//Seleccionar territorios y número de unidades para la fortificación

    string SterritorioOrigen, SterritorioDestino;
    Territorio territorioOrigen, territorioDestino;

    cout << "Selecciona el territorio desde el que deseas trasladar unidades: ";
    cin >> SterritorioOrigen;


//Obtener territorio origen
    condicional = true;
    do{
        cout << "Selecciona el territorio desde el que se ataca: ";
        cin >> SterritorioOrigen;
        for(Territorio& t: jugadorActual.getTerritoriosOcupados()){
            if(SterritorioOrigen==t.getNombre()){
                territorioOrigen = t;
                condicional = false;
                break;
            }
        }
        if(condicional){
            std::cout<<"Este territorio no es suyo\n";
        }
    }while (condicional);


//Obtener territorio destino

    // Mostrar territorios colindantes
    cout << "Territorios a los que puede trasladar " << jugadorActual.getNombre() << ": ";
    for (const Territorio &territorio : territorioOrigen.getTerritoriosColindantes()) {
        cout << territorio.getNombre() << " ";
    }
    cout << "\n";

    condicional = true;
    do{
        cout << "Selecciona el territorio para trasladar las tropas: ";
        cin >> SterritorioDestino;
        for(Territorio& t: territorioOrigen.getTerritoriosColindantes()){
            if(SterritorioDestino==t.getNombre()){
                territorioDestino = t;
                condicional = false;
                break;
            }
        }
        if(condicional){
            std::cout<<"Este territorio no colinda con su territorio atacante\n";
        }
    }while (condicional);

//Trasladar tropas

// Elegir cantidad de tropas para atacar:

    //Cuenta disponibilidad de tropas
    int contInfanteria = 0;
    int contCaballeria = 0;
    int contArtilleria = 0;

    for(Tropa tropa: territorioOrigen.getTropas()){
        if(tropa.getTipoTropa() == "Infanteria"){
            contInfanteria++;
        }else if(tropa.getTipoTropa() == "Caballeria"){
            contCaballeria++;
        }else if(tropa.getTipoTropa() == "Artilleria"){
            contArtilleria++;
        }else cout << " ñóñáñáíóú \"Hay tipos de tropa no valida :(\"\n";
    }

    //Imprime tropas disponibles
    std::cout << "Tropas que puedes mover:\n";
    std::cout << "Infanteria: "<<contInfanteria<<endl;
    std::cout << "Caballeria: "<<contCaballeria<<endl;
    std::cout << "Artilleria: "<<contArtilleria<<endl;

    //Pregunta por las tropas que quiere mover
    int unidadesInfanteria;
    int unidadesCaballeria;
    int unidadesArtilleria;

    do{
        std::cout <<"Cuantas tropas de infanteria quieres mover: ";
        std::cin >> unidadesInfanteria;
        if(unidadesInfanteria > contInfanteria || unidadesInfanteria < 0){
            std::cout<<"No tienes esa cantidad de unidades de infanteria\n";
            condicional = true;
        } else{
            condicional = false;
        }
    }while (condicional);


    do{
        std::cout <<"Cuantas tropas de caballeria quieres mover: ";
        std::cin >> unidadesCaballeria;
        if(unidadesCaballeria > contCaballeria|| unidadesCaballeria < 0){
            std::cout<<"No tienes esa cantidad de unidades de caballeria\n";
            condicional = true;
        } else{
            condicional = false;
        }
    }while (condicional);

    do{
        std::cout <<"Cuantas tropas de artilleria quieres mover: ";
        std::cin >> unidadesArtilleria;
        if(unidadesArtilleria > contArtilleria || unidadesArtilleria < 0){
            std::cout<<"No tienes esa cantidad de unidades de artilleria\n";
            condicional = true;
        } else{
            condicional = false;
        }
    }while (condicional);


    //Quitar las tropas del pais origen y se almacenan en el vector tropas apoyo y contar valor de fortificacion
    int contQuitarInfanteria = unidadesInfanteria;
    int contQuitarCaballeria = unidadesCaballeria;
    int contQuitarArtilleria = unidadesArtilleria;

    int unidadesFortificacion = 0;

    vector<Tropa> tropasApoyo;
    std::vector<Tropa>::iterator iterador;

    for(iterador = territorioOrigen.getTropas().begin(); iterador != territorioOrigen.getTropas().end();){
        if(iterador->getTipoTropa() == "Infanteria"){
            if(contQuitarInfanteria > 0){
                tropasApoyo.push_back(*iterador);
                iterador = territorioOrigen.getTropas().erase(iterador);
                unidadesFortificacion ++;
            }
            else{
                iterador++;
            }
        }else if(iterador->getTipoTropa() == "Caballeria"){
            if(contQuitarCaballeria > 0){
                tropasApoyo.push_back(*iterador);
                iterador = territorioOrigen.getTropas().erase(iterador);
                unidadesFortificacion += 5;
            }
            else{
                iterador++;
            }
        }else if(iterador->getTipoTropa() == "Artilleria"){
            if(contQuitarArtilleria > 0){
                tropasApoyo.push_back(*iterador);
                iterador = territorioOrigen.getTropas().erase(iterador);
                unidadesFortificacion += 10;
            }
            else{
                iterador++;
            }
        }
    }

    //Agregar las tropas al destino
    for(Tropa& tropa: tropasApoyo){
        territorioDestino.getTropas().push_back(tropa);
    }

    cout << "Se han trasladado " << unidadesFortificacion << " unidades desde "
         << territorioOrigen.getNombre() << " a " << territorioDestino.getNombre() << ".\n";
}

