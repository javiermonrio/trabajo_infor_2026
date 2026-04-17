#pragma once
#include "Tablero.h"

class Mundo {
private:
    Tablero tablero;
    int pasoCiclo;
    int jugadoresQueHanTerminado; // 0, 1 o 2


    void avanzarCicloGlobal();

public:
    Mundo();

    // El Main llamará a esto cuando un jugador pulse una tecla de "Terminar Turno"
    void finalizarTurnoJugador();

    void dibujar(sf::RenderWindow& window);
};
