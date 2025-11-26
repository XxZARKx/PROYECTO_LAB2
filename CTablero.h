//
// Created by maydelithzuniga on 23/11/2025.
//

#ifndef PROYECTO_CTABLERO_H
#define PROYECTO_CTABLERO_H
#include <iostream>
#include <vector>
#include <string>
#include "CCubo.h"
#include "CMovimientos.cpp"
using namespace std;


class CTablero {
private:
    int tamano;
    vector<vector<string>> tablero;
public:
    CTablero();
    CTablero(int _tamano):tamano(2*_tamano) {
        tablero.resize(tamano);
        for (int i = 0; i < tamano; i++) {
            tablero[i].resize(tamano," ");
        }
    };
    virtual ~CTablero();
    vector<vector<string>> relleno_tablero();
    void dibujar_tablero();
    bool aplicar_movimiento( const vector<int> &print,string letra);
    void conversion_coordenadas(const vector<int> &print, vector<int> &coordenadas);
    friend ostream& operator<<(iostream&, vector<vector<string>>& tabla);
};


#endif //PROYECTO_CTABLERO_H