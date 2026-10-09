#pragma once

#include <string>

class EstacionInspeccion 
{
private:
    std::string nombreSensor;

    bool encendida;

    double valorNominal;
    double tolerancia;
    double offset;

    int piezasOK;
    int piezasNOK;

public:
    EstacionInspeccion(
        std::string sensor,
        double nominal,
        double tolerancia
    );

    void encender();
    void apagar();

    void calibrar(double referencia);

    bool inspeccionar(double medida);

    void mostrarReporte() const;
};
