#include <sstream>
#include "Risk.h"



Risk::Risk()
{
    // América del Norte
    list<Territorio*> listaProvANorte;

    auto alaska = std::make_shared<Territorio>("Alaska",list<Tropa>());
    auto alberta = std::make_shared<Territorio>("Alberta",list<Tropa>());
    auto americaCentral = std::make_shared<Territorio>("America_Central",list<Tropa>());
    auto estadosUnidosOrientales = std::make_shared<Territorio>("Estados_Unidos_Orientales",list<Tropa>());
    auto groenlandia = std::make_shared<Territorio>("Groenlandia",list<Tropa>());
    auto territorioNoroccidental = std::make_shared<Territorio>("Territorio_Noroccidental",list<Tropa>());
    auto ontario = std::make_shared<Territorio>("Ontario",list<Tropa>());
    auto quebec = std::make_shared<Territorio>("Quebec",list<Tropa>());
    auto estadosUnidosOccidentales = std::make_shared<Territorio>("Estados_Unidos_Occidentales",list<Tropa>());


    // Asia
    list<Territorio*> listaProvAsia;

    auto afghanistan = std::make_shared<Territorio>("Afghanistan",list<Tropa>());
    auto china = std::make_shared<Territorio>("China",list<Tropa>());
    auto india = std::make_shared<Territorio>("India",list<Tropa>());
    auto irkutsk = std::make_shared<Territorio>("Irkutsk",list<Tropa>());
    auto japon = std::make_shared<Territorio>("Japon",list<Tropa>());
    auto kamchatka = std::make_shared<Territorio>("Kamchatka",list<Tropa>());
    auto mediooriente = std::make_shared<Territorio>("Medio_Oriente",list<Tropa>());
    auto mongolia = std::make_shared<Territorio>("Mongolia",list<Tropa>());
    auto siam = std::make_shared<Territorio>("Siam",list<Tropa>());
    auto siberia = std::make_shared<Territorio>("Siberia",list<Tropa>());
    auto ural = std::make_shared<Territorio>("Ural",list<Tropa>());
    auto yakutsk = std::make_shared<Territorio>("Yakutsk",list<Tropa>());


    // Europa
    list<Territorio*> listaProvEuropa;

    auto granBretana = std::make_shared<Territorio>("Gran_Bretana",list<Tropa>());
    auto islandia = std::make_shared<Territorio>("Islandia",list<Tropa>());
    auto europaDelNorte = std::make_shared<Territorio>("Europa_del_Norte",list<Tropa>());
    auto escandinavia = std::make_shared<Territorio>("Escandinavia",list<Tropa>());
    auto europaDelSur = std::make_shared<Territorio>("Europa_del_Sur",list<Tropa>());
    auto ucrania = std::make_shared<Territorio>("Ucrania",list<Tropa>());
    auto europaOccidental = std::make_shared<Territorio>("Europa_Occidental",list<Tropa>());


    // Africa

    list<Territorio*> listaProvAfrica;

    auto congo = std::make_shared<Territorio>("Congo",list<Tropa>());
    auto africaOriental = std::make_shared<Territorio>("Africa_Oriental",list<Tropa>());
    auto egipto = std::make_shared<Territorio>("Egipto",list<Tropa>());
    auto madagascar = std::make_shared<Territorio>("Madagascar",list<Tropa>());
    auto africaDelNorte = std::make_shared<Territorio>("Africa_del_Norte",list<Tropa>());
    auto africaDelSur = std::make_shared<Territorio>("Africa_del_Sur",list<Tropa>());


    // Australia
    list<Territorio*> listProvAustralia;

    auto australiaOriental = std::make_shared<Territorio>("Australia_Oriental",list<Tropa>());
    auto indonesia = std::make_shared<Territorio>("Indonesia",list<Tropa>());
    auto nuevaGuinea = std::make_shared<Territorio>("Nueva_Guinea",list<Tropa>());
    auto australiaOccidental = std::make_shared<Territorio>("Australia_Occidental",list<Tropa>());


    // America del sur
    list<Territorio*> listProvASur;

    auto argentina = std::make_shared<Territorio>("Argentina",list<Tropa>());
    auto brasil = std::make_shared<Territorio>("Brasil",list<Tropa>());
    auto peru = std::make_shared<Territorio>("Peru",list<Tropa>());
    auto venezuela = std::make_shared<Territorio>("Venezuela",list<Tropa>());



    // Poniendo territorios colindantes
    alaska->setTerritoriosColindantes( list<Territorio*>{kamchatka.get(), territorioNoroccidental.get(), alberta.get()});
    alberta->setTerritoriosColindantes(list<Territorio*>{alaska.get(), territorioNoroccidental.get(), ontario.get(), estadosUnidosOccidentales.get()});
    americaCentral->setTerritoriosColindantes(list<Territorio*>{estadosUnidosOccidentales.get(), estadosUnidosOrientales.get(), venezuela.get()});
    estadosUnidosOrientales->setTerritoriosColindantes(list<Territorio*>{americaCentral.get(), estadosUnidosOccidentales.get(),ontario.get(), quebec.get()});
    groenlandia->setTerritoriosColindantes(list<Territorio*>{islandia.get(), territorioNoroccidental.get(), ontario.get(), quebec.get()});
    territorioNoroccidental->setTerritoriosColindantes(list<Territorio*>{alaska.get(), groenlandia.get(), alberta.get(), ontario.get()});
    ontario->setTerritoriosColindantes(list<Territorio*>{quebec.get(), territorioNoroccidental.get(), groenlandia.get(), alberta.get(), estadosUnidosOccidentales.get(), estadosUnidosOrientales.get()});
    quebec->setTerritoriosColindantes(list<Territorio*>{groenlandia.get(), ontario.get(), estadosUnidosOrientales.get()});
    estadosUnidosOccidentales->setTerritoriosColindantes(list<Territorio*>{americaCentral.get(), estadosUnidosOrientales.get(), alberta.get(), ontario.get()});
    venezuela->setTerritoriosColindantes(list<Territorio*>{americaCentral.get(), brasil.get(), peru.get()});
    peru->setTerritoriosColindantes(list<Territorio*>{venezuela.get(), brasil.get(), argentina.get()});
    argentina->setTerritoriosColindantes(list<Territorio*>{brasil.get(), peru.get()});
    brasil->setTerritoriosColindantes(list<Territorio*>{venezuela.get(), argentina.get(), peru.get(), africaDelNorte.get()});
    africaDelNorte->setTerritoriosColindantes(list<Territorio*>{europaOccidental.get(), europaDelSur.get(), brasil.get(), egipto.get(), congo.get(), africaOriental.get()});
    congo->setTerritoriosColindantes(list<Territorio*>{africaDelNorte.get(), africaOriental.get(), africaDelSur.get()});
    africaOriental->setTerritoriosColindantes(list<Territorio*>{madagascar.get(), congo.get(), africaDelSur.get(), africaDelNorte.get(), egipto.get()});
    africaDelSur->setTerritoriosColindantes(list<Territorio*>{congo.get(), madagascar.get(), africaOriental.get()});
    madagascar->setTerritoriosColindantes(list<Territorio*>{africaOriental.get(), africaDelSur.get()});
    egipto->setTerritoriosColindantes(list<Territorio*>{africaDelNorte.get(), africaOriental.get(), europaDelSur.get(), mediooriente.get()});
    granBretana->setTerritoriosColindantes(list<Territorio*>{islandia.get(), europaOccidental.get(), europaDelNorte.get(), escandinavia.get()});
    islandia->setTerritoriosColindantes(list<Territorio*>{groenlandia.get(), granBretana.get(), escandinavia.get()});
    europaDelNorte->setTerritoriosColindantes(list<Territorio*>{granBretana.get(), europaOccidental.get(), europaDelSur.get(), ucrania.get(), escandinavia.get()});
    escandinavia->setTerritoriosColindantes(list<Territorio*>{islandia.get(), granBretana.get(), europaDelNorte.get(), ucrania.get()});
    europaDelSur->setTerritoriosColindantes(list<Territorio*>{africaDelNorte.get(), europaOccidental.get(), europaDelNorte.get(), egipto.get(), ucrania.get(), mediooriente.get()});
    europaOccidental->setTerritoriosColindantes(list<Territorio*>{granBretana.get(), africaDelNorte.get(), europaDelNorte.get(), europaDelSur.get()});
    ucrania->setTerritoriosColindantes(list<Territorio*>{europaDelSur.get(), mediooriente.get(), europaDelNorte.get(), escandinavia.get(), ural.get(), escandinavia.get()});
    afghanistan->setTerritoriosColindantes(list<Territorio*>{ural.get(), ucrania.get(), mediooriente.get(), india.get(), china.get()});
    china->setTerritoriosColindantes(list<Territorio*>{afghanistan.get(), india.get(), siam.get(), mongolia.get(), ural.get(), siberia.get()});
    india->setTerritoriosColindantes(list<Territorio*>{afghanistan.get(), mediooriente.get(), china.get(), siam.get()});
    irkutsk->setTerritoriosColindantes(list<Territorio*>{mongolia.get(), siberia.get(), yakutsk.get(), kamchatka.get()});
    japon->setTerritoriosColindantes(list<Territorio*>{kamchatka.get(), mongolia.get()});
    kamchatka->setTerritoriosColindantes(list<Territorio*>{japon.get(), alaska.get(), mongolia.get(), irkutsk.get(), yakutsk.get()});
    mediooriente->setTerritoriosColindantes(list<Territorio*>{egipto.get(), europaDelSur.get(), ucrania.get(), afghanistan.get(), india.get()});
    mongolia->setTerritoriosColindantes(list<Territorio*>{japon.get(), china.get(), kamchatka.get(), irkutsk.get(), siberia.get()});
    siam->setTerritoriosColindantes(list<Territorio*>{india.get(), china.get(), indonesia.get()});
    siberia->setTerritoriosColindantes(list<Territorio*>{ural.get(), china.get(), mongolia.get(), irkutsk.get(), yakutsk.get()});
    ural->setTerritoriosColindantes(list<Territorio*>{ucrania.get(), afghanistan.get(), china.get(), siberia.get()});
    yakutsk->setTerritoriosColindantes(list<Territorio*>{siberia.get(), kamchatka.get(), irkutsk.get()});
    australiaOriental->setTerritoriosColindantes(list<Territorio*>{australiaOccidental.get(), nuevaGuinea.get()});
    indonesia->setTerritoriosColindantes(list<Territorio*>{siam.get(), nuevaGuinea.get(), australiaOccidental.get()});
    nuevaGuinea->setTerritoriosColindantes(list<Territorio*>{indonesia.get(), australiaOccidental.get(), australiaOriental.get()});
    australiaOccidental->setTerritoriosColindantes(list<Territorio*>{indonesia.get(), australiaOriental.get(), nuevaGuinea.get()});


    //Agregar en la lista de territorios
    listaTerritorios.push_back(alaska);
    listaTerritorios.push_back(alberta);
    listaTerritorios.push_back(americaCentral);
    listaTerritorios.push_back(estadosUnidosOrientales);
    listaTerritorios.push_back(groenlandia);
    listaTerritorios.push_back(territorioNoroccidental);
    listaTerritorios.push_back(ontario);
    listaTerritorios.push_back(quebec);
    listaTerritorios.push_back(estadosUnidosOccidentales);

    listaTerritorios.push_back(afghanistan);
    listaTerritorios.push_back(china);
    listaTerritorios.push_back(india);
    listaTerritorios.push_back(japon);
    listaTerritorios.push_back(irkutsk);
    listaTerritorios.push_back(kamchatka);
    listaTerritorios.push_back(mongolia);
    listaTerritorios.push_back(siam);
    listaTerritorios.push_back(siberia);
    listaTerritorios.push_back(ural);
    listaTerritorios.push_back(yakutsk);
    listaTerritorios.push_back(mediooriente);

    listaTerritorios.push_back(indonesia);
    listaTerritorios.push_back(granBretana);
    listaTerritorios.push_back(islandia);
    listaTerritorios.push_back(europaDelNorte);
    listaTerritorios.push_back(europaDelSur);
    listaTerritorios.push_back(ucrania);
    listaTerritorios.push_back(europaOccidental);
    listaTerritorios.push_back(escandinavia);

    listaTerritorios.push_back(africaOriental);
    listaTerritorios.push_back(congo);
    listaTerritorios.push_back(egipto);
    listaTerritorios.push_back(madagascar);
    listaTerritorios.push_back(africaDelNorte);
    listaTerritorios.push_back(africaDelSur);
    listaTerritorios.push_back(australiaOriental);
    listaTerritorios.push_back(nuevaGuinea);
    listaTerritorios.push_back(australiaOccidental);
    listaTerritorios.push_back(argentina);
    listaTerritorios.push_back(brasil);
    listaTerritorios.push_back(peru);
    listaTerritorios.push_back(venezuela);

    listaProvANorte.push_back(alaska.get());
    listaProvANorte.push_back(alberta.get());
    listaProvANorte.push_back(americaCentral.get());
    listaProvANorte.push_back(estadosUnidosOrientales.get());
    listaProvANorte.push_back(groenlandia.get());
    listaProvANorte.push_back(territorioNoroccidental.get());
    listaProvANorte.push_back(ontario.get());
    listaProvANorte.push_back(quebec.get());
    listaProvANorte.push_back(estadosUnidosOccidentales.get());

    Continente AmericaNorte("America_del_Norte", listaProvANorte);

    listaProvEuropa.push_back(granBretana.get());
    listaProvEuropa.push_back(islandia.get());
    listaProvEuropa.push_back(europaDelNorte.get());
    listaProvEuropa.push_back(escandinavia.get());
    listaProvEuropa.push_back(europaDelSur.get());
    listaProvEuropa.push_back(ucrania.get());
    listaProvEuropa.push_back(europaOccidental.get());

    Continente Europa("Europa", listaProvEuropa);

    listaProvAfrica.push_back(congo.get());
    listaProvAfrica.push_back(africaOriental.get());
    listaProvAfrica.push_back(egipto.get());
    listaProvAfrica.push_back(madagascar.get());
    listaProvAfrica.push_back(africaDelNorte.get());
    listaProvAfrica.push_back(africaDelSur.get());

    Continente Africa("Africa", listaProvAfrica);

    listaProvAsia.push_back(afghanistan.get());
    listaProvAsia.push_back(china.get());
    listaProvAsia.push_back(india.get());
    listaProvAsia.push_back(irkutsk.get());
    listaProvAsia.push_back(japon.get());
    listaProvAsia.push_back(kamchatka.get());
    listaProvAsia.push_back(mediooriente.get());
    listaProvAsia.push_back(mongolia.get());
    listaProvAsia.push_back(siam.get());
    listaProvAsia.push_back(siberia.get());
    listaProvAsia.push_back(ural.get());
    listaProvAsia.push_back(yakutsk.get());


    Continente Asia("Asia", listaProvAsia);

    listProvAustralia.push_back(australiaOriental.get());
    listProvAustralia.push_back(indonesia.get());
    listProvAustralia.push_back(nuevaGuinea.get());
    listProvAustralia.push_back(australiaOccidental.get());

    Continente Australia("Australia", listProvAustralia);

    listProvAustralia.push_back(argentina.get());
    listProvAustralia.push_back(brasil.get());
    listProvAustralia.push_back(peru.get());
    listProvAustralia.push_back(venezuela.get());

    Continente AmericaDelSur("America_del_Sur", listProvASur);

    listaContinentes.push_back(AmericaNorte);
    listaContinentes.push_back(Asia);
    listaContinentes.push_back(Europa);
    listaContinentes.push_back(Australia);
    listaContinentes.push_back(AmericaDelSur);


    // Inicialización de Cartas ---------------
    listaCartas.emplace_back("01", alaska->getNombre(), "Artilleria");
    listaCartas.emplace_back("02", americaCentral->getNombre(), "Caballeria");
    listaCartas.emplace_back("03", estadosUnidosOrientales->getNombre(), "Infanteria");
    listaCartas.emplace_back("04", groenlandia->getNombre(), "Artilleria");
    listaCartas.emplace_back("05", territorioNoroccidental->getNombre(), "Caballeria");
    listaCartas.emplace_back("06", ontario->getNombre(), "Infanteria");
    listaCartas.emplace_back("07", estadosUnidosOccidentales->getNombre(), "Artilleria");
    listaCartas.emplace_back("08", argentina->getNombre(), "Caballeria");
    listaCartas.emplace_back("09", brasil->getNombre(), "Infanteria");
    listaCartas.emplace_back("10", peru->getNombre(), "Artilleria");
    listaCartas.emplace_back("11", venezuela->getNombre(), "Caballeria");
    listaCartas.emplace_back("12", granBretana->getNombre(), "Infanteria");
    listaCartas.emplace_back("13", islandia->getNombre(), "Artilleria");
    listaCartas.emplace_back("14", europaDelNorte->getNombre(), "Caballeria");
    listaCartas.emplace_back("15", escandinavia->getNombre(), "Infanteria");
    listaCartas.emplace_back("16", europaDelSur->getNombre(), "Artilleria");
    listaCartas.emplace_back("17", ucrania->getNombre(), "Caballeria");
    listaCartas.emplace_back("18", europaOccidental->getNombre(), "Infanteria");
    listaCartas.emplace_back("19", congo->getNombre(), "Artilleria");
    listaCartas.emplace_back("20", africaOriental->getNombre(), "Caballeria");
    listaCartas.emplace_back("21", egipto->getNombre(), "Infanteria");
    listaCartas.emplace_back("22", madagascar->getNombre(), "Artilleria");
    listaCartas.emplace_back("23", africaDelNorte->getNombre(), "Caballeria");
    listaCartas.emplace_back("24", africaDelSur->getNombre(), "Infanteria");
    listaCartas.emplace_back("25", afghanistan->getNombre(), "Artilleria");
    listaCartas.emplace_back("26", china->getNombre(), "Caballeria");
    listaCartas.emplace_back("27", india->getNombre(), "Infanteria");
    listaCartas.emplace_back("28", irkutsk->getNombre(), "Artilleria");
    listaCartas.emplace_back("29", japon->getNombre(), "Caballeria");
    listaCartas.emplace_back("30", kamchatka->getNombre(), "Infanteria");
    listaCartas.emplace_back("31", mediooriente->getNombre(), "Artilleria");
    listaCartas.emplace_back("32", mongolia->getNombre(), "Caballeria");
    listaCartas.emplace_back("33", siam->getNombre(), "Infanteria");
    listaCartas.emplace_back("34", siberia->getNombre(), "Artilleria");
    listaCartas.emplace_back("35", ural->getNombre(), "Caballeria");
    listaCartas.emplace_back("36", yakutsk->getNombre(), "Infanteria");
    listaCartas.emplace_back("37", australiaOccidental->getNombre(), "Artilleria");
    listaCartas.emplace_back("38", australiaOriental->getNombre(), "Caballeria");
    listaCartas.emplace_back("39", indonesia->getNombre(), "Infanteria");
    listaCartas.emplace_back("40", nuevaGuinea->getNombre(), "Artilleria");
    listaCartas.emplace_back("41", alberta->getNombre(), "Caballeria");
    listaCartas.emplace_back("42", quebec->getNombre(), "Infanteria");
    listaCartas.emplace_back("43", venezuela->getNombre(), "Comodin");
    listaCartas.emplace_back("44", quebec->getNombre(), "Comodin");

    // Inicializo la cantidad de cartas intercambiadas
    cartasIntercambiadas = 0;
}

