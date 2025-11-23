//
// Created by Carlos on 11/22/2025.
//

#include "CMovimientos.h"


bool CMovimientos::validarMovimiento(int tablero_size, const vector<int>& pos_inicial) {
    if (coordenadas.size() != 2)
        return false;
    int fila = coordenadas[0];
    int columna = coordenadas[1];

    if (!(fila >= 0 && fila < tablero_size && columna >= 0 && columna < tablero_size))
        return false;

    if (!validarDistancia_manhattan(pos_inicial))
        return false;
    return true;


}

bool CMovimientos::validarDistancia_manhattan(const vector<int>& pos_inicial) const{
    int dist = abs(coordenadas[0] - pos_inicial[0]) +  abs(coordenadas[1] - pos_inicial[1]);
    return dist <= 1;
}