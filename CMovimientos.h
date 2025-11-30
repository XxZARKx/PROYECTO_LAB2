//
// Created by Carlos on 11/22/2025.
//

#ifndef DOTS_AND_BOXES_CMOVIMIENTOS_H
#define DOTS_AND_BOXES_CMOVIMIENTOS_H
//ReSharper disable CppUnusedIncludeDirective
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


class CMovimientos {
private:
    vector<int> print_pos_inicial;
    vector<int> print_pos_final;
    vector<int> coordenadas_pos_inicial;
    vector<int> coordenadas_pos_final;
public:
    CMovimientos()= default;
    explicit CMovimientos(const vector<int>& _print_pos_inicial, const vector<int> &_print_pos_final,const vector<int>& _coordenadas_pos_inicial, const vector<int> &_coordenadas_pos_final ):print_pos_inicial(_print_pos_inicial),print_pos_final(_print_pos_final),coordenadas_pos_inicial(_coordenadas_pos_inicial),coordenadas_pos_final(_coordenadas_pos_final){}
    virtual ~CMovimientos(){}
    [[nodiscard]] bool coordenadas_validarMovimiento(int tablero_size, vector<vector<string>> &tablero) const;
    [[nodiscard]] bool coordenadas_validarDistancia_manhattan() const;
    [[nodiscard]] bool print_validarMovimiento(int tablero_size) const;
    [[nodiscard]] bool print_validarDistancia_manhattan() const;


};


#endif //DOTS_AND_BOXES_CMOVIMIENTOS_H