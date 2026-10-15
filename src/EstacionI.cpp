#include "EstacionInspeccion.h"
#include <iostream>

EstacionInspeccion::EstacionInspeccion(int id, const std::string& nombre, int limiteLecturas, double tolerancia, int tiempoPorPieza)
    : Maquina(id, nombre), sensor(limiteLecturas),
      toleranciaAceptable(tolerancia > 0.0 ? tolerancia : 0.05),
      tiempoPorPieza(tiempoPorPieza > 0 ? tiempoPorPieza : 10) {}

bool EstacionInspeccion::inspeccionarDimensiones() {
    if (!puedeProcesar()) {
        std::cout << "[ERROR] " << getNombre() << ": No se puede inspeccionar la pieza. Estación apagada o en falla." << std::endl;
        return false;
    }

    // Registra la pieza y acumula el tiempo de medición
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    // Modela el desgaste del sensor de precisión
    if (sensor.desgastar()) {
        reportarFalla();
        std::cout << "[ALERTA] " << getNombre() << ": Sensor descalibrado tras alcanzar el límite de inspecciones. Falla reportada." << std::endl;
    }

    return true;
}

void EstacionInspeccion::recalibrarSensor() {
    sensor.recalibrar();
    registrarMantenimiento();
    std::cout << "[MANTENIMIENTO] " << getNombre() << ": Sensor recalibrado exitosamente. Falla despejada." << std::endl;
}

double EstacionInspeccion::getToleranciaAceptable() const {
    return toleranciaAceptable;
}

void EstacionInspeccion::mostrarEstado() const {
    // Reutilización explícita del método de la clase base
    Maquina::mostrarEstado();
    
    // Extensión con datos específicos de la Estación de Inspección y su componente
    std::cout << "  └─ [Estación Inspección] Tolerancia: ±" << toleranciaAceptable << " mm | Sensor: " << sensor.getLecturasRestantes() << "/" << sensor.getLecturasMaximas() << " lecturas rest." << " (Precisión: ±" << sensor.getPrecision() << " mm)" << std::endl;
}
