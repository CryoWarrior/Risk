#include "Risk.h"

 vector<Continente> &Risk::getListaContinentes()  {
    return listaContinentes;
}

void Risk::setListaContinentes(const vector<Continente> &listaContinentes) {
    Risk::listaContinentes = listaContinentes;
}

 vector<Tropa> &Risk::getListaTropas()  {
    return listaTropas;
}

void Risk::setListaTropas(const vector<Tropa> &listaTropas) {
    Risk::listaTropas = listaTropas;
}

 vector<Carta> &Risk::getListaCartas()  {
    return listaCartas;
}

void Risk::setListaCartas(const vector<Carta> &listaCartas) {
    Risk::listaCartas = listaCartas;
}

 list<Jugador> &Risk::getListaJugadores()  {
    return listaJugadores;
}

void Risk::setListaJugadores(const list<Jugador> &listaJugadores) {
    Risk::listaJugadores = listaJugadores;
}

list<Territorio> &Risk::getListaTerritorios() {
    return listaTerritorios;
}

void Risk::setListaTerritorios(const list<Territorio> &listaTerritorios) {
    Risk::listaTerritorios = listaTerritorios;
}

Risk::Risk() {}

int Risk::getCurrentTurn() const {
    return currentTurn;
}

void Risk::setCurrentTurn(int currentTurn) {
    Risk::currentTurn = currentTurn;
}

bool Risk::isGameInitialized1() const {
    return isGameInitialized;
}

void Risk::setIsGameInitialized(bool isGameInitialized) {
    Risk::isGameInitialized = isGameInitialized;
}

bool Risk::isGameOver1() const {
    return isGameOver;
}

void Risk::setIsGameOver(bool isGameOver) {
    Risk::isGameOver = isGameOver;
}

