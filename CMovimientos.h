//
// Created by Carlos on 11/22/2025.
//

#ifndef DOTS_AND_BOXES_CMOVIMIENTOS_H
#define DOTS_AND_BOXES_CMOVIMIENTOS_H
// ReSharper disable once CppUnusedIncludeDirective
#include <cstdlib>
#include <vector>
using namespace std;


class CMovimientos {
private:
    vector<int> coordenadas;
public:
    CMovimientos()= default;
    explicit CMovimientos(const vector<int>& pos_final):coordenadas(pos_final){}
    vector<int>& getCoordenadas(){return coordenadas;}

    bool validarMovimiento(int tablero_size, const vector<int>& pos_inicial);
    bool validarDistancia_manhattan(const vector<int>& pos_inicial);


};


#endif //DOTS_AND_BOXES_CMOVIMIENTOS_H