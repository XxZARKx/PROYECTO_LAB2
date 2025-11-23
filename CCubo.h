//
// Created by azul_ on 23/11/2025.
//

#ifndef CCUBO_CCUBO_H
#define CCUBO_CCUBO_H

#include <vector>
using namespace std;

class CCubo {
    private:
        vector<int> casillas;
    public:
        CCubo();
        CCubo(vector<int> _casillas);
        virtual ~CCubo();

    //Metodo de verificacion
        bool verificar(const vector<int> &estado_linea);
};


#endif //CCUBO_CCUBO_H