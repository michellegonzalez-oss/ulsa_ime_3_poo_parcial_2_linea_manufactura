// src/RobotSoldador.cpp
#include "RobotSoldador.h"
#include <iostream>

RobotSoldador::RobotSoldador(int id, const std::string& nombre, float tempInicial)
    : Maquina(id, nombre), temperaturaActual(tempInicial), piezasSoldadas(0) {}

bool RobotSoldador::soldarComponente(Componente& comp, int tiempoSeg) {
    if (!puedeProcesar()) return false;
    
    // Modificación del estado propio del RobotSoldador
    temperaturaActual += 15.5f; 
    piezasSoldadas++;
    
    // Modificación del componente que viaja por la línea
    comp.setSoldado(true); // Asumiendo que Componente tiene este método
    
    agregarTiempo(tiempoSeg);
    registrarPieza();
    
    return true;
}

void RobotSoldador::calibrarAntorcha() {
    std::cout << "Calibrando antorcha y ajustando voltaje en: " << nombre << "\n";
}

void RobotSoldador::enfriar() {
    temperaturaActual = 25.0f; // Regresa a temperatura ambiente
}

void RobotSoldador::reparar() {
    registrarMantenimiento();
    piezasSoldadas = 0; 
    enfriar();
}