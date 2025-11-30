//
// Created by Carlos on 11/22/2025.
//

#include "CMovimientos.h"


bool CMovimientos::coordenadas_validarMovimiento(int tablero_size,vector<vector<string>>const &tablero) const {
    if (coordenadas_pos_final.size() != 2)
        return false;
    if (coordenadas_pos_inicial.size() != 2)
        return false;
    int inicial_fila = coordenadas_pos_inicial[0];
    int inicial_columna = coordenadas_pos_inicial[1];
    int final_fila = coordenadas_pos_final[0];
    int final_columna = coordenadas_pos_final[1];

    if (!(inicial_fila > 0 && inicial_fila < tablero_size && inicial_columna > 0 && inicial_columna < tablero_size))
        return false;
    if (!(final_fila > 0 && final_fila < tablero_size && final_columna > 0 && final_columna < tablero_size))
        return false;
    if ((inicial_fila!=final_fila and inicial_columna!=final_columna) or (inicial_fila==final_fila and inicial_columna==final_columna))
        return false;
    if (!coordenadas_validarDistancia_manhattan())
        return false;
    if ((final_fila-inicial_fila)==0) {
        if (tablero[inicial_fila][inicial_columna+1] == " | " ) {
            return false;
        }
    }
    if ((final_columna-inicial_columna)==0) {
        if (tablero[inicial_fila+1][inicial_columna] == " ― " ) {
            return false;
        }
    }
    return true;
}
bool CMovimientos::coordenadas_validarDistancia_manhattan() const {
    int dist = sqrt(pow((coordenadas_pos_final[0] - coordenadas_pos_inicial[0]),2) +  pow((coordenadas_pos_final[1] - coordenadas_pos_inicial[1]),2));
    return dist == 2;
}
bool CMovimientos::print_validarMovimiento(int tablero_size) const {
    if (print_pos_final.size() != 2)
        return false;
    if (print_pos_inicial.size() != 2)
        return false;
    int inicial_fila = print_pos_inicial[0];
    int inicial_columna = print_pos_inicial[1];
    int final_fila = print_pos_final[0];
    int final_columna = print_pos_final[1];

    if (!(inicial_fila > 0 && inicial_fila < 7 && inicial_columna > 0 && inicial_columna < 7))
        return false;
    if (!(final_fila > 0 && final_fila < 7 && final_columna > 0 && final_columna < 7))
        return false;
    if ((inicial_fila!=final_fila and inicial_columna!=final_columna) or (inicial_fila==final_fila and inicial_columna==final_columna))
        return false;
    if (!print_validarDistancia_manhattan())
        return false;
    return true;
}
bool CMovimientos::print_validarDistancia_manhattan() const {
    int dist = sqrt(pow((print_pos_final[0] - print_pos_inicial[0]),2) +  pow((print_pos_final[1] - print_pos_inicial[1]),2));
    return dist == 1;
}