vector<Continente> &Risk::getListaContinentes()
{
    return listaContinentes;
}

void Risk::setListaContinentes(const vector<Continente> &listaContinentes)
{
    Risk::listaContinentes = listaContinentes;
}

vector<Carta> &Risk::getListaCartas()
{
    return listaCartas;
}

void Risk::setListaCartas(const vector<Carta> &listaCartas)
{
    Risk::listaCartas = listaCartas;
}

list<Jugador> &Risk::getListaJugadores()
{
    return listaJugadores;
}

void Risk::setListaJugadores(const list<Jugador> &listaJugadores)
{
    Risk::listaJugadores = listaJugadores;
}


int Risk::getCurrentTurn() const
{
    return currentTurn;
}

void Risk::setCurrentTurn(int currentTurn)
{
    Risk::currentTurn = currentTurn;
}

bool Risk::isGameInitialized1() const
{
    return isGameInitialized;
}

void Risk::setIsGameInitialized(bool isGameInitialized)
{
    Risk::isGameInitialized = isGameInitialized;
}

bool Risk::isGameOver1() const
{
    return isGameOver;
}

void Risk::setIsGameOver(bool isGameOver)
{
    Risk::isGameOver = isGameOver;
}

int Risk::getCartasIntercambiadas() const
{
    return cartasIntercambiadas;
}

