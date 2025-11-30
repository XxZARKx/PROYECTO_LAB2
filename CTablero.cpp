//
// Created by maydelithzuniga on 23/11/2025.
//

#include "CTablero.h"


ostream& operator<<(ostream& os, const vector<vector<string>>& tabla) {
    os<<"Tablero: \n";
    for (const auto & i : tabla) {
        for (const auto & j : i) {
            os<<j;
        }
        os<<endl;
    }
    return os;
}

vector<vector<string>> CTablero::relleno_tablero() {
    int contador=1;
    for (int i=0;i<tamano;i++) {
        if (i%2==0) {
            tablero[i][0] = "  ";
            tablero[0][i] = "  ";
        }
        else {
            tablero[i][0] = to_string(contador);
            tablero[0][i] = to_string(contador);
            contador++;
        }
    }
    for (int i=1;i<tamano;i++) {
        for (int j=1;j<tamano;j++) {
            if (i%2!=0 and j%2!=0) {
                tablero[i][j] = "+";
            }
            else {
                tablero[i][j] = "  ";
            }

        }
    }
    return tablero;
}
void CTablero::dibujar_tablero() const{
    cout<<tablero;
}
bool CTablero::aplicar_movimiento(const vector<int> &print,const string& letra) {
    if (print.size() == 4) {
        vector<int> coordenadas;
        conversion_coordenadas(print,coordenadas);
        vector<int> print_pos_inicial;
        vector<int> print_pos_final;
        vector<int> coordenadas_pos_inicial;
        vector<int> coordenadas_pos_final;
        for (int i=0;i<coordenadas.size();i++) {
            if (i<=1) {
                print_pos_inicial.push_back(print[i]);
                coordenadas_pos_inicial.push_back(coordenadas[i]);
            }
            else {
                print_pos_final.push_back(print[i]);
                coordenadas_pos_final.push_back(coordenadas[i]);
            }
        }
        CMovimientos movimientos(print_pos_inicial,print_pos_final,coordenadas_pos_inicial,coordenadas_pos_final);
        if (movimientos.print_validarMovimiento(tamano)) {
            if (movimientos.coordenadas_validarMovimiento(tamano,tablero)) {
                vector<int> posicion;
                if ((coordenadas_pos_final[0]-coordenadas_pos_inicial[0])==0) {
                    tablero[coordenadas_pos_inicial[0]][coordenadas_pos_inicial[1]+1] = " -- ";
                    posicion.push_back(coordenadas_pos_inicial[0]);
                    posicion.push_back(coordenadas_pos_inicial[1]+1);
                    CCubo cubo(posicion,"columna");
                    cubo.verificar(tablero,letra);
                }
                if ((coordenadas_pos_final[1]-coordenadas_pos_inicial[1])==0) {
                    tablero[coordenadas_pos_inicial[0]+1][coordenadas_pos_inicial[1]] = " | ";
                    posicion.push_back(coordenadas_pos_inicial[0]+1);
                    posicion.push_back(coordenadas_pos_inicial[1]);
                    CCubo cubo(posicion,"fila");
                    cubo.verificar(tablero,letra);
                }
                posicion.clear();
                return true;

            }
        }
        return false;
    }
    else {
        return false;
    }



}
void CTablero::conversion_coordenadas(const vector<int> &print, vector<int> &coordenadas) {
    for (int i=0;i<print.size();i++) {
        coordenadas.push_back(print[i]*2 -1);
    }
}