void Risk::elementosJuego() {

// Inicialización de Territorios y continentes
    listaTerritorios ;

    // América del Norte
    list<Territorio> listaProvANorte;

    Territorio alaska("Alaska", {});
    Territorio alberta("Alberta", {});
    Territorio americaCentral("America Central", {});
    Territorio estadosUnidosOrientales("Estados Unidos Orientales", {});
    Territorio groenlandia("Groenlandia", {});
    Territorio territorioNoroccidental("Territorio Noroccidental", {});
    Territorio ontario("Ontario", {});
    Territorio quebec("Quebec", {});
    Territorio estadosUnidosOccidentales("Estados Unidos Occidentales", {});

    listaTerritorios.push_back(alaska);
    listaProvANorte.push_back(alaska);
    listaTerritorios.push_back(alberta);
    listaProvANorte.push_back(alberta);
    listaTerritorios.push_back(americaCentral);
    listaProvANorte.push_back(americaCentral);
    listaTerritorios.push_back(estadosUnidosOrientales);
    listaProvANorte.push_back(estadosUnidosOrientales);
    listaTerritorios.push_back(groenlandia);
    listaProvANorte.push_back(groenlandia);
    listaTerritorios.push_back(territorioNoroccidental);
    listaProvANorte.push_back(territorioNoroccidental);
    listaTerritorios.push_back(ontario);
    listaProvANorte.push_back(ontario);
    listaTerritorios.push_back(quebec);
    listaProvANorte.push_back(quebec);
    listaTerritorios.push_back(estadosUnidosOccidentales);
    listaProvANorte.push_back(estadosUnidosOccidentales);

    Continente AmericaNorte("America del norte", listaProvANorte);

    // Asia
    list<Territorio> listaProvAsia;

    Territorio afghanistan("Afghanistan", {});\
    Territorio china("China", {});
    Territorio india("India", {});
    Territorio irkutsk("Irkutsk", {});
    Territorio japon("Japon", {});
    Territorio kamchatka("Kamchatka", {});
    Territorio mediooriente("Medio Oriente", {});
    Territorio mongolia("Mongolia", {});
    Territorio siam("Siam", {});
    Territorio siberia("Siberia", {});
    Territorio ural("Ural", {});
    Territorio yakutsk("Yakutsk", {});

    listaTerritorios.push_back(afghanistan);
    listaProvAsia.push_back(afghanistan);
    listaTerritorios.push_back(china);
    listaProvAsia.push_back(china);
    listaTerritorios.push_back(india);
    listaProvAsia.push_back(india);
    listaTerritorios.push_back(irkutsk);
    listaProvAsia.push_back(irkutsk);
    listaTerritorios.push_back(japon);
    listaProvAsia.push_back(japon);
    listaTerritorios.push_back(kamchatka);
    listaProvAsia.push_back(kamchatka);
    listaTerritorios.push_back(mediooriente);
    listaProvAsia.push_back(mediooriente);
    listaTerritorios.push_back(mongolia);
    listaProvAsia.push_back(mongolia);
    listaTerritorios.push_back(siam);
    listaProvAsia.push_back(siam);
    listaTerritorios.push_back(siberia);
    listaProvAsia.push_back(siberia);
    listaTerritorios.push_back(ural);
    listaProvAsia.push_back(ural);
    listaTerritorios.push_back(yakutsk);
    listaProvAsia.push_back(yakutsk);

    Continente Asia("Asia", listaProvAsia);

    //Europa
    list<Territorio> listaProvEuropa;

    Territorio granBretana("Gran Bretana", {});\
    Territorio islandia("Islandia", {});
    Territorio europaDelNorte("Europa del Norte", {});
    Territorio escandinavia("Escandinavia", {});
    Territorio europaDelSur("Europa del Sur", {});
    Territorio ucrania("Ucrania", {});
    Territorio europaOccidental(" Europa Occidental", {});

    listaTerritorios.push_back(granBretana);
    listaProvEuropa.push_back(granBretana);
    listaTerritorios.push_back(islandia);
    listaProvEuropa.push_back(islandia);
    listaTerritorios.push_back(europaDelNorte);
    listaProvEuropa.push_back(europaDelNorte);
    listaTerritorios.push_back(escandinavia);
    listaProvEuropa.push_back(escandinavia);
    listaTerritorios.push_back(europaDelSur);
    listaProvEuropa.push_back(europaDelSur);
    listaTerritorios.push_back(ucrania);
    listaProvEuropa.push_back(ucrania);
    listaTerritorios.push_back(europaOccidental);
    listaProvEuropa.push_back(europaOccidental);

    Continente Europa("Europa", listaProvEuropa);

    //Africa

    list<Territorio> listaProvAfrica;

    Territorio congo("Congo", {});
    Territorio africaOriental("Africa Oriental", {});
    Territorio egipto("Egipto", {});
    Territorio madagascar("Madagascar", {});
    Territorio africaDelNorte("Africa del Norte", {});
    Territorio africaDelSur("Africa del Sur", {});

    listaTerritorios.push_back(congo);
    listaProvAfrica.push_back(congo);
    listaTerritorios.push_back(africaOriental);
    listaProvAfrica.push_back(africaOriental);
    listaTerritorios.push_back(egipto);
    listaProvAfrica.push_back(egipto);
    listaTerritorios.push_back(madagascar);
    listaProvAfrica.push_back(madagascar);
    listaTerritorios.push_back(africaDelNorte);
    listaProvAfrica.push_back(africaDelNorte);
    listaTerritorios.push_back(africaDelSur);
    listaProvAfrica.push_back(africaDelSur);

    Continente Africa("Africa", listaProvAfrica);

    //Australia
    list<Territorio> listProvAustralia;

    Territorio australiaOriental("Australia Oriental", {});
    Territorio indonesia("Indonesia", {});
    Territorio nuevaGuinea("Nueva Guinea", {});
    Territorio australiaOccidental("Australia Occidental", {});

    listaTerritorios.push_back(australiaOriental);
    listProvAustralia.push_back(australiaOriental);
    listaTerritorios.push_back(indonesia);
    listProvAustralia.push_back(indonesia);
    listaTerritorios.push_back(nuevaGuinea);
    listProvAustralia.push_back(nuevaGuinea);
    listaTerritorios.push_back(australiaOccidental);
    listProvAustralia.push_back(australiaOccidental);

    Continente Australia("Australia", listProvAustralia);

    //America del sur
    list<Territorio> listProvASur;

    Territorio argentina("Argentina", {});
    Territorio brasil("Brasil", {});
    Territorio peru("Peru", {});
    Territorio venezuela("Venezuela", {});

    listaTerritorios.push_back(argentina);
    listProvAustralia.push_back(argentina);
    listaTerritorios.push_back(brasil);
    listProvAustralia.push_back(brasil);
    listaTerritorios.push_back(peru);
    listProvAustralia.push_back(peru);
    listaTerritorios.push_back(venezuela);
    listProvAustralia.push_back(venezuela);

    Continente AmericaDelSur("America del Sur", listProvASur);

//Inicialización de Cartas ---------------
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");

}