void Risk::setCartasIntercambiadas(int cartasIntercambiadas)
{
    Risk::cartasIntercambiadas = cartasIntercambiadas;
}


const list<shared_ptr<Territorio>> &Risk::getListaTerritorios() const {
    return listaTerritorios;
}

void Risk::setListaTerritorios(const list<shared_ptr<Territorio>> &listaTerritorios) {
    Risk::listaTerritorios = listaTerritorios;
}




void Risk::eliminarUltimaCarta()
{
    listaCartas.pop_back();
}

ArbolHuffman Risk::crearArbolHuffman(map<int, int> caracteresYFrecuencias) {

    deque<NodoHuffman*> heap;


    for (const auto& pair : caracteresYFrecuencias) {
        NodoHuffman* node = new NodoHuffman(pair.second, pair.first);
        heap.push_back(node);
        push_heap(heap.begin(),heap.end(), NodoHuffman::comparadorNodosHuffman());
    }

    ArbolHuffman arbolHuffman(heap);

    return arbolHuffman;
}



string Risk::contenidoDeLaPartidaEnTexto() {
    string salidaArchivo;

    //SECCION JUGADORES
    salidaArchivo += "jugadores ";

    //Guarda cantidad de jugadores
    salidaArchivo += to_string(listaJugadores.size()) + " ";

    //Informacion de jugadores
    for(Jugador &jugador:listaJugadores){

        salidaArchivo += jugador.getNombre() + " ";
        salidaArchivo += jugador.getColor() + " ";

        //Guarda cantidad de territorios
        salidaArchivo += to_string(jugador.getTerritoriosOcupados().size()) + " ";

        //Guarda el estado actual de todos los territorios del jugador
        for(Territorio* territorio : jugador.getTerritoriosOcupados()){
            salidaArchivo += territorio->getNombre() + " ";
            salidaArchivo += to_string(territorio->getTropas().size()) + " ";

            //Informacion de las tropas
            for(Tropa &tropa : territorio->getTropas()){
                salidaArchivo += tropa.getTipoTropa() + " ";
                salidaArchivo += tropa.getColor() + " ";
                salidaArchivo += to_string(tropa.getValorTropa())+ " ";
            }
        }

        //Guarda el estado actual de las cartas del jugador
        salidaArchivo += to_string(jugador.getCartas().size())+ " ";

        for(const Carta &carta : jugador.getCartas()){
            salidaArchivo += carta.getIdCarta() + " ";
        }
    }

    salidaArchivo += to_string(cartasIntercambiadas) + " ";
    salidaArchivo += to_string(currentTurn);

    return salidaArchivo;
}


