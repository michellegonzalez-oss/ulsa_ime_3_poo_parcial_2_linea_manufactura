#ifndef ESTACIONINSPECCION_H
#define ESTACIONINSPECCION_H

#include "Maquina.h"
#include "SensorCalibracion.h"

class EstacionInspeccion : public Maquina {
private:
    SensorCalibracion sensor;   // Composición
    double toleranciaAceptable; // Atributo propio 1 (en mm, ej. 0.05 mm)
    int tiempoPorPieza;         // Atributo propio 2 (en segundos)

public:
    EstacionInspeccion(int id, const std::string& nombre, int limiteLecturas, double tolerancia, int tiempoPorPieza);

    // Métodos propios
    bool inspeccionarDimensiones();
    void recalibrarSensor();
    double getToleranciaAceptable() const;

    // Redefinición de método virtual de la base
    void mostrarEstado() const override;
};

#endif
