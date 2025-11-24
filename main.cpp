/**
* @file main.cpp
 * @brief Punto de entrada principal para el proyecto Dots and Boxes.
 * @date 22/11/2025
 * @version 1.0
 *
 * @note Datos del Grupo:
 * - Número de Grupo: 6
 * - Integrante 1: Rafael Adrián Castillo Castro (Código: 202510044)
 * - Integrante 2: Maydelith Laura Zuñiga Cabrera (Código: 202510437)
 * - Integrante 3: Rodrigo Franco Huertos Ochoa (Código: 202510118)
 * - Integrante 4: Carlos Fabrizio Condor Hurtado (Código: SU_CODIGO_AQUI)
 * - Integrante 5: Valeria  Baquerizo Rojas (Código: 202510657)
 * - Integrante 6: Hector Contreras Sosa (Código: SU_CODIGO_AQUI)
 */

#include "CJuego.h"

int main() {
    // 1. Instanciamos la clase controladora del juego.
    CJuego juego(2);

    // 2. Lanzamos el menú principal.
    // A partir de aquí, la clase CJuego toma el control total.
    juego.mostrar_menu();

    return 0;
}