#include <SFML/Graphics.hpp>
#include "Mundo.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 650), "Archon 40k - Sistema de Mundos");
    Mundo miMundo;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::KeyPressed) {
                // Simulamos que el jugador actual termina su turno (pulsa Espacio)
                if (event.key.code == sf::Keyboard::Space) {
                    miMundo.finalizarTurnoJugador();
                }
            }
        }

        window.clear();
        miMundo.dibujar(window);
        window.display();
    }
    return 0;
}