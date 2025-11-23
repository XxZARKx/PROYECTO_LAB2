//
// Created by elvia on 11/22/2025.
//

#include "CJugador.h"

void CJugador::setNombre(const string& _nombre) {
    nombre = _nombre;
};

void CJugador::setSigla(string _sigla) {
    sigla = _sigla;
};

string CJugador::getNombre() {
    return nombre;
};

string CJugador::getSigla() {
    return sigla;
};

void CJugador::sumarPuntaje(int punto) {
    puntaje += punto;
};

int CJugador::getPuntaje() const {
    return puntaje;
};

void CJugador::cambiarTurno(int n ) {
    turno = n;
};

int CJugador::getTurno() {
    return turno;
};