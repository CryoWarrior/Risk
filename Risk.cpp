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

void Risk::iniciarElementosJuego() {

// Agrega territorios a los continentes y a Risk
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

    //Agregar continentes
    listaContinentes.push_back(AmericaNorte);
    listaContinentes.push_back(Asia);
    listaContinentes.push_back(Europa);
    listaContinentes.push_back(Australia);
    listaContinentes.push_back(AmericaDelSur);

    //Poniendo territorios colindantes
    alaska.setTerritoriosColindantes(list<Territorio>{kamchatka,territorioNoroccidental,alberta});
    alberta.setTerritoriosColindantes(list<Territorio>{alaska,territorioNoroccidental,ontario,estadosUnidosOccidentales});
    americaCentral.setTerritoriosColindantes(list<Territorio>{estadosUnidosOccidentales, estadosUnidosOrientales, venezuela});
    estadosUnidosOrientales.setTerritoriosColindantes(list<Territorio>{americaCentral, estadosUnidosOccidentales, ontario, quebec});
    groenlandia.setTerritoriosColindantes(list<Territorio>{islandia,territorioNoroccidental,ontario, quebec});
    territorioNoroccidental.setTerritoriosColindantes(list<Territorio>{alaska,groenlandia,alberta, ontario});
    ontario.setTerritoriosColindantes(list<Territorio>{quebec,territorioNoroccidental,groenlandia, alberta, estadosUnidosOccidentales, estadosUnidosOrientales});
    quebec.setTerritoriosColindantes(list<Territorio>{groenlandia,ontario,estadosUnidosOrientales});
    estadosUnidosOccidentales.setTerritoriosColindantes(list<Territorio>{americaCentral,estadosUnidosOrientales,alberta, ontario});
    venezuela.setTerritoriosColindantes(list<Territorio>{americaCentral,brasil,peru});
    peru.setTerritoriosColindantes(list<Territorio>{venezuela,brasil,argentina});
    argentina.setTerritoriosColindantes(list<Territorio>{brasil,peru});
    brasil.setTerritoriosColindantes(list<Territorio>{venezuela,argentina,peru, africaDelNorte});
    africaDelNorte.setTerritoriosColindantes(list<Territorio>{europaOccidental,europaDelSur,brasil, egipto, congo, africaOriental});
    congo.setTerritoriosColindantes(list<Territorio>{africaDelNorte,africaOriental,africaDelSur});
    africaOriental.setTerritoriosColindantes(list<Territorio>{madagascar,congo,africaDelSur, africaDelNorte,egipto});
    africaDelSur.setTerritoriosColindantes(list<Territorio>{congo,madagascar,africaOriental});
    madagascar.setTerritoriosColindantes(list<Territorio>{africaOriental,africaDelSur});
    egipto.setTerritoriosColindantes(list<Territorio>{africaDelNorte,africaOriental,europaDelSur, mediooriente});
    granBretana.setTerritoriosColindantes(list<Territorio>{islandia,europaOccidental,europaDelNorte, escandinavia});
    islandia.setTerritoriosColindantes(list<Territorio>{groenlandia,granBretana,escandinavia});
    europaDelNorte.setTerritoriosColindantes(list<Territorio>{granBretana,europaOccidental,europaDelSur, ucrania, escandinavia});
    escandinavia.setTerritoriosColindantes(list<Territorio>{islandia,granBretana,europaDelNorte, ucrania});
    europaDelSur.setTerritoriosColindantes(list<Territorio>{africaDelNorte,europaOccidental,europaDelNorte, egipto, ucrania, mediooriente});
    europaOccidental.setTerritoriosColindantes(list<Territorio>{granBretana,africaDelNorte,europaDelNorte, europaDelSur});
    ucrania.setTerritoriosColindantes(list<Territorio>{europaDelSur,mediooriente,europaDelNorte, escandinavia, ural, escandinavia});
    afghanistan.setTerritoriosColindantes(list<Territorio>{ural,ucrania,mediooriente, india, china});
    china.setTerritoriosColindantes(list<Territorio>{afghanistan,india,siam, mongolia, ural, siberia});
    india.setTerritoriosColindantes(list<Territorio>{afghanistan,mediooriente,china, siam});
    irkutsk.setTerritoriosColindantes(list<Territorio>{mongolia,siberia,yakutsk, kamchatka});
    japon.setTerritoriosColindantes(list<Territorio>{kamchatka,mongolia});
    kamchatka.setTerritoriosColindantes(list<Territorio>{japon,alaska,mongolia, irkutsk, yakutsk});
    mediooriente.setTerritoriosColindantes(list<Territorio>{egipto,europaDelSur,ucrania, afghanistan, india});
    mongolia.setTerritoriosColindantes(list<Territorio>{japon,china,kamchatka, irkutsk, siberia});
    siam.setTerritoriosColindantes(list<Territorio>{india,china,indonesia});
    siberia.setTerritoriosColindantes(list<Territorio>{ural,china,mongolia, irkutsk, yakutsk});
    ural.setTerritoriosColindantes(list<Territorio>{ucrania,afghanistan,china, siberia});
    yakutsk.setTerritoriosColindantes(list<Territorio>{siberia,kamchatka, irkutsk});
    australiaOriental.setTerritoriosColindantes(list<Territorio>{australiaOccidental,nuevaGuinea});
    indonesia.setTerritoriosColindantes(list<Territorio>{siam,nuevaGuinea,australiaOccidental});
    nuevaGuinea.setTerritoriosColindantes(list<Territorio>{indonesia,australiaOccidental,australiaOriental});
    australiaOccidental.setTerritoriosColindantes(list<Territorio>{indonesia,australiaOriental,nuevaGuinea});



//Inicialización de Cartas ---------------
    listaCartas.emplace_back("01",alaska.getNombre(),"Artilleria");
    listaCartas.emplace_back("02",americaCentral.getNombre(),"Caballeria");
    listaCartas.emplace_back("03",estadosUnidosOrientales.getNombre(),"Infanteria");
    listaCartas.emplace_back("04",groenlandia.getNombre(),"Artilleria");
    listaCartas.emplace_back("05",territorioNoroccidental.getNombre(),"Caballeria");
    listaCartas.emplace_back("06",ontario.getNombre(),"Infanteria");
    listaCartas.emplace_back("07",estadosUnidosOccidentales.getNombre(),"Artilleria");
    listaCartas.emplace_back("08",argentina.getNombre(),"Caballeria");
    listaCartas.emplace_back("09",brasil.getNombre(),"Infanteria");
    listaCartas.emplace_back("10",peru.getNombre(),"Artilleria");
    listaCartas.emplace_back("11",venezuela.getNombre(),"Caballeria");
    listaCartas.emplace_back("12",granBretana.getNombre(),"Infanteria");
    listaCartas.emplace_back("13",islandia.getNombre(),"Artilleria");
    listaCartas.emplace_back("14",europaDelNorte.getNombre(),"Caballeria");
    listaCartas.emplace_back("15",escandinavia.getNombre(),"Infanteria");
    listaCartas.emplace_back("16",europaDelSur.getNombre(),"Artilleria");
    listaCartas.emplace_back("17",ucrania.getNombre(),"Caballeria");
    listaCartas.emplace_back("18",europaOccidental.getNombre(),"Infanteria");
    listaCartas.emplace_back("19",congo.getNombre(),"Artilleria");
    listaCartas.emplace_back("20",africaOriental.getNombre(),"Caballeria");
    listaCartas.emplace_back("21",egipto.getNombre(),"Infanteria");
    listaCartas.emplace_back("22",madagascar.getNombre(),"Artilleria");
    listaCartas.emplace_back("23",africaDelNorte.getNombre(),"Caballeria");
    listaCartas.emplace_back("24",africaDelSur.getNombre(),"Infanteria");
    listaCartas.emplace_back("25",afghanistan.getNombre(),"Artilleria");
    listaCartas.emplace_back("26",china.getNombre(),"Caballeria");
    listaCartas.emplace_back("27",india.getNombre(),"Infanteria");
    listaCartas.emplace_back("28",irkutsk.getNombre(),"Artilleria");
    listaCartas.emplace_back("29",japon.getNombre(),"Caballeria");
    listaCartas.emplace_back("30",kamchatka.getNombre(),"Infanteria");
    listaCartas.emplace_back("31",mediooriente.getNombre(),"Artilleria");
    listaCartas.emplace_back("32",mongolia.getNombre(),"Caballeria");
    listaCartas.emplace_back("33",siam.getNombre(),"Infanteria");
    listaCartas.emplace_back("34",siberia.getNombre(),"Artilleria");
    listaCartas.emplace_back("35",ural.getNombre(),"Caballeria");
    listaCartas.emplace_back("36",yakutsk.getNombre(),"Infanteria");
    listaCartas.emplace_back("37",australiaOccidental.getNombre(),"Artilleria");
    listaCartas.emplace_back("38",australiaOriental.getNombre(),"Caballeria");
    listaCartas.emplace_back("39",indonesia.getNombre(),"Infanteria");
    listaCartas.emplace_back("40",nuevaGuinea.getNombre(),"Artilleria");
    listaCartas.emplace_back("41",alberta.getNombre(),"Caballeria");
    listaCartas.emplace_back("42",quebec.getNombre(),"Infanteria");
    listaCartas.emplace_back("43",quebec.getNombre(),"Comodin");
    listaCartas.emplace_back("44",quebec.getNombre(),"Comodin");

}
