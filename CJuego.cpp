/**
 * @file CJuego.cpp
 * @brief Implementación de los métodos de la clase controladora del juego.
 * @author RCastillo / Grupo 6 / Sección 1.07
 */

#include "CJuego.h"
#include <limits>
#include <sstream>
#include <algorithm>

// --- CONSTRUCTOR ---
CJuego::CJuego(int _n_jugadores)
    : tamanio_tablero(0),
      n_jugadores(_n_jugadores), // Lista de inicialización
      turno_actual(0),
      jugadores(),
      tablero(0) // Inicializa con tamaño 0 temporalmente
{
    cout << "\n--- Configuracion de Jugadores ---" << endl;

    for (int i = 0; i < n_jugadores; i++) {
        string nombreInput;
        string siglaInput;
        bool entradaValida = false;

        // 1. Pedir Nombre
        cout << "Ingrese el nombre del Jugador " << (i + 1) << ": ";
        cin >> nombreInput;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do {
            cout << "Ingrese su sigla (1 letra) para " << nombreInput << ": ";
            cin >> siglaInput;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // VALIDACIÓN LÓGICA
            if (siglaInput.length() == 1) {
                entradaValida = true;
            } else {
                cout << ">> ERROR: La sigla debe ser de un solo caracter. Intente de nuevo.\n";
                entradaValida = false;
            }
        } while (!entradaValida);

        // 3. Crear el jugador directamente en el vector
        jugadores.emplace_back(nombreInput, siglaInput);

        cout << "----------------------------------" << endl;
    }
    cout << "Jugadores registrados exitosamente.\n" << endl;
}

// --- DESTRUCTOR ---
CJuego::~CJuego() = default;

// --- MENÚ PRINCIPAL ---
void CJuego::mostrar_menu() {
    int opcion = 0;
    do {
        cout << "\n--- Dots & Boxes ---\n";
        cout << "1. Tablero 6x6\n";
        cout << "2. Tablero 10x10\n";
        cout << "0. Salir\n";
        cout << "Seleccione la opcion: ";
        cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                iniciar_partida(6);
                break;
            case 2:
                iniciar_partida(10);
                break;
            case 0:
                cout << "Saliendo del juego...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
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
        tablero.dibujar_tablero();

        CJugador &jugadorActual = jugadores[turno_actual];
        cout << "\nTurno de: " << jugadorActual.getNombre()
             << " (" << jugadorActual.getSigla() << ")"
             << " | Puntos: " << jugadorActual.getPuntaje() << endl;

        // --- INICIO DEL BUCLE DE VALIDACIÓN ---
        int puntos_en_este_turno = 0;

        // Repetir esto hasta que el movimiento sea válido
        do {
            string linea_entrada;

            // --- INPUT ORIGEN ---
            cout << "Ingrese origen (fila;columna): ";
            getline(cin, linea_entrada);

            // Reemplaza cualquier ';' o ',' por espacios
            replace(linea_entrada.begin(), linea_entrada.end(), ';', ' ');
            replace(linea_entrada.begin(), linea_entrada.end(), ',', ' ');

            // Procesa los números
            stringstream ss_origen(linea_entrada);
            ss_origen >> r1 >> c1;
            
            // --- INPUT DESTINO ---
            cout << "Ingrese destino (fila;columna): ";
            getline(cin, linea_entrada);

            // Misma limpieza
            replace(linea_entrada.begin(), linea_entrada.end(), ';', ' ');
            replace(linea_entrada.begin(), linea_entrada.end(), ',', ' ');

            stringstream ss_destino(linea_entrada);
            ss_destino >> r2 >> c2;

            vector<int> coordenadas = {r1, c1, r2, c2};
            string letra = jugadorActual.getSigla();

            // Llama al tablero.
            // Según el cambio, ahora nos devuelve true (éxito) o false (fallo).
            movimiento_exitoso = tablero.aplicar_movimiento(coordenadas, letra, puntos_en_este_turno);

            if (!movimiento_exitoso) {
                cout << ">> Movimiento invalido (o formato incorrecto). Intentalo de nuevo.\n";
            }

        } while (!movimiento_exitoso);
        // --- FIN DEL BUCLE DE VALIDACIÓN ---

        if (puntos_en_este_turno > 0) {
            // 1. Sumar puntaje al jugador actual
            jugadorActual.sumarPuntaje(puntos_en_este_turno);

            cout << "\n!! " << jugadorActual.getNombre() << " cerro "
                 << puntos_en_este_turno << " cuadrado(s) y repite turno !!\n";
        } else {
            // Si no hizo puntos, le toca al siguiente
            cambiar_turno();
        }
    }

    cout << "\n--- JUEGO TERMINADO ---\n";
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