void Risk::cargarEstadoDesdeTexto(const string& contenidoArchivo) {
    stringstream ss(contenidoArchivo);
    string palabra;

    ss >> palabra; // Ignorar "jugadores"
    int numJugadores;
    ss >> numJugadores;

    listaJugadores.clear();

    for (int i = 1; i <= numJugadores; i++) {
        string nombreJugador;
        string colorJugador;
        int numTerritorios;
        ss >> nombreJugador >> colorJugador >> numTerritorios;

        Jugador jugador(nombreJugador, i, colorJugador);

        for (int j = 0; j < numTerritorios; j++) {
            string nombreTerritorio;
            int numTropas;
            ss >> nombreTerritorio >> numTropas;

            shared_ptr<Territorio> territorio;

            for (const auto& t : listaTerritorios) {
                if (t->getNombre() == nombreTerritorio) {
                    territorio = t;
                    break;
                }
            }

            if (territorio != nullptr) {
                for (int k = 0; k < numTropas; k++) {
                    string tipoTropa;
                    string colorTropa;
                    int valorTropa;
                    ss >> tipoTropa >> colorTropa >> valorTropa;

                    Tropa tropa(tipoTropa, valorTropa, colorTropa);
                    territorio->agregarTropa(tropa);
                }
                jugador.agregarTerritorio(territorio.get());
            }
        }

        int numCartas;
        ss >> numCartas;

        for (int j = 0; j < numCartas; j++) {
            string idCarta;
            ss >> idCarta;

            for(auto it = listaCartas.begin();it!=listaCartas.end();it++){
                if(it->getIdCarta() == idCarta){
                    jugador.agregarCarta(*it);
                    it = listaCartas.erase(it);
                    break;
                }
            }
        }

        listaJugadores.push_back(jugador);
    }

    ss >> cartasIntercambiadas;
    ss >> currentTurn;

}

Grafo Risk::crearGrafo() {

    Grafo grafo;

    //Crea las vertices
    for(const shared_ptr<Territorio>& territorioP : this->listaTerritorios){
        Territorio* territorio = territorioP.get();
        VerticeGrafo verticeGrafo(territorio);
        grafo.agregarVertice(verticeGrafo);
    }

    //Crea las relaciones
    for(VerticeGrafo& verticeGrafo: grafo.getVertices()){
        for(Territorio* territorioAdyacente: verticeGrafo.getDato()->getTerritoriosColindantes()){
            verticeGrafo.agregarPaisColidante(territorioAdyacente->getNombre(), territorioAdyacente->contarTropas());
        }
    }

    return grafo;
}

