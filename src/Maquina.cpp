
#include "Maquina.h"
#include <iostream>
#include <stdexcept>

Maquina::Maquina(int id, const std::string& nombre)
    : id(id),
      nombre(nombre),
      encendida(false),
      enFalla(false),
      piezasProcesadas(0),
      tiempoTrabajado(0),
      paros(0) {

    // Validar los datos de la maquina
    if (id <= 0) {
        throw std::invalid_argument("El ID debe ser mayor que cero.");
    }

    if (nombre.empty()) {
        throw std::invalid_argument("El nombre no puede estar vacio.");
    }
}

void Maquina::registrarPieza() {
    piezasProcesadas++;
}

void Maquina::agregarTiempo(int segundos) {
    if (segundos > 0) {
        tiempoTrabajado += segundos;
    }
}

void Maquina::reportarFalla() {
    enFalla = true;
}

void Maquina::registrarMantenimiento() {
    if (enFalla) {
        enFalla = false;
        paros++;
    }
}

void Maquina::encender() {
    if (!enFalla) {
        encendida = true;
    } else {
        std::cout << nombre
                  << " no puede encenderse: necesita mantenimiento.\n";
    }
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

void Maquina::mostrarEstado() const {
    std::cout << "\n--- Estado de la maquina ---\n";
    std::cout << "ID: " << id << '\n';
    std::cout << "Nombre: " << nombre << '\n';
    std::cout << "Encendida: " << (encendida ? "Si" : "No") << '\n';
    std::cout << "Falla: " << (enFalla ? "Si" : "No") << '\n';
    std::cout << "Piezas procesadas: " << piezasProcesadas << '\n';
    std::cout << "Tiempo trabajado: " << tiempoTrabajado << " segundos\n";
    std::cout << "Paros por mantenimiento: " << paros << '\n';
}
