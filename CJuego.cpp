/**
 * @file CJuego.cpp
 * @brief Implementación de los métodos de la clase controladora del juego.
 * @author RCastillo / Grupo 6 / Sección 1.07
 */

#include "CJuego.h"

// --- CONSTRUCTOR ---
CJuego::CJuego(int _n_jugadores)
    : tamanio_tablero(0),
      n_jugadores(_n_jugadores), // Lista de inicialización
      turno_actual(0),
      jugadores(),
      tablero(0) // Inicializa con tamaño 0 temporalmente
{
    // Llena el vector con jugadores por defecto
    for (int i = 0; i < n_jugadores; i++) {
        std::string stdPlayerName = "Jugador " + std::to_string(i + 1);
        std::string stdAbrevName = "J" + std::to_string(i + 1);
        jugadores.emplace_back(stdPlayerName, stdAbrevName);
    }
}

// --- DESTRUCTOR ---
CJuego::~CJuego() = default;

// --- MENÚ PRINCIPAL ---
void CJuego::mostrar_menu() {
    int opcion = 0;
    do {
        std::cout << "\n--- Dots & Boxes ---\n";
        std::cout << "1. Tablero 6x6\n";
        std::cout << "2. Tablero 10x10\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione la opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                iniciar_partida(6);
                break;
            case 2:
                iniciar_partida(10);
                break;
            case 0:
                std::cout << "Saliendo del juego...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 0 && opcion != 1 && opcion != 2);
}

// --- INICIAR PARTIDA ---
void CJuego::iniciar_partida(int tamanio) {
    // 1. Guarda el tamaño del tablero para usarse en CJuego::juego_terminado()
    this->tamanio_tablero = tamanio;

    // 2. Reasigna el objeto tablero con el tamaño real seleccionado
    tablero = CTablero(tamanio);

    // 3. Inicia el ciclo principal del juego
    jugar();
}
// --- CONTROLADOR DE LA PARTIDA ---

void CJuego::jugar() {
    int r1, c1, r2, c2;
    bool movimiento_exitoso = false; // Flag para controlar el bucle de validación

    while (!juego_terminado()) {
        // 1. Renderizar tablero
        tablero.dibujar_Tablero();

        CJugador &jugadorActual = jugadores[turno_actual];
        std::cout << "\nTurno de: " << jugadorActual.getNombre()
                  << " (" << jugadorActual.getSigla() << ")" << std::endl;

        // --- INICIO DEL BUCLE DE VALIDACIÓN ---

        // Repetir esto hasta que el movimiento sea válido
        do {
            // Input de coordenadas
            std::cout << "Ingrese origen (fila columna): ";
            std::cin >> r1 >> c1;
            std::cout << "Ingrese destino (fila columna): ";
            std::cin >> r2 >> c2;

            std::vector<int> coordenadas = {r1, c1, r2, c2};
            std::string letra = jugadorActual.getSigla();

            // Llama al tablero.
            // Según el cambio, ahora nos devuelve true (éxito) o false (fallo).
            movimiento_exitoso = tablero.aplicar_movimiento(coordenadas, letra);

            if (!movimiento_exitoso) {
                std::cout << "Intentalo de nuevo, por favor.\n";
            }

        } while (!movimiento_exitoso);
        // --- FIN DEL BUCLE DE VALIDACIÓN ---

        // Solo cambiamos de turno si salimos del bucle (o sea, si fue exitoso)
        cambiar_turno();
    }

    std::cout << "\n--- JUEGO TERMINADO ---\n";
}

void CJuego::cambiar_turno() {
    // Fórmula: (turno_actual + 1) dividido entre n_jugadores, y nos quedamos el residuo.

    // Ejemplo con 2 jugadores:
    // (0 + 1) % 2 = 1 -> Pasa al jugador 1
    // (1 + 1) % 2 = 0 -> Vuelve al jugador 0

    turno_actual = (turno_actual + 1) % n_jugadores;
}

bool CJuego::juego_terminado() const {
    // A. Cálculo matemático de cajas totales: (N-1) * (N-1)
    int filas_cajas = tamanio_tablero - 1;
    int total_cajas = filas_cajas * filas_cajas;

    // B. Sumar puntajes de los jugadores
    int suma_puntajes = 0;
    for (int i = 0; i < n_jugadores; i++) {
        suma_puntajes += jugadores[i].getPuntaje();
    }

    // C. Comparar
    // Si la suma de puntos es igual al total de cajas, ya no hay nada más que jugar.
    if (suma_puntajes >= total_cajas) {
        return true;
    } else {
        return false;
    }
}

