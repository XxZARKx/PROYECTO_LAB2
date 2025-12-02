//
// Created by maydelithzuniga on 23/11/2025.
//

#ifndef PROYECTO_CTABLERO_H
#define PROYECTO_CTABLERO_H
//ReSharper disable CppUnusedIncludeDirective
#include <iostream>
#include <vector>
#include <string>
#include "CCubo.h"
#include "CMovimientos.h"
using namespace std;


class CTablero {
private:
    int tamano{};
    vector<vector<string>> tablero;
public:
    CTablero() = default;
    explicit CTablero(int _tamano):tamano(2*_tamano) {
        tablero.resize(tamano);
        for (int i = 0; i < tamano; i++) {
            tablero[i].resize(tamano," ");
        }
        int contador=1;
        for (int i=0;i<tamano;i++) {
            if (i%2==0) {
                tablero[i][0] = "  ";
                tablero[0][i] = "  ";
            }
            else {
                if (contador==10) {
                    tablero[i][0] = " "+to_string(contador);
                }
                else {
                    tablero[i][0] = " "+to_string(contador)+ " ";

                }
                tablero[0][i] = "  " + to_string(contador) + " ";
                contador++;
            }
        }
        for (int i=1;i<tamano;i++) {
            for (int j=1;j<tamano;j++) {
                if (i%2!=0 and j%2!=0) {
                    tablero[i][j] = " + ";
                }
                else {
                    tablero[i][j] = "   ";
                }

            }
        }
    };
    virtual ~CTablero()=default;
    void dibujar_tablero() const;
    bool aplicar_movimiento( const vector<int> &print,const string& letra, int &puntos_ganados);
    static void conversion_coordenadas(const vector<int> &print, vector<int> &coordenadas);
    friend ostream& operator<<(iostream&, vector<vector<string>>& tabla);
};


#endif //PROYECTO_CTABLERO_H