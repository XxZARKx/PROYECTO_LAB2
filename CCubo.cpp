//
// Created by azul_ on 23/11/2025.
//

#include "CCubo.h"


CCubo :: CCubo() {
    casillas = {};
}
CCubo :: CCubo(vector<int> _casillas) {
    casillas = _casillas;
}
CCubo ::  ~CCubo(){}

/*Metodo de verificacion
 * Se espera recibir valores entre 1 y 4 para validar que este completamente lleno vector
 */
bool CCubo :: verificar(const vector<int> &estado_linea){
    //Verificamos que tengamos las 4 lineas llenas si falso
   if (casillas.size() != 4)
       return false;

    //Revisa que las 4 lineas esten marcadas (valor == 1)
    for (int indice : casillas) {

        //Proteccion para indices invalidos
        if (indice < 0 || indice >= estado_linea.size())
            return false;

        //Si alguna linea No esta marcada el cubo no esta completo
        if (estado_linea[indice] == 0)
            return false;
    }

    //Las 4 lineas estan marcadas, cubo completo
    return true;
}