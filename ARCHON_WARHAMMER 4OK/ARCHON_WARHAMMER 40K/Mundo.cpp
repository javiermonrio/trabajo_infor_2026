#include "Mundo.h"

Mundo::Mundo() : pasoCiclo(0), jugadoresQueHanTerminado(0) {}

void Mundo::finalizarTurnoJugador() {
    jugadoresQueHanTerminado++;

    // Si ambos jugadores han terminado, avanzamos el ciclo
    if (jugadoresQueHanTerminado >= 2) {
        avanzarCicloGlobal();
        jugadoresQueHanTerminado = 0; // Reiniciamos contador para la siguiente ronda
    }
}

void Mundo::avanzarCicloGlobal() {

    pasoCiclo = (pasoCiclo + 1) % 12;

    //Definimos la secuencia
    ColorActual secuencia[] = {
        ColorActual::BLANCO_PICO, ColorActual::BLANCO, ColorActual::GRIS_CLARO,
        ColorActual::GRIS_MEDIO, ColorActual::GRIS_OSCURO, ColorActual::NEGRO,
        ColorActual::NEGRO_PICO, ColorActual::NEGRO, ColorActual::GRIS_OSCURO,
        ColorActual::GRIS_MEDIO, ColorActual::GRIS_CLARO, ColorActual::BLANCO
    };

    tablero.actualizarColoresCambiantes(secuencia[pasoCiclo]);
}

void Mundo::dibujar(sf::RenderWindow& window) {
    tablero.dibujar(window);
}