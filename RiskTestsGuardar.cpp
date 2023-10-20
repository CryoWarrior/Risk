// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
// This includes the catch.hpp file
#include "Librerias/catch.hpp"
#include "Comandos.h"
#include "Risk.h"

#include <fstream>
#include <iostream>
#include <string>
#include "Risk.h"

// Include the header file of the class that you are testing

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
        Comandos comandos = Comandos();

        comandos.guardarEstadoJuego(risk, nombreArchivo+".txt");

        fstream archivoCreado(nombreArchivo);
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

TEST_CASE("Leer archivos correctamente"){
    SECTION("Carga de partida archivo de texto"){
        string nombreArchivo = "archivoTexto";

        Risk risk = Risk();
        Comandos comandos = Comandos();

        comandos.guardarEstadoJuego(risk, nombreArchivo+".txt");

        fstream archivoCreado(nombreArchivo);
        if(archivoCreado.is_open()){


        }

    }


    SECTION("Carga de partida archivo binario"){
        string nombreArchivo = "archivoComprimido";
        bool archivoCreadoCorrectamente = false;

        Risk risk = Risk();
        Comandos comandos = Comandos();

        comandos.guardarEstadoComprimido(risk, nombreArchivo);

        fstream archivoCreado(nombreArchivo+".bin");
        if(archivoCreado.is_open()){
            archivoCreadoCorrectamente = true;
        }
    }
}