//
// Created by azul_ on 23/11/2025.
//

#ifndef CCUBO_CCUBO_H
#define CCUBO_CCUBO_H
//ReSharper disable CppUnusedIncludeDirective
#include "CTablero.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

class CCubo {
    private:
        vector<int> pos;
        string lado;
    public:
        CCubo()= default;
        CCubo(vector<int> _pos, string _lado):pos(std::move(_pos)),lado(std::move(_lado)){};
        virtual ~CCubo()= default;

    //Metodo de verificacion
        int verificar( vector<vector<string>> &estado_linea,const string& letra) const;
        static bool movimientos(int n1,int n2, size_t tamano);

};


#endif //CCUBO_CCUBO_H