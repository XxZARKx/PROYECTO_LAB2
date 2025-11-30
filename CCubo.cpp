//
// Created by azul_ on 23/11/2025.
//

#include "CCubo.h"

bool CCubo::movimientos(int n1,int n2, size_t tamano) {
    if (n1 > 0 && n1 < tamano && n2 > 0 && n2 < tamano) {
        return true;
    }
    return false;
}

void CCubo :: verificar( vector<vector<string>> &estado_linea,const string& letra)const {
    vector<int> estado;
    if (lado=="columna") {
        if (movimientos(pos[0]-2,pos[1],estado_linea.size())) {
            if (estado_linea[pos[0]-2][pos[1]]=="---") {
                estado.push_back(pos[0]-2);
                estado.push_back(pos[1]);
            }
        }
        if (movimientos(pos[0]-1,pos[1]-1,estado_linea.size())) {
            if (estado_linea[pos[0]-1][pos[1]-1]=="  |") {
                estado.push_back(pos[0]-1);
                estado.push_back(pos[1]-1);
            }

        }
        if (movimientos(pos[0]-1,pos[1]+1,estado_linea.size())) {
            if (estado_linea[pos[0]-1][pos[1]+1]=="  |") {
                estado.push_back(pos[0]-1);
                estado.push_back(pos[1]+1);
            }

        }
        if (estado.size()==6) {
            estado_linea[pos[0]-1][pos[1]]="  " + letra;
        }
        estado.clear();

        if (movimientos(pos[0]+1,pos[1]-1,estado_linea.size())) {
            if (estado_linea[pos[0]+1][pos[1]-1]=="  |") {
                estado.push_back(pos[0]+1);
                estado.push_back(pos[1]-1);
            }
        }
        if (movimientos(pos[0]+2,pos[1],estado_linea.size())) {
            if (estado_linea[pos[0]+2][pos[1]]=="---") {
                estado.push_back(pos[0]+2);
                estado.push_back(pos[1]);
            }

        }
        if (movimientos(pos[0]+1,pos[1]+1,estado_linea.size())) {
            if (estado_linea[pos[0]+1][pos[1]+1]=="  |") {
                estado.push_back(pos[0]+1);
                estado.push_back(pos[1]+1);
            }

        }
        if (movimientos(pos[0],pos[1]+2,estado_linea.size())) {
            if (estado_linea[pos[0]][pos[1]+2]==" | ") {
                estado.push_back(pos[0]);
            estado.push_back(pos[1]+2);
            }

        }
        if (estado.size()==6) {
            estado_linea[pos[0]][pos[1]+1]=" " + letra + " ";
        }

        if (movimientos(pos[0]-1,pos[1]-1,estado_linea.size())) {
            if (estado_linea[pos[0]-1][pos[1]-1]==" ― ") {
                estado.push_back(pos[0]-1);
                estado.push_back(pos[1]-1);
            }
        }
        if (movimientos(pos[0]+1,pos[1]-1,estado_linea.size())) {
            if (estado_linea[pos[0]+1][pos[1]-1]==" ― ") {
                estado.push_back(pos[0]+1);
                estado.push_back(pos[1]-1);
            }

        }
        if (movimientos(pos[0],pos[1]-2,estado_linea.size())) {
            if (estado_linea[pos[0]][pos[1]-2]==" | ") {
                estado.push_back(pos[0]);
                estado.push_back(pos[1]-2);
            }

        }
        if (estado.size()==12) {
            estado_linea[pos[0]][pos[1]-1]=" " + letra + " ";
        }

    }
    else {
        if (movimientos(pos[0]-1,pos[1]+1,estado_linea.size())) {
            if (estado_linea[pos[0]-1][pos[1]+1]==" | ") {
                estado.push_back(pos[0]-1);
                estado.push_back(pos[1]+1);
            }
        }
        if (movimientos(pos[0]-1,pos[1]-1,estado_linea.size())) {
            if (estado_linea[pos[0]-1][pos[1]-1]==" | ") {
                estado.push_back(pos[0]-1);
                estado.push_back(pos[1]-1);
            }

        }
        if (movimientos(pos[0]-2,pos[1],estado_linea.size())) {
            if (estado_linea[pos[0]-2][pos[1]]==" ― ") {
                estado.push_back(pos[0]-2);
                estado.push_back(pos[1]);
            }

        }
        if (estado.size()==6) {
            estado_linea[pos[0]-1][pos[1]]=" " + letra + " ";
        }

        if (movimientos(pos[0]+1,pos[1]+1,estado_linea.size())) {
            if (estado_linea[pos[0]+1][pos[1]+1]==" | ") {
                estado.push_back(pos[0]+1);
                estado.push_back(pos[1]+1);
            }
        }
        if (movimientos(pos[0]+1,pos[1]-1,estado_linea.size())) {
            if (estado_linea[pos[0]+1][pos[1]-1]==" | ") {
                estado.push_back(pos[0]+1);
                estado.push_back(pos[1]-1);
            }

        }
        if (movimientos(pos[0]+2,pos[1],estado_linea.size())) {
            if (estado_linea[pos[0]+2][pos[1]]==" ― ") {
                estado.push_back(pos[0]+2);
                estado.push_back(pos[1]);
            }

        }
        if (estado.size()==12) {
            estado_linea[pos[0]+1][pos[1]]=" " + letra + " ";
        }

    }
    estado.clear();
}