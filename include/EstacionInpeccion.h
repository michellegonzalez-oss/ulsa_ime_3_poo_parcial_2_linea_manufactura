#pragma once

#include <string>
#include "Componente.h"

class EstacionInspeccion
{
private:
    bool encendida;

    double valorNominal;
    double tolerancia;
    double offset;

    int piezasOK;
    int piezasNOK;

public:

    EstacionInspeccion(double nominal, double tolerancia);

    void encender();
    void apagar();

    void calibrar(double referencia);

    bool inspeccionar(Componente& componente, double medida);

    void mostrarReporte() const;
};