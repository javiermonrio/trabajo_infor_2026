#include "Tablero.h"
#include <SFML/Graphics.hpp>

// El constructor que fabrica el mapa inicial
Tablero::Tablero() {
    int mapa[9][9] = {
        {1, 0, 1, 2, 3, 2, 0, 1, 0},
        {0, 1, 2, 0, 2, 1, 2, 0, 1},
        {1, 2, 0, 1, 2, 0, 1, 2, 0},
        {2, 0, 1, 0, 2, 1, 0, 1, 2},
        {3, 2, 2, 2, 3, 2, 2, 2, 3},
        {2, 0, 1, 0, 2, 1, 0, 1, 2},
        {1, 2, 0, 1, 2, 0, 1, 2, 0},
        {0, 1, 2, 0, 2, 1, 2, 0, 1},
        {1, 0, 1, 2, 3, 2, 0, 1, 0}
    };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            // Asignamos el tipo según el valor en el mapa
            switch (mapa[i][j]) {
            case 0: matriz[i][j].tipo = TipoCasilla::PERMANENTE_LUZ;      break;
            case 1: matriz[i][j].tipo = TipoCasilla::PERMANENTE_OSCURIDAD; break;
            case 2: matriz[i][j].tipo = TipoCasilla::CAMBIANTE;           break;
            case 3: matriz[i][j].tipo = TipoCasilla::POWER_POINT;         break;
            }

            // Colores iniciales por defecto
            if (matriz[i][j].tipo == TipoCasilla::PERMANENTE_OSCURIDAD)
                matriz[i][j].colorVisual = ColorActual::NEGRO_PICO;
            else
                matriz[i][j].colorVisual = ColorActual::BLANCO_PICO;
        }
    }
}

// metodo que actualiza los colores cambiantes del tablero
void Tablero::actualizarColoresCambiantes(ColorActual nuevoColor) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (matriz[i][j].tipo == TipoCasilla::CAMBIANTE) {
                matriz[i][j].colorVisual = nuevoColor;
            }
        }
    }
}

void Tablero::dibujar(sf::RenderWindow& window) { //Creación tablero
    float tamCasilla = 60.f;
    sf::RectangleShape cuadro(sf::Vector2f(tamCasilla - 2.f, tamCasilla - 2.f));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sf::Color colorSF;
            // Traducimos el enum a sf::Color (mismo switch de antes)
            switch (matriz[i][j].colorVisual) {
            case ColorActual::BLANCO_PICO: colorSF = sf::Color(255, 255, 255); break;
            case ColorActual::BLANCO:      colorSF = sf::Color(220, 220, 220); break;
            case ColorActual::GRIS_CLARO:  colorSF = sf::Color(180, 180, 180); break;
            case ColorActual::GRIS_MEDIO:  colorSF = sf::Color(120, 120, 120); break;
            case ColorActual::GRIS_OSCURO: colorSF = sf::Color(60, 60, 60);    break;
            case ColorActual::NEGRO:       colorSF = sf::Color(30, 30, 30);    break;
            case ColorActual::NEGRO_PICO:  colorSF = sf::Color(0, 0, 0);       break;
            }

            cuadro.setFillColor(colorSF);
            cuadro.setPosition(j * tamCasilla + 50.f, i * tamCasilla + 30.f);
            window.draw(cuadro);
        }
    }
}