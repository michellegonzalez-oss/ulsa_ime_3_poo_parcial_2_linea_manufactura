#ifndef PLANTA_H
#define PLANTA_H

#include <vector>
#include "Fresadora.h"

class Planta {
private:
    std::vector<Fresadora*> estaciones; // Agregación de punteros a máquinas

public:
    Planta() = default;

    void agregarEstacion(Fresadora* estacion);
    void procesarLote(int cantidadPiezas);
    void encenderLinea();
    void apagarLinea();
    void generarReporte() const;
};

#endif