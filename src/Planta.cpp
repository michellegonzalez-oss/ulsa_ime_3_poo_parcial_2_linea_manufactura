#include "Planta.h"
#include <iostream>
#include <iomanip>

void Planta::agregarEstacion(Fresadora* estacion) {
    if (estacion != nullptr) {
        estaciones.push_back(estacion);
    }
}

void Planta::encenderLinea() {
    for (auto* m : estaciones) {
        m->encender();
    }
}

void Planta::apagarLinea() {
    for (auto* m : estaciones) {
        m->apagar();
    }
}

void Planta::procesarLote(int cantidadPiezas) {
    for (int i = 1; i <= cantidadPiezas; ++i) {
        for (auto* m : estaciones) {
            if (m->estaEnFalla()) {
                m->darMantenimiento();
            }
            m->procesarPieza();
        }
    }
}

void Planta::generarReporte() const {
    int tiempoTotal = 0;
    int parosTotales = 0;
    int piezasTerminadas = estaciones.empty() ? 0 : estaciones.back()->getPiezasProcesadas();

    for (const auto* m : estaciones) {
        tiempoTotal += m->getTiempoTrabajado();
        parosTotales += m->getParos();
    }

    std::cout << "\n=== Reporte del turno ===" << std::endl;
    std::cout << "Piezas terminadas: " << piezasTerminadas << std::endl;
    std::cout << "Tiempo total: " << tiempoTotal << " s" << std::endl;
    std::cout << "Paros por mantenimiento: " << parosTotales << std::endl;

    for (const auto* m : estaciones) {
        std::cout << "  " << std::left << std::setw(25) << m->getNombre()
                  << " .... " << m->getPiezasProcesadas() << " piezas, "
                  << m->getParos() << " paros, "
                  << (m->estaEnFalla() ? "en falla" : "sin falla") << std::endl;
    }
}