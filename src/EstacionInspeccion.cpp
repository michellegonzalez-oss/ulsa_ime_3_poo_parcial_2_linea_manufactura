#include "EstacionInspeccion.h"
#include <iostream>

EstacionInspeccion::EstacionInspeccion(std::string sensor, double nominal, double tol)
{
    nombreSensor = sensor;
    valorNominal = nominal;
    tolerancia = tol;

    encendida = false;

    offset = 0.0;

    piezasOK = 0;
    piezasNOK = 0;
}

void EstacionInspeccion::encender()
{
    encendida = true;
}

void EstacionInspeccion::apagar()
{
    encendida = false;
}

void EstacionInspeccion::calibrar(double referencia)
{
    offset = valorNominal - referencia;

    std::cout << "Offset de calibracion: " << offset << " mm\n";
}

bool EstacionInspeccion::inspeccionar(double medida)
{
    if(!encendida)
    {
        std::cout << "ERROR: Estacion apagada.\n";
        return false;
    }

    medida += offset;

    bool aprobada = medida >= (valorNominal - tolerancia) && medida <= (valorNominal + tolerancia);

    if(aprobada)
    {
        piezasOK++;

        std::cout << "Pieza " << medida << " mm -> OK\n";
    }
    else
    {
        piezasNOK++;

        std::cout << "Pieza " << medida << " mm -> NOK\n";
    }

    return aprobada;
}

void EstacionInspeccion::mostrarReporte() const
{
    std::cout << "Sensor: " << nombreSensor << "\n";

    std::cout << "Piezas OK: " << piezasOK << "\n";

    std::cout << "Piezas NOK: " << piezasNOK << "\n";

    std::cout << "Total: " << (piezasOK + piezasNOK) << "\n";
}
