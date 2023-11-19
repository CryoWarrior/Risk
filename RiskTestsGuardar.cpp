// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
// This includes the catch.hpp file
#include "Librerias/catch.hpp"
#include "Comandos.h"
#include "Risk.h"

#include <fstream>
#include <iostream>
#include <string>

// Include the header file of the class that you are testing

void inicializarJuegoQuemado(Risk &risk);

// Create a test case
TEST_CASE("Creacion de archivos")
{
    // Create a section, this is just to organize your tests
    SECTION("Creacion de archivo de texto")
    {
        INFO("Seccion: Creacion de archivo de texto");
        INFO("Se guarda el estado del juego y el archivo se vuelve a abrir para revisar si fue creado correctamente");


        string nombreArchivo = "archivoTexto";
        bool archivoCreadoCorrectamente = false;

        Risk risk = Risk();
        risk.setIsGameInitialized(true);
        Comandos comandos = Comandos();

        comandos.guardarEstadoJuego(risk, nombreArchivo);

        fstream archivoCreado(nombreArchivo+".txt");
        if(archivoCreado.is_open()){
            archivoCreadoCorrectamente = true;
        }

        // Check if the result of the function is the same as the expected value,
        // if they are not, the test will fail.
        REQUIRE(archivoCreadoCorrectamente == true);
    }

        // Create a section, this is just to organize your tests
    SECTION("Creacion de archivo binario")
    {
        INFO("Seccion: Creacion de archivo binario");
        INFO("Se guarda el estado del juego comprimido y el archivo se vuelve a abrir para revisar si fue creado correctamente");


        string nombreArchivo = "archivoComprimido";
        bool archivoCreadoCorrectamente = false;

        Risk risk = Risk();
        risk.setIsGameInitialized(true);
        Comandos comandos = Comandos();

        comandos.guardarEstadoComprimido(risk, nombreArchivo);

        fstream archivoCreado(nombreArchivo+".bin");
        if(archivoCreado.is_open()){
            archivoCreadoCorrectamente = true;
        }

        // Check if the result of the function is the same as the expected value,
        // if they are not, the test will fail.
        REQUIRE(archivoCreadoCorrectamente == true);
    }
}

TEST_CASE("Guardar contenido partida correctamente"){
    SECTION("Guardar contenido partida en archivo de texto") {
        std::string nombreArchivo = "hola";
        Risk risk = Risk();


        inicializarJuegoQuemado(risk);

        Comandos comandos;
        comandos.guardarEstadoJuego(risk, nombreArchivo);

        string llegada;
        string linea;

        std::ifstream archivo(nombreArchivo+".txt");
        getline(archivo,linea);
        getline(archivo,linea);
        archivo.close();

        std::istringstream iss(linea);
        std::string palabra;

        string contenidoLeido;

        for(int i = 0; i<3;i++){
            iss >> llegada;
            contenidoLeido += llegada +" ";

        }

        std::string contenidoEsperado = "jugadores 3 Cami ";

        REQUIRE(contenidoLeido == contenidoEsperado);
    }


    SECTION("Guardar contenido partida en archivo de texto") {
        std::string nombreArchivo = "hola";
        Risk risk = Risk();


        inicializarJuegoQuemado(risk);

        Comandos comandos;
        comandos.guardarEstadoComprimido(risk, nombreArchivo);


        std::ifstream archivo(nombreArchivo+".bin", ios::in | ios::binary);
        uint16_t contadorDiferentesCaracteres;
        archivo.read(reinterpret_cast<char*>(&contadorDiferentesCaracteres), sizeof(uint16_t));
        int contenidoLeido = static_cast<int>(contadorDiferentesCaracteres);
        archivo.close();


        int contenidoEsperado = 22;


        REQUIRE(contenidoLeido == contenidoEsperado);
    }
}

/*
TEST_CASE("Lectura de archivos")
{
    SECTION("Lectura de archivo de texto")
    {
        INFO("Seccion: Lectura de archivo de texto");
        INFO("Se lee el estado del juego desde un archivo de texto existente");

        string nombreArchivo = "archivoTexto";
        bool lecturaExitosa = false;

        Risk risk = Risk();
        Comandos comandos = Comandos();

        // Asegúrate de que exista un archivo de texto con contenido válido para la prueba
        ofstream archivoTexto(nombreArchivo + ".txt", ios::out);
        archivoTexto << "Risk 2 Jugadores";
        archivoTexto.close();

        lecturaExitosa = comandos.leerArchivoTexto(risk, nombreArchivo);

        // Verificar si la lectura es exitosa y si los datos leídos son correctos
        REQUIRE(lecturaExitosa==true);
    }

    SECTION("Lectura de archivo binario")
    {
        INFO("Seccion: Lectura de archivo binario");
        INFO("Se lee el estado del juego desde un archivo binario existente");

        string nombreArchivo = "archivoBinario";
        bool lecturaExitosa = false;

        Risk risk = Risk();
        Comandos comandos = Comandos();

        // Asegúrate de que exista un archivo binario con contenido válido para la prueba
        fstream archivoBinario(nombreArchivo + ".bin", ios::out | ios::binary);
        // Escribe datos binarios válidos para la prueba
        char datosBinarios[] = {0x52, 0x69, 0x73, 0x6B, 0x20, 0x32, 0x20, 0x4A, 0x75, 0x67, 0x61, 0x64, 0x6F, 0x72, 0x65, 0x73};
        archivoBinario.write(datosBinarios, sizeof(datosBinarios));
        archivoBinario.close();

        lecturaExitosa = comandos.leerComprimido(risk, nombreArchivo);

        // Verificar si la lectura es exitosa y si los datos leídos son correctos
        REQUIRE(lecturaExitosa == true);
        // Datos esperados en formato de cadena
        string datosEsperados = "Risk 2 Jugadores";
    }
}
*/


void inicializarJuegoQuemado(Risk &risk){
    risk.setIsGameInitialized(true);




    Jugador jugador1;
    jugador1.setIdJugador(1);
    jugador1.setNombre("Cami");
    jugador1.setColor("azul");

    Jugador jugador2;
    jugador2.setIdJugador(2);
    jugador2.setNombre("Ale");
    jugador2.setColor("rojo");

    Jugador jugador3;
    jugador3.setIdJugador(3);
    jugador3.setNombre("Ripa");
    jugador3.setColor("negro");

    risk.getListaJugadores().push_back(jugador1);
    risk.getListaJugadores().push_back(jugador2);
    risk.getListaJugadores().push_back(jugador3);

    list<Territorio*> territoriosDisponibles;

    for (auto territorio : risk.getListaTerritorios()) {
        territoriosDisponibles.push_back(territorio.get());
    }

    auto iterterritoriosDisponibles = territoriosDisponibles.begin();

    auto iterJugadorActual = risk.getListaJugadores().begin();
    while (!territoriosDisponibles.empty())
    {

        Jugador &jugadorActual = *iterJugadorActual;
        Territorio &territorioActual = **iterterritoriosDisponibles;

        Tropa infanteria("Infanteria", 1, jugadorActual.getColor());
        territorioActual.getTropas().push_back(infanteria);

        iterterritoriosDisponibles = territoriosDisponibles.erase(iterterritoriosDisponibles);


        ++iterJugadorActual;
        if (iterJugadorActual == risk.getListaJugadores().end())
        {
            iterJugadorActual = risk.getListaJugadores().begin();
        }
    }

    risk.setCurrentTurn(risk.getListaJugadores().front().getIdJugador());

}