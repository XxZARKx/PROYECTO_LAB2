/**
 * @file CJuego.h
 * @brief Archivo de cabecera para la clase controladora del juego Dots and Boxes.
 * @author RCastillo / Grupo 6 / Sección 1.07
 */

// --- Guardas de Inclusión ---
#ifndef CJUEGO_H
#define CJUEGO_H

// --- Inclusiones Necesarias ---
#include <iostream>
#include <vector>
#include <string>
#include "CTablero.h"
#include "CJugador.h"

/**
 * @class CJuego
 * @brief Clase principal que controla el flujo del juego, turnos y puntuaciones.
 */

class CJuego {
private:
    int tamanio_tablero;
protected:
    // --- ATRIBUTOS ---

    int n_jugadores;    ///< Cantidad de jugadores en la partida.

    int turno_actual;   ///< Índice del jugador que tiene el turno actual (0 o 1).

    /**
     *@brief Lista dinámica de jugadores.
     */

    std::vector<CJugador> jugadores{};

    /**
     *@brief Objeto que representa la matriz de juego.
     */
    CTablero tablero{};

public:
    // --- MÉTODOS ---

    /**
     * @brief Constructor de la clase.
     * @param _n_jugadores Número de jugadores a inicializar.
     */
    explicit CJuego(int _n_jugadores);

    /**
     * @brief Destructor virtual.
     */
    virtual ~CJuego();

    /**
     * @brief Muestra el menú principal para elegir el tamaño del tablero.
     */
    void mostrar_menu();

    /**
     * @brief Configura el tablero e inicia los objetos necesarios.
     * @param tamanio Dimensión del tablero (ej. 6 para 6x6).
     */
    void iniciar_partida(int tamanio);

    /**
     * @brief El "Game Loop" principal. Controla el ciclo de turnos hasta el fin del juego.
     */
    void jugar();

    /**
     * @brief Verifica si ya no quedan movimientos posibles.
     * @return true si el juego ha terminado, false en caso contrario.
     */
    bool juego_terminado() const;

    /**
     * @brief Pasa el turno al siguiente jugador.
     */
    void cambiar_turno();
};

#endif // CJUEGO_H