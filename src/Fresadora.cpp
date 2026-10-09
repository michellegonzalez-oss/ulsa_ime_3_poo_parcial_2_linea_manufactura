// src/Fresadora.cpp
#include "Fresadora.h"

Fresadora::Fresadora(int id, const std::string& nombre, int numEjes)
    : Maquina(id, nombre), numEjes(numEjes) {}

bool Fresadora::fresarSuperficie(Componente& comp, int tiempoSeg) {
    if (!puedeProcesar()) return false;
    agregarTiempo(tiempoSeg);
    registrarPieza();
    return true;
}

void Fresadora::reparar() {
    registrarMantenimiento();
}