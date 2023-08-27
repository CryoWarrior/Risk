#include "Comandos.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "algorithm"

using namespace std;

void Comandos::inicializarJuego(Risk &risk)
{
    if (risk.isGameInitialized1())
    {
        cout << "(Juego en curso) El juego ya ha sido inicializado.\n";
    }
    else
    {
        // Realiza la inicializacion del juego aqui

        risk.setIsGameInitialized(true);

        // Se incluyen todos los territorios, continentes, cartas y relaciones

        bool condicional = true;
        int cantidad_jugadores;
        std::vector<std::string> identificadores;
        std::vector<std::string> territorios_jugadores;

        std::string color;
        std::string nombre;

        std::cout << "Cantidad de jugadores: ";
        std::cin >> cantidad_jugadores;

        // Ver infanterias totales por jugadoor
        int infanteriaPorJugador;
        if (cantidad_jugadores == 3)
        {
            infanteriaPorJugador = 35;
        }
        else if (cantidad_jugadores == 4)
        {
            infanteriaPorJugador = 30;
        }
        else if (cantidad_jugadores == 5)
        {
            infanteriaPorJugador = 25;
        }
        else if (cantidad_jugadores == 6)
        {
            infanteriaPorJugador = 20;
        }
        else
        {
            cout << "Numero de jugadores no valido.\n";
            risk.setIsGameInitialized(false);
            return;
        }

        vector<string> coloresElegidos;
        bool colorRepetido = false;

        // Añadir jugadores a risk
        for (int i = 1; i <= cantidad_jugadores; i++)
        {
            std::cout << "Nombre del jugador (Una sola palabra) : ";
            std::cin >> nombre;

            condicional = true;
            colorRepetido = false;

            do
            {
                colorRepetido = false;
                std::cout << "Elija un color en minuscula (verde, azul, rojo, amarillo, negro o gris): ";
                std::cin >> color;

                for (const string &s : coloresElegidos)
                {
                    if (s == color)
                    {
                        colorRepetido = true;
                        break;
                    }
                }

                if ((color == "verde" || color == "azul" || color == "rojo" || color == "amarillo" || color == "negro" ||
                     color == "gris") &&
                    (!colorRepetido))
                {
                    condicional = false;
                    coloresElegidos.push_back(color);
                }
                else
                {
                    cout << "Color no valido o repetido\n";
                }
            } while (condicional);

            Jugador jugador;
            jugador.setColor(color);
            jugador.setNombre(nombre);
            jugador.setIdJugador(i);
            risk.getListaJugadores().push_back(jugador);
            cout<<nombre<<" fue agregado correctamente, RECUERDE!!! Su ID es: "<<i<<endl;
        }

        //Crea la lista de apuntadores territoriosDisponibles, los cuales referencias elementos de la lista original de paises
        list<Territorio*> territoriosDisponibles;

        for (auto territorio : risk.getListaTerritorios()) {
            territoriosDisponibles.push_back(territorio.get());
        }

        std::string territorioNombre;
        // Poner unidades en todos los territorios
        cout << "\n*************************FASE DE SELECCION DE TERRITORIOS******************************" << endl
             << endl;

        auto iterJugadorActual = risk.getListaJugadores().begin();
        while (!territoriosDisponibles.empty())
        {
            Jugador &jugadorActual = *iterJugadorActual;
            condicional = true;
            bool error = false;

            std::cout << "--------------Turno de " << jugadorActual.getNombre() << "--------------" << endl;

            // Imprimir territorios disponibles
            int contador = 0;
            cout << "Territorios disponibles: " << endl;
            for (Territorio* & territorio : territoriosDisponibles)
            {
                contador++;
                cout << contador << " " << territorio->getNombre() << endl;
            }

            int territorioNumero;
            cout << "Escriba el numero del territorio para ubicar una infanteria: ";
            std::cin >> territorioNumero;


            //covertir el numero que digita el usuario a un string (el nombre del pais que quiere el usuario)
            contador = 0;
            for(Territorio* &territorio : territoriosDisponibles)
            {
                contador ++;
                if (territorioNumero == contador )
                {
                    territorioNombre = territorio->getNombre();
                }

            }

            std::cout<<territorioNombre<<std::endl;

            // Encontar el territorio y asignarle las tropas
            auto iterTerritorio = territoriosDisponibles.begin();
            while (iterTerritorio != territoriosDisponibles.end())
            {
                if ((*iterTerritorio)->getNombre() == territorioNombre)
                {
                    Tropa infanteria("Infanteria", 1, jugadorActual.getColor());
                    (*iterTerritorio)->getTropas().push_back(infanteria);
                    jugadorActual.getTerritoriosOcupados().push_back(*iterTerritorio);
                    iterTerritorio = territoriosDisponibles.erase(iterTerritorio);
                    condicional = false;
                    cout << "Territorio concedido correctamente\n";
                    break;
                }
                ++iterTerritorio;
            }
            if (condicional)
            {
                cout << "Este territorio no existe o ya esta ocupado\n";
                error = true;
                --iterJugadorActual;
            }

            ++iterJugadorActual;
            if (iterJugadorActual == risk.getListaJugadores().end())
            {
                if (!error)
                {
                    infanteriaPorJugador--;
                }
                iterJugadorActual = risk.getListaJugadores().begin();
            }

            cout << "Presione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }

        int copiaInfanteriaPorJugador = infanteriaPorJugador;

        cout << "\n****************************FASE DE PONER INFANTERIA RESTANTE****************************" << endl
             << endl;
        // Poner las unidades restantes
        for (Jugador &jugador : risk.getListaJugadores())
        {
            while (infanteriaPorJugador > 0)
            {
                int cantidadTropas;
                std::cout << "--------------Turno de " << jugador.getNombre() << "--------------" << endl;

                // Imprimir territorios del jugador
                int contador = 0;
                cout << "Territorios disponibles: " << endl;
                for (Territorio* &territorio : jugador.getTerritoriosOcupados())
                {
                    contador++;
                    cout << " " << territorio->getNombre() << endl;
                }

                cout << "Ponga el nombre del territorio para ubicar la infanteria restante: ";
                std::cin >> territorioNombre;

                condicional = true;
                do
                {
                    cout << "Escriba la cantidad de infanteria que quiere ubicar, tiene " << infanteriaPorJugador << " unidades (En valor de infanteria) disponibles: ";

                    std::cin >> cantidadTropas;
                    if (cantidadTropas <= infanteriaPorJugador)
                    {
                        condicional = false;
                    }
                    else
                    {
                        cout << "No puede poner esa cantidad, tiene " << infanteriaPorJugador << " unidades (En valor de infanteria) disponibles\n";
                    }
                } while (condicional);

                condicional = true;
                for (Territorio* &territorio : jugador.getTerritoriosOcupados())
                {
                    if (territorio->getNombre() == territorioNombre)
                    {
                        Tropa infanteria("Infanteria", 1, jugador.getColor());
                        for (int i = 0; i < cantidadTropas; i++)
                        {
                            territorio->getTropas().push_back(infanteria);
                        }
                        infanteriaPorJugador -= cantidadTropas;
                        condicional = false;
                        cout << "Infanteria ubicada correctamente\n";
                        break;
                    }
                }
                if (condicional)
                {
                    cout << "Este territorio no existe o no pertenece al juagador\n";
                }

                cout << "Presione Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
            }
            infanteriaPorJugador = copiaInfanteriaPorJugador;
        }

        cout << "\n(Inicializacion satisfactoria) El juego se ha inicializado "
                "correctamente.\n";

        // Poner el ID del primer jugador:
        risk.setCurrentTurn(risk.getListaJugadores().front().getIdJugador());
        cout << "Turno del jugador " << risk.getListaJugadores().front().getNombre() << " ID: "<<
        risk.getListaJugadores().front().getIdJugador()<< endl;
    }
}

void Comandos::turnoJugador(int jugadorId, Risk &risk)
{
    bool condicional = false;

    if(!risk.isGameInitialized1()){
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada correctamente\n";
        return;
    }

    if(risk.isGameOver1()){
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
        return;
    }

    // Encontrar usuario y verificar si es valido
    Jugador* jugadorActual;
    for (Jugador &jugadorX : risk.getListaJugadores())
    {
        if (jugadorId == jugadorX.getIdJugador())
        {
            jugadorActual = &jugadorX;
            condicional = true;
            break;
        }
    }
    if (!condicional)
    {
        cout << "(Jugador no valido) El jugador " << jugadorId << " no forma parte de esta partida.\n";
        return;
    }

    // Verificar si es el turno del jugador
    if (jugadorId != risk.getCurrentTurn())
    {
        cout << "(Jugador fuera de turno) No es el turno del jugador " << jugadorId << ".\n";
        return;
    }

    cout << "Es el turno del jugador " << jugadorId << ".\n";

    std::cout<<"\n***********************FASE DE PONER NUEVAS TROPAS ADQUIRIDAS***************\n\n";

    // Obtener nuevas unidades para el jugador
    int nuevasUnidades = obtenerNuevasUnidades(*jugadorActual, risk);
    cout << "El jugador " << jugadorId << " ha obtenido " << nuevasUnidades << " nuevas unidades.\n";

    int infanteria, caballeria, artilleria;
    std::string Nterritorio;

    // CIclo para poner las tropas
    while (nuevasUnidades > 0)
    {

        // Muestra los territorios
        cout << "Territorios del jugador " << jugadorId << ": " << endl;
        for (Territorio* &territorio : jugadorActual->getTerritoriosOcupados())
        {
            cout << territorio->getNombre() << " " << std::endl;
        }
        cout << "\n";

        std::cout << "Tienes " << nuevasUnidades << " unidades (En valor de infanteria) disponibles." << std::endl;

        // Recibe y comprueba el territorio
        std::cout << "Introduzca el nombre territorio donde va a poner sus tropas: ";
        std::cin >> Nterritorio;

        condicional = false;
        for (Territorio* &territorio : jugadorActual->getTerritoriosOcupados())
        {
            if (territorio->getNombre() == Nterritorio)
            {
                // Pregunta por tropas y las añade al territorio

                std::cout << "Ingresa la cantidad de artilleria para ubicar en " << territorio->getNombre() << ": ";
                std::cin >> artilleria;

                if (artilleria * 10 > nuevasUnidades)
                {
                    cout << "No tiene suficientes unidades para ubicar " << artilleria << " unidades de artilleria\n";
                }
                else
                {
                    nuevasUnidades -= artilleria * 10;
                    for (int i = 0; i < artilleria; ++i)
                    {
                        Tropa nuevaArtilleria;
                        nuevaArtilleria.setTipoTropa("Artilleria");
                        nuevaArtilleria.setValorTropa(10);
                        nuevaArtilleria.setColor(jugadorActual->getColor());
                        territorio->getTropas().push_back(nuevaArtilleria);
                    }
                }

                std::cout << "Ingresa la cantidad de caballeria para ubicar en " << territorio->getNombre() << ": ";
                std::cin >> caballeria;

                if (caballeria * 5 > nuevasUnidades)
                {
                    cout << "No tiene suficientes unidades para ubicar " << caballeria << " unidades de caballeria\n";
                }
                else
                {
                    nuevasUnidades -= caballeria * 5;
                    for (int i = 0; i < caballeria; ++i)
                    {
                        Tropa nuevaCaballeria;
                        nuevaCaballeria.setTipoTropa("Caballeria");
                        nuevaCaballeria.setValorTropa(5);
                        nuevaCaballeria.setColor(jugadorActual->getColor());
                        territorio->getTropas().push_back(nuevaCaballeria);
                    }
                }

                std::cout << "Ingresa la cantidad de infanteria para ubicar en " << territorio->getNombre() << ": ";
                std::cin >> infanteria;

                if (infanteria > nuevasUnidades)
                {
                    cout << "No tiene suficientes unidades para ubicar " << infanteria << " unidades de infanteria\n";
                }
                else
                {
                    nuevasUnidades -= infanteria;
                    for (int i = 0; i < infanteria; ++i)
                    {
                        Tropa nuevaInfanteria;
                        nuevaInfanteria.setTipoTropa("Infanteria");
                        nuevaInfanteria.setValorTropa(1);
                        nuevaInfanteria.setColor(jugadorActual->getColor());
                        territorio->getTropas().push_back(nuevaInfanteria);
                    }
                }
                condicional = true;
                break;
            }
        }
        if (!condicional)
        {
            // Dice si no se entro un territorio valido
            std::cout << "El jugador no tiene este territorio";
        }

    }

    std::cout << "Unidades ubicadas exitosamente en tus territorios." << std::endl;

    // Elegir territorio de ataque ---------------

    std::cout<<"\n**********************FASE DE ATAQUE*****************************\n\n";

    // Obtener nombres territorio del jugador
    vector<string> territoriosJugador;
    for (Territorio* &t : jugadorActual->getTerritoriosOcupados())
    {
        territoriosJugador.push_back(t->getNombre());
    }

    // Mostrar territorios del jugador
    cout << "Territorios del jugador " << jugadorId << ": "<< endl;
    for (const string &territorio : territoriosJugador)
    {
        cout << territorio << " " << endl;
    }
    cout << "\n";

    // Territorio atacante
    condicional = true;
    bool esDelJugador;
    bool todosSonJugador;
    Territorio* territorioAtacante;
    string SterritorioAtacante;

    do
    {
        condicional = true;
        esDelJugador = false;

        cout << "Escriba el nombre del territorio desde el que se ataca: ";
        cin >> SterritorioAtacante;
        for (Territorio* &t : jugadorActual->getTerritoriosOcupados())
        {
            if (SterritorioAtacante == t->getNombre())
            {
                territorioAtacante = t;
                condicional = false;
                break;
            }
        }
        if (condicional)
        {
            std::cout << "Este territorio no es suyo o no existe\n";
        }else{
            todosSonJugador = true;
            for(Territorio* &territorio : territorioAtacante->getTerritoriosColindantes()){
                esDelJugador = false;
                for(Territorio* &t : jugadorActual->getTerritoriosOcupados()){
                    if(territorio->getNombre()==t->getNombre()){
                        esDelJugador = true;
                        break;
                    }
                }
                if (!esDelJugador) {
                    todosSonJugador = false;
                    break;
                }
            }
            if(todosSonJugador){
                cout<<"Este territorio no tiene territorios enemigos para atacar\n";
            }
        }
    } while (condicional||todosSonJugador);

    // Elegir territorio para atacar --------------

    // Mostrar territorios colindantes y que no son del jugador
    cout << "Territorios que puede atacar " << jugadorActual->getNombre() << ": " <<  endl;
    for (Territorio* &territorio : territorioAtacante->getTerritoriosColindantes())
    {
        esDelJugador = false;
        for(Territorio* &t:jugadorActual->getTerritoriosOcupados()){
            if(territorio->getNombre()==t->getNombre()){
                esDelJugador = true;
                break;
            }
        }
        if(!esDelJugador){
            cout << territorio->getNombre() << "\n";
        }
    }
    cout<<endl;

    // Pregunta por el territorio defensor, verifica si es colindante y si es del jugador

    esDelJugador = false;
    Territorio* territorioDefensor;
    string SterritorioDefensor;

    do{
        condicional = true;
        esDelJugador = false;

        cout << "Selecciona el territorio a atacar: ";
        cin >> SterritorioDefensor;
        for(Territorio* & t: territorioAtacante->getTerritoriosColindantes()){
            if(SterritorioDefensor==t->getNombre()){
                territorioDefensor = t;
                condicional = false;
                break;
            }
        }
        if(condicional){
            std::cout<<"Este territorio no colinda con su territorio atacante\n";
        }else {
            for(Territorio* & t1: jugadorActual->getTerritoriosOcupados()){
                if(SterritorioDefensor==t1->getNombre()){
                    esDelJugador = true;
                }
            }

            if (esDelJugador) {
                std::cout << "Este territorio es suyo\n";
            }
        }
    }while (condicional||esDelJugador);

    // Elegir de tropas para atacar:

    // Cuenta disponibilidad de tropas
    int contInfanteria = 0;
    int contCaballeria = 0;
    int contArtilleria = 0;

    for (Tropa tropa : territorioAtacante->getTropas())
    {
        if (tropa.getTipoTropa() == "Infanteria")
        {
            contInfanteria++;
        }
        else if (tropa.getTipoTropa() == "Caballeria")
        {
            contCaballeria++;
        }
        else if (tropa.getTipoTropa() == "Artilleria")
        {
            contArtilleria++;
        }
        else
            cout << " ñoñañaiou \"Hay tipos de tropa no valida :(\"\n";
    }

    // Imprime tropas disponibles
    std::cout << "Tropas con las que puedes atacar:\n";
    std::cout << "Infanteria: " << contInfanteria << endl;
    std::cout << "Caballeria: " << contCaballeria << endl;
    std::cout << "Artilleria: " << contArtilleria << endl;

    // Pregunta por las tropas que quiere atacar
    int infanteriaAtaque;
    int caballeriaAtaque;
    int artilleriaAtaque;

    do
    {
        std::cout << "Con cuantas tropas de infanteria quieres atacar: ";
        std::cin >> infanteriaAtaque;
        if (infanteriaAtaque > contInfanteria || infanteriaAtaque < 0)
        {
            std::cout << "No tienes esa cantidad de unidades de infanteria\n";
            condicional = true;
        }
        else
        {
            condicional = false;
        }
    } while (condicional);

    do
    {
        std::cout << "Con cuantas tropas de caballeria quieres atacar: ";
        std::cin >> caballeriaAtaque;
        if (caballeriaAtaque > contCaballeria || caballeriaAtaque < 0)
        {
            std::cout << "No tienes esa cantidad de unidades de caballeria\n";
            condicional = true;
        }
        else
        {
            condicional = false;
        }
    } while (condicional);

    do
    {
        std::cout << "Con cuantas tropas de artilleria quieres atacar: ";
        std::cin >> artilleriaAtaque;
        if (artilleriaAtaque > contArtilleria || artilleriaAtaque < 0)
        {
            std::cout << "No tienes esa cantidad de unidades de artilleria\n";
            condicional = true;
        }
        else
        {
            condicional = false;
        }
    } while (condicional);

    // Quitar las tropas del pais atacante y se almacenan en el vector tropas atacantes
    int contQuitarInfanteria = infanteriaAtaque;
    int contQuitarCaballeria = caballeriaAtaque;
    int contQuitarArtilleria = artilleriaAtaque;

    list<Tropa> tropasAtacantes;

    for (auto iterador = territorioAtacante->getTropas().begin(); iterador != territorioAtacante->getTropas().end();)
    {
        if (iterador->getTipoTropa() == "Infanteria")
        {
            if (contQuitarInfanteria > 0)
            {
                tropasAtacantes.push_back(*iterador);
                iterador = territorioAtacante->getTropas().erase(iterador);
                contQuitarInfanteria--;
            }
            else
            {
                iterador++;
            }
        }
        else if (iterador->getTipoTropa() == "Caballeria")
        {
            if (contQuitarCaballeria > 0)
            {
                tropasAtacantes.push_back(*iterador);
                iterador = territorioAtacante->getTropas().erase(iterador);
                contQuitarCaballeria--;
            }
            else
            {
                iterador++;
            }
        }
        else if (iterador->getTipoTropa() == "Artilleria")
        {
            if (contQuitarArtilleria > 0)
            {
                tropasAtacantes.push_back(*iterador);
                iterador = territorioAtacante->getTropas().erase(iterador);
                contQuitarArtilleria--;
            }
            else
            {
                iterador++;
            }
        }
    }


    // Numero de dados para atacante y defensor (Dados por el enunciado)
    int dadosAtacante = 3;
    int dadosDefensor = 2;

    // Ciclo de conquista
    condicional = true;

    // Cacular valor de tropas (En medidas de infateria) iniciales del atacante
    int valorAtacante = 0;
    valorAtacante += infanteriaAtaque;
    valorAtacante += 5 * caballeriaAtaque;
    valorAtacante += 10 * artilleriaAtaque;

    // Cacular valor de tropas (En medidas de infateria) iniciales del defensor
    // ADicionalemente de calcular el valor contamos la cantidad de tropas actuales para mas tarde
    int valorDefensor = 0;

    int infanteriaDefensa = 0;
    int caballeriaDefensa = 0;
    int artilleriaDefensa = 0;

    for (Tropa tropa : territorioDefensor->getTropas())
    {
        if (tropa.getTipoTropa() == "Infanteria")
        {
            valorDefensor += 1;
            infanteriaDefensa++;
        }
        else if (tropa.getTipoTropa() == "Caballeria")
        {
            valorDefensor += 5;
            caballeriaDefensa++;
        }
        else if (tropa.getTipoTropa() == "Artilleria")
        {
            valorDefensor += 10;
            artilleriaDefensa++;
        }
    }

    int valorPerdidoAtacantes = 0;
    int valorPerdidoDefensores = 0;

    condicional = true;
    int contador = 0;
    while (condicional)
    {
        contador++;
        cout<<"Loop "<< contador<<endl;

        // Simular lanzamiento de dados y determinar resultados
        vector<int> resultadosAtacante = lanzarDados(dadosAtacante);
        vector<int> resultadosDefensor = lanzarDados(dadosDefensor);
        cout<<"Resultado atacante - Dado 1: "<<resultadosAtacante[0]<< ", Dado 2: "<<resultadosAtacante[1]<<", Dado 3: "<<resultadosAtacante[2]<<endl;
        cout<<"Resultado defensor - Dado 1: "<<resultadosDefensor[0]<< ", Dado 2: "<<resultadosDefensor[1]<<endl<<endl;


        // Calcular perdidas de unidades para atacante y defensor (Ataque se devuelve en [1] y defensa en [0]
        vector<int> perdidas = calcularPerdidas(resultadosAtacante, resultadosDefensor);
        valorPerdidoDefensores += perdidas[0];
        valorPerdidoAtacantes += perdidas[1];

        // Actualizar valor de tropas de la batalla (Provisional)
        valorDefensor -= perdidas[0];
        valorAtacante -= perdidas[1];


        // Comprobar si la batalla esta terminada y Ajustar el estado actual de la partida dependiendo del resultado de la partida
        if (valorAtacante <= 0 || valorDefensor <= 0)
        {
            if (valorAtacante <= 0 && valorDefensor <= 0)
            {
                auto it = territorioDefensor->getTropas().begin();
                string color = it->getColor();
                eliminarPropiedadConColor(risk, color, territorioDefensor->getNombre()); // Eliminar el pais de la lista del defensor

                territorioDefensor->setTropas(list<Tropa>());
                cout << "El defensor perdio sus tropas y tu tambien, no se realiza la conquista, se la quita la propiedad al defensor.\n";

            }
            else if (valorAtacante <= 0)
            {
                cout << "No lograste conquistar el territorio\n";
                cout << "Tropas del defensor perdidas: "<<valorPerdidoDefensores<<endl;
                eliminarPerdidas(territorioDefensor, infanteriaDefensa, caballeriaDefensa, artilleriaDefensa, valorPerdidoDefensores);
            }
            else if (valorDefensor <= 0)
            {
                auto it = territorioDefensor->getTropas().begin();
                string color = it->getColor();
                eliminarPropiedadConColor(risk, color, territorioDefensor->getNombre()); // Eliminar el pais de la lista del defensor

                territorioDefensor->setTropas(tropasAtacantes);
                eliminarPerdidas(territorioDefensor, infanteriaAtaque, caballeriaAtaque, artilleriaAtaque, valorPerdidoAtacantes);

                jugadorActual->getTerritoriosOcupados().push_back(territorioDefensor);

                // Dar carta por la victoria
                if (!risk.getListaCartas().empty()) {
                    jugadorActual->agregarCarta(risk.getListaCartas().back());
                    risk.eliminarUltimaCarta();
                } else {
                    cout << "Ya no hay mas cartas\n";
                }

                cout << "Lograste controlar el territorio, felicitaciones :)\n";
                cout << "Tropas perdidas: "<<valorPerdidoAtacantes<<endl;

            }
            condicional = false;
            cout << "Presione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    }

    std::cout<<"\n***********************FASE DE FORTIFICACION**********************************\n\n";

    // Fortificar la posicion del jugador
    int unidadesFortificacion;

    fortificarPosicion(*jugadorActual, risk);

    // Cambiar el turno al siguiente jugador
    for (auto it = risk.getListaJugadores().begin(); it != risk.getListaJugadores().end(); ++it)
    {
        if (it->getNombre() == jugadorActual->getNombre())
        {
            auto nextIt = std::next(it); // Avanzar al siguiente jugador

            if (nextIt == risk.getListaJugadores().end())
            {
                nextIt = risk.getListaJugadores().begin(); // Volver al primer jugador si es el último
            }

            risk.setCurrentTurn(nextIt->getIdJugador());
            cout << "Turno del jugador " << nextIt->getNombre() << " ID: " << nextIt->getIdJugador() << endl;
            break;
        }
    }
}

void Comandos::salirJuego(Risk &risk)
{
    risk.setIsGameOver(true);
    cout << "El juego ha terminado. ¡Hasta luego!\n";
}

void Comandos::guardarEstadoJuego(Risk &risk, const string &nombreArchivo)
{
    if (!risk.isGameInitialized1())
    {
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
                "correctamente.\n";
    }
    else if (risk.isGameOver1())
    {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    }
    else
    {

        bool guardo_bien = false;
        if (guardo_bien)
        {
        }
        else
        {
            cout << "(Error al guardar) La partida no ha sido guardada correctamente.\n";
        }
    }
}

void Comandos::guardarEstadoComprimido(Risk &risk, const string &nombreArchivo)
{
    if (!risk.isGameInitialized1())
    {
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
                "correctamente.\n";
    }
    else if (risk.isGameOver1())
    {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    }
    else
    {

        bool guardo_archivo_binario = false;
        if (guardo_archivo_binario)
        {
        }
        else
        {
            cout << "(Error al codificar y/o guardar) La partida no ha sido codificada ni guardada correctamente.\n";
        }
    }
}

void Comandos::inicializar(const string &nombre_archivo) {}

string Comandos::costoConquista(Risk &risk, const string &territorio, const vector<string> &territorios)
{
    if (!risk.isGameInitialized1())
    {
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
                "correctamente.\n";
    }
    else if (risk.isGameOver1())
    {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    }
    else
    {
        // Mostrar el mensaje con los valores calculados
        cout << "(Comando correcto) Para conquistar el territorio "
             << territorio;

        if (!territorios.empty())
        {
            cout << ", debe atacar desde " << territorios[0]
                 << ", pasando por los territorios ";

            for (size_t i = 1; i < territorios.size(); ++i)
            {
                cout << territorios[i];
                if (i < territorios.size() - 1)
                {
                    cout << ", ";
                }
            }
        }

        cout << ". Debe conquistar " << territorios.size()
             << " unidades de ejercito.\n";
    }
    return "Pronto implementado >O";
}

string Comandos::conquistaMasBarata(Risk &risk, const vector<string> &territorios)
{
    if (!risk.isGameInitialized1())
    {
        cout << "(Juego no inicializado) Esta partida no ha sido inicializada "
                "correctamente.\n";
    }
    else if (risk.isGameOver1())
    {
        cout << "(Juego terminado) Esta partida ya tuvo un ganador.\n";
    }
    else
    {
        // Mostrar el mensaje con los valores calculados
        cout << "(Comando correcto) El territorio con menor costo de conquista es: \n";

        if (!territorios.empty())
        {
            cout << ", debe avanzar sobre el territorio " << territorios[0]
                 << ", desde el territorio ";

            for (size_t i = 1; i < territorios.size(); ++i)
            {
                cout << territorios[i];
                if (i < territorios.size() - 1)
                {
                    cout << ", ";
                }
            }
        }
    }
    return "Implementado pronto :v";
}

int Comandos::obtenerNuevasUnidades(Jugador &jugador, Risk &risk)
{
    int nuevasUnidades = 0;

    // Obtener la cantidad de territorios ocupados por el jugador
    int cantidadTerritoriosOcupados = jugador.getTerritoriosOcupados().size();

    // Calcular las unidades basadas en territorios ocupados
    nuevasUnidades += cantidadTerritoriosOcupados / 3;

    // Calcular unidades por continentes ocupados
    int continentesOcupados = 0;
    for (Continente &continente : risk.getListaContinentes())
    {
        int territoriosOcupadosEnContinente = 0;
        for (Territorio* &territorio : continente.getTerritorios())
        {
            for (Territorio* &t : jugador.getTerritoriosOcupados())
            {
                if (territorio->getNombre() == t->getNombre())
                {
                    territoriosOcupadosEnContinente++;
                    break;
                }
            }
        }
        if (territoriosOcupadosEnContinente == continente.getTerritorios().size())
        {
            if (continente.getNombre() == "America del Sur" || continente.getNombre() == "Oceania")
            {
                nuevasUnidades += 2;
            }
            else if (continente.getNombre() == "Africa")
            {
                nuevasUnidades += 3;
            }
            else if (continente.getNombre() == "America del norte" || continente.getNombre() == "Europa")
            {
                nuevasUnidades += 5;
            }
            else if (continente.getNombre() == "Asia")
            {
                nuevasUnidades += 7;
            }
        }
    }
    // Calcular unidades por cartas de territorios
    nuevasUnidades += intercambiarCartas(jugador, risk);

    return nuevasUnidades;
}

int Comandos::intercambiarCartas(Jugador &jugadorActual, Risk &risk)
{
    const list<Carta> &cartasJugador = jugadorActual.getCartas();

    int cartasIntercambiadas = risk.getCartasIntercambiadas();
    int unidadesExtras = 0;

    int contadorComodines = 0;
    int contadorInfanteria = 0;
    int contadorCaballeria = 0;
    int contadorArtilleria = 0;

    int contadorGrupo;

    Comandos comandos;

    vector<Carta> cartasAIntercambiar;

    for (const Carta &carta : cartasJugador)
    {
        if (carta.getTropa() == "Comodin")
        {
            contadorComodines++;
        }
        else if (carta.getTropa() == "Infanteria")
        {
            contadorInfanteria++;
        }
        else if (carta.getTropa() == "Caballeria")
        {
            contadorCaballeria++;
        }
        else if (carta.getTropa() == "Artilleria")
        {
            contadorArtilleria++;
        }

        // Si son se encuentra de la misma tropa
        if (contadorInfanteria == 3 || contadorCaballeria == 3 || contadorArtilleria == 3 ||
            (contadorComodines > 0 && (contadorComodines + contadorArtilleria + contadorCaballeria + contadorInfanteria >= 3)))
        {
            // Determinar el tipo de intecambio
            string tipoIntercambio;
            if (contadorInfanteria >= 3)
            {
                tipoIntercambio = "Infanteria";
            }
            else if (contadorCaballeria >= 3)
            {
                tipoIntercambio = "Caballeria";
            }
            else if (contadorArtilleria >= 3)
            {
                tipoIntercambio = "Artilleria";
            }
            else if (contadorComodines > 0)
            {
                tipoIntercambio = "Comodin";
            }

            // Realizar el intercambio, si hubo comodines se recibe cuantos se usaron
            int comodinesUsados = comandos.intercambioCartasYTerritorio(risk, jugadorActual, tipoIntercambio, 3);

            // Se calculan las unidades extra que puede calcular
            unidadesExtras = comandos.calcularUnidadesExtraCartas(cartasIntercambiadas, unidadesExtras);

            // Ajustar contadores dependiendo del intercambio hecho
            if (tipoIntercambio == "Infanteria")
            {
                contadorInfanteria -= 3;
            }
            else if (tipoIntercambio == "Caballeria")
            {
                contadorCaballeria -= 3;
            }
            else if (tipoIntercambio == "Artilleria")
            {
                contadorArtilleria -= 3;
            }
            else if (tipoIntercambio == "Comodin")
            {
                contadorComodines -= comodinesUsados;
            }

            cartasIntercambiadas++; // Intercambio realizado
        }
        else if (contadorInfanteria > 0 || contadorCaballeria > 0 || contadorArtilleria > 0)
        {
            comandos.intercambioCartasYTerritorio(risk, jugadorActual, "Infanteria", 1);
            comandos.intercambioCartasYTerritorio(risk, jugadorActual, "Caballeria", 1);
            comandos.intercambioCartasYTerritorio(risk, jugadorActual, "Artilleria", 1);

            unidadesExtras = comandos.calcularUnidadesExtraCartas(cartasIntercambiadas, unidadesExtras);
            contadorArtilleria--;
            contadorInfanteria--;
            contadorCaballeria--;
            cartasIntercambiadas++; // Intercambio realizado
        }
    }
    risk.setCartasIntercambiadas(cartasIntercambiadas);

    return unidadesExtras;
}

int Comandos::calcularUnidadesExtraCartas(int cartasIntercambiadas, int unidadesExtras)
{
    if (cartasIntercambiadas == 0)
    {
        unidadesExtras += 4;
    }
    else if (cartasIntercambiadas == 1)
    {
        unidadesExtras += 6;
    }
    else if (cartasIntercambiadas == 2)
    {
        unidadesExtras += 8;
    }
    else if (cartasIntercambiadas == 3)
    {
        unidadesExtras += 10;
    }
    else if (cartasIntercambiadas == 4)
    {
        unidadesExtras += 12;
    }
    else if (cartasIntercambiadas == 5)
    {
        unidadesExtras += 15;
    }
    else
    {
        unidadesExtras += 15 + (5 * (cartasIntercambiadas - 5));
    }

    return unidadesExtras;
}

int Comandos::intercambioCartasYTerritorio(Risk &risk, Jugador &jugadorActual, string tropa, int contador)
{
    int contadorGrupo = 0;
    int comodinesUsados = 0;
    std::vector<std::list<Carta>::const_iterator> cartasAIntercambiar;

    if (tropa == "Comodin")
    {
        bool comodinUsado = false;
        for (auto it = jugadorActual.getCartas().begin(); it != jugadorActual.getCartas().end(); ++it)
        {
            if (it->getTropa() == "Comodin")
            {
                comodinesUsados++;
                comodinUsado = true;
            }
            contadorGrupo++;

            if (comodinUsado || contadorGrupo < 3)
            {
                // Agregar carta a las que se van a intercambiar
                cartasAIntercambiar.push_back(it);

                // Evaluar si el territorio de la carta pertenece al jugador, darle las unidades adicionales
                for (Territorio* &territorio : jugadorActual.getTerritoriosOcupados())
                {
                    if (it->getTerritorio() == territorio->getNombre())
                    {
                        Tropa nuevaInfanteria;
                        nuevaInfanteria.setTipoTropa("Infanteria");
                        nuevaInfanteria.setValorTropa(1);
                        nuevaInfanteria.setColor(jugadorActual.getColor());
                        territorio->getTropas().push_back(nuevaInfanteria);
                        territorio->getTropas().push_back(nuevaInfanteria);
                    }
                }
            }

            if (contadorGrupo >= 3 && comodinUsado)
            {
                break;
            }
        }
    }
    else
    {
        for (auto it = jugadorActual.getCartas().begin(); it != jugadorActual.getCartas().end(); ++it)
        {
            if (it->getTropa() == tropa)
            {
                contadorGrupo++;

                // Agregar carta a las que se van a intercambiar
                cartasAIntercambiar.push_back(it);

                // Evaluar si el territorio de la carta pertenece al jugador, darle las unidades adicionales
                for (Territorio* &territorio : jugadorActual.getTerritoriosOcupados())
                {
                    if (it->getTerritorio() == territorio->getNombre())
                    {
                        Tropa nuevaInfanteria;
                        nuevaInfanteria.setTipoTropa("Infanteria");
                        nuevaInfanteria.setValorTropa(1);
                        nuevaInfanteria.setColor(jugadorActual.getColor());
                        territorio->getTropas().push_back(nuevaInfanteria);
                        territorio->getTropas().push_back(nuevaInfanteria);
                    }
                }
            }
            if (contadorGrupo == contador)
            {
                break;
            }
        }
    }

    // Realizar el intercambio de cartas
    for (auto it : cartasAIntercambiar)
    {
        risk.getListaCartas().push_back(*it);
        it = jugadorActual.eliminarCarta(it);
    }

    return comodinesUsados;
}

vector<int> Comandos::lanzarDados(int cantidad)
{
    vector<int> resultados;
    // Poner los resultados en el vector
    std::srand(std::time(nullptr));
    for (int i = 0; i < cantidad; i++)
    {
        resultados.push_back((std::rand() % 6) + 1);
    }

    // Ordenar los resultados de mayor a menor
    int aux;
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = i + 1; j < cantidad; j++)
        {
            if (resultados[i] < resultados[j])
            {
                aux = resultados[j];
                resultados[j] = resultados[i];
                resultados[i] = aux;
            }
        }
    }

    return resultados;
}

vector<int> Comandos::calcularPerdidas(const vector<int> &resultadosA, const vector<int> &resultadosD)
{
    int perdidasA = 0;
    int perdidasD = 0;

    // Calcula la cantidad de dados a comparar
    int menorCantidad;
    if (resultadosD.size() <= resultadosA.size())
    {
        menorCantidad = resultadosD.size();
    }
    else
        menorCantidad = resultadosA.size();

    for (int i = 0; i < menorCantidad; i++)
    {
        if (resultadosD[i] >= resultadosA[i])
        {
            perdidasA++;
        }
        else
            perdidasD++;
    }

    // El vector de vuelta devuelve primero las perdidas del defensor y luego las del atacante
    vector<int> perdidas;
    perdidas.push_back(perdidasD);
    perdidas.push_back(perdidasA);

    return perdidas;
}

void Comandos::eliminarPerdidas(Territorio* &territorio, int infanteria, int caballeria, int artilleria, int valorPerdido)
{
    for (auto iterador = territorio->getTropas().begin(); iterador != territorio->getTropas().end();)
    {
        if (iterador->getTipoTropa() == "Infanteria")
        {
            if (valorPerdido > 0 && infanteria > 0)
            {
                iterador = territorio->getTropas().erase(iterador);
                infanteria--;
                valorPerdido--;
            }
            else
            {
                iterador++;
            }
        }
        else if (iterador->getTipoTropa() == "Caballeria")
        {
            if (valorPerdido >= 5 && caballeria > 0)
            {
                iterador = territorio->getTropas().erase(iterador);
                caballeria--;
                valorPerdido-=5;
            }
            else
            {
                iterador++;
            }
        }
        else if (iterador->getTipoTropa() == "Artilleria")
        {
            if (valorPerdido >= 10 && artilleria > 0)
            {
                iterador = territorio->getTropas().erase(iterador);
                artilleria--;
                valorPerdido-=10;
            }
            else
            {
                iterador++;
            }
        }
    }
}

void Comandos::eliminarPropiedadConColor(Risk &risk, const string &color, const string &nombreTerritorio)
{
    for (Jugador& jugador : risk.getListaJugadores())
    {
        if (jugador.getColor() == color)
        {
            for (auto iterador = jugador.getTerritoriosOcupados().begin();
                 iterador != jugador.getTerritoriosOcupados().end();) {
                if (nombreTerritorio == (*iterador)->getNombre()) {
                    iterador = jugador.getTerritoriosOcupados().erase(iterador);
                    break;
                } else {
                    ++iterador;
                }
            }
            break;
        }
    }
}

void Comandos::fortificarPosicion(Jugador &jugadorActual, Risk &risk)
{
    try {
        bool condicional;

        cout << "Territorios del jugador " << jugadorActual.getNombre() << ": " << endl;
        for (Territorio* &territorio : jugadorActual.getTerritoriosOcupados())
        {
            cout << territorio->getNombre() << " " << endl;
        }
        cout << "\n";

        string SterritorioOrigen, SterritorioDestino;
        Territorio* territorioOrigen;
        Territorio* territorioDestino;
        bool esDelJugador;

        // Pregunta territorio origen, verifica si es del jugador y si este tiene territorios colindantes del jugador
        condicional = true;
        do
        {
            condicional = true;
            esDelJugador = false;

            cout << "Selecciona el territorio desde el que deseas trasladar unidades (Si no quiere realizar fortificacion"
                    " escriba 'no'): ";
            cin >> SterritorioOrigen;

            if(SterritorioOrigen == "no"||SterritorioOrigen == "No"){
                cout<<"No se fortifico ningun territorio\n";
                return;
            }

            for (Territorio* &t : jugadorActual.getTerritoriosOcupados())
            {
                if (SterritorioOrigen == t->getNombre())
                {
                    territorioOrigen = t;
                    condicional = false;
                    break;
                }
            }


            if (condicional)
            {
                std::cout << "Este territorio no es suyo o no existe\n";
            }else{
                for(Territorio* &territorio : territorioOrigen->getTerritoriosColindantes()){
                    for(Territorio* &t : jugadorActual.getTerritoriosOcupados()){
                        if(territorio->getNombre()==t->getNombre()){
                            esDelJugador = true;
                            break;
                        }
                    }
                }
                if(!esDelJugador){
                    cout<<"Este territorio no tiene territorios colindantes tuyos para fortificar\n";
                }
            }
        } while (condicional||!esDelJugador);

        // Obtener territorio destino de la fortificacion

        // Mostrar territorios colindantes y que pertenecen al jugador
        cout << "Territorios a los que puede trasladar " << jugadorActual.getNombre() << ": ";
        for (Territorio* &territorio : territorioOrigen->getTerritoriosColindantes())
        {
            condicional = false;
            for(Territorio* &t:jugadorActual.getTerritoriosOcupados()){
                if(territorio->getNombre()==t->getNombre()){
                    condicional = true;
                    break;
                }
            }
            if(condicional){
                cout << territorio->getNombre() << "\n";
            }

        }
        cout << "\n";

        //Pregunta por los territorios destino de la fortificacion, verifica si es colindante y si es del jugador
        do
        {
            condicional = true;
            esDelJugador = false;

            cout << "Escriba el nombre territorio para trasladar las tropas: ";
            cin >> SterritorioDestino;

            for (Territorio* &t : territorioOrigen->getTerritoriosColindantes())
            {
                if (SterritorioDestino == t->getNombre())
                {
                    territorioDestino = t;
                    condicional = false;
                    break;
                }
            }
            if(condicional)
            {
                std::cout << "Este territorio no colinda con su territorio atacante\n";
            } else{
                for(Territorio* &t : jugadorActual.getTerritoriosOcupados()){
                    if(territorioDestino->getNombre()==t->getNombre()){
                        esDelJugador = true;
                        break;
                    }
                }
                if(!esDelJugador) {
                    std::cout << "Este territorio no es tuyo\n";
                }
            }

        } while (!esDelJugador||condicional);

        // Trasladar tropas

        // Elegir cantidad de tropas para atacar:

        // Cuenta disponibilidad de tropas
        int contInfanteria = 0;
        int contCaballeria = 0;
        int contArtilleria = 0;

        for (const Tropa &tropa : territorioOrigen->getTropas())
        {
            if (tropa.getTipoTropa() == "Infanteria")
            {
                contInfanteria++;
            }
            else if (tropa.getTipoTropa() == "Caballeria")
            {
                contCaballeria++;
            }
            else if (tropa.getTipoTropa() == "Artilleria")
            {
                contArtilleria++;
            }
            else
                cout << " ñoñañaiou \"Hay tipos de tropa no valida :(\"\n";
        }

        // Imprime tropas disponibles
        std::cout << "Tropas que puedes mover:\n";
        std::cout << "Infanteria: " << contInfanteria << endl;
        std::cout << "Caballeria: " << contCaballeria << endl;
        std::cout << "Artilleria: " << contArtilleria << endl;

        // Pregunta por las tropas que quiere mover
        int unidadesInfanteria;
        int unidadesCaballeria;
        int unidadesArtilleria;

        do
        {
            std::cout << "Cuantas tropas de infanteria quieres mover: ";
            std::cin >> unidadesInfanteria;
            if (unidadesInfanteria > contInfanteria || unidadesInfanteria < 0)
            {
                std::cout << "No tienes esa cantidad de unidades de infanteria\n";
                condicional = true;
            }
            else
            {
                condicional = false;
            }
        } while (condicional);

        do
        {
            std::cout << "Cuantas tropas de caballeria quieres mover: ";
            std::cin >> unidadesCaballeria;
            if (unidadesCaballeria > contCaballeria || unidadesCaballeria < 0)
            {
                std::cout << "No tienes esa cantidad de unidades de caballeria\n";
                condicional = true;
            }
            else
            {
                condicional = false;
            }
        } while (condicional);

        do
        {
            std::cout << "Cuantas tropas de artilleria quieres mover: ";
            std::cin >> unidadesArtilleria;
            if (unidadesArtilleria > contArtilleria || unidadesArtilleria < 0)
            {
                std::cout << "No tienes esa cantidad de unidades de artilleria\n";
                condicional = true;
            }
            else
            {
                condicional = false;
            }
        } while (condicional);

        // Quitar las tropas del pais origen y se almacenan en el vector tropas apoyo y contar valor de fortificacion
        int contQuitarInfanteria = unidadesInfanteria;
        int contQuitarCaballeria = unidadesCaballeria;
        int contQuitarArtilleria = unidadesArtilleria;

        int unidadesFortificacion = 0;

        vector<Tropa> tropasApoyo;

        for (auto iterador = territorioOrigen->getTropas().begin(); iterador != territorioOrigen->getTropas().end();)
        {
            if (iterador->getTipoTropa() == "Infanteria")
            {
                if (contQuitarInfanteria > 0)
                {
                    tropasApoyo.push_back(*iterador);
                    iterador = territorioOrigen->getTropas().erase(iterador);
                    unidadesFortificacion++;
                    contQuitarInfanteria--;
                }
                else
                {
                    iterador++;
                }
            }
            else if (iterador->getTipoTropa() == "Caballeria")
            {
                if (contQuitarCaballeria > 0)
                {
                    tropasApoyo.push_back(*iterador);
                    iterador = territorioOrigen->getTropas().erase(iterador);
                    unidadesFortificacion += 5;
                    contQuitarCaballeria--;
                }
                else
                {
                    iterador++;
                }
            }
            else if (iterador->getTipoTropa() == "Artilleria")
            {
                if (contQuitarArtilleria > 0)
                {
                    tropasApoyo.push_back(*iterador);
                    iterador = territorioOrigen->getTropas().erase(iterador);
                    unidadesFortificacion += 10;
                    contQuitarArtilleria--;
                }
                else
                {
                    iterador++;
                }
            }
        }

        // Agregar las tropas al destino
        for (Tropa &tropa : tropasApoyo)
        {
            territorioDestino->getTropas().push_back(tropa);
        }

        cout << "Se han trasladado " << unidadesFortificacion << " unidades desde "
             << territorioOrigen->getNombre() << " a " << territorioDestino->getNombre() << ".\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}