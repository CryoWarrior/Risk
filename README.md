# Risk
Este proyecto tiene como objetivo la creación de una herramienta  de software que sirva como ayuda para los jugadores de Risk.

## Codigo de ejecución
g++ -c Carta.cpp -o Carta.o

g++ -c Comandos.cpp -o Comandos.o

g++ -c Continente.cpp -o Continente.o

g++ -c Jugador.cpp -o Jugador.o

g++ -c Risk.cpp -o Risk.o

g++ -c Territorio.cpp -o Territorio.o

g++ -c Tropa.cpp -o Tropa.o

g++ -c main.cpp -o main.o

g++ Carta.o Comandos.o Continente.o Jugador.o Risk.o Territorio.o Tropa.o main.o -o JuegoRisk

## Authors

- [@CryoWarrior](https://github.com/CryoWarrior)
- [@Luquinra](https://github.com/Luquinra)
- [@Sofia19c](https://github.com/Sofia19c)
