#pragma once
#include <SFML/Graphics.hpp>

enum class TipoCasilla { PERMANENTE_LUZ, PERMANENTE_OSCURIDAD, CAMBIANTE, POWER_POINT };
enum class ColorActual { BLANCO_PICO, BLANCO, GRIS_CLARO, GRIS_MEDIO, GRIS_OSCURO, NEGRO, NEGRO_PICO };

struct Casilla {
    TipoCasilla tipo;
    ColorActual colorVisual;
};

class Tablero {
private:
    Casilla matriz[9][9];

public:
    Tablero();
    // El tablero ya no decide cuándo cambiar, Mundo le dice qué color usar
    void actualizarColoresCambiantes(ColorActual nuevoColor);
    void dibujar(sf::RenderWindow& window);
};


