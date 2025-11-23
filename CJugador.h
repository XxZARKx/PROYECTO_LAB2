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
    CJugador()= default;
    explicit CJugador(string  _nombre, string  _sigla): nombre(std::move(_nombre)), sigla(std::move(_sigla)){};
    virtual ~CJugador()= default;

    void setNombre(const string& _nombre);

    void setSigla(const string& _sigla);

    string getNombre();

    string getSigla();

    void sumarPuntaje(int punto);

    [[nodiscard]] int getPuntaje() const;

    void cambiarTurno(int n );

    [[nodiscard]] int getTurno() const;

};


#endif //PROYECTO_CJUGADOR_H