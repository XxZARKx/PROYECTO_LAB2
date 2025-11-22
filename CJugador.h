//
// Created by elvia on 11/22/2025.
//

#ifndef PROYECTO_CJUGADOR_H
#define PROYECTO_CJUGADOR_H


#include <iostream>

using namespace std;

class CJugador {
private:
    string nombre;
    string sigla;
    int turno = 0;
    int puntaje = 0;
public:
    CJugador(){};
    CJugador(string _nombre, string _sigla): nombre(_nombre), sigla(_sigla){};
    virtual ~CJugador(){};

    void setNombre(string _nombre);

    void setSigla(string _sigla);

    string getNombre();

    string getSigla();

    void sumarPuntaje(int punto);

    int getPuntaje() const;

    void cambiarTurno(int n );

    int getTurno();

};


#endif //PROYECTO_CJUGADOR_H