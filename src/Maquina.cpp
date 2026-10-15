#include "Maquina.h"
#include <iostream>

Maquina::Maquina(int id, const std::string& nombre)
    : id(id), nombre(nombre), encendida(false), enFalla(false),
      piezasProcesadas(0), tiempoTrabajado(0), paros(0) {}

void Maquina::encender() {
    encendida = true;
}

void Maquina::apagar() {
    encendida = false;
}

bool Maquina::estaEncendida() const {
    return encendida;
}

bool Maquina::estaEnFalla() const {
    return enFalla;
}

bool Maquina::puedeProcesar() const {
    return encendida && !enFalla;
}

int Maquina::getId() const {
    return id;
}

std::string Maquina::getNombre() const {
    return nombre;
}

int Maquina::getPiezasProcesadas() const {
    return piezasProcesadas;
}

int Maquina::getTiempoTrabajado() const {
    return tiempoTrabajado;
}

int Maquina::getParos() const {
    return paros;
}

void Maquina::registrarPieza() {
    piezasProcesadas++;
}

void Maquina::agregarTiempo(int segundos) {
    tiempoTrabajado += segundos;
}

void Maquina::reportarFalla() {
    enFalla = true;
}

void Maquina::registrarMantenimiento() {
    enFalla = false;
    paros++;
}

void Maquina::mostrarEstado() const {
    std::cout << "[" << id << "] " << nombre
              << " | Estado: " << (encendida ? "Encendida" : "Apagada")
              << " | Falla: " << (enFalla ? "SI" : "NO")
              << " | Piezas: " << piezasProcesadas
              << " | Tiempo: " << tiempoTrabajado << "s"
              << " | Paros: " << paros << std::endl;
}