//
// Created by azul_ on 23/11/2025.
//

#ifndef CCUBO_CCUBO_H
#define CCUBO_CCUBO_H
#include "CTablero.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class CCubo {
    private:
        vector<int> pos;
        string lado;
    public:
        CCubo(){};
        CCubo(vector<int> _pos, string _lado):pos(_pos),lado(_lado){};
        virtual ~CCubo(){};

    //Metodo de verificacion
        void verificar(vector<vector<string>> &estado_linea, string letra);
        bool movimientos(int n1,int n2, int tamano);

};


#endif //CCUBO_CCUBO_H