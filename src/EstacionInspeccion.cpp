#include "EstacionInspeccion.h"
#include "Componente.h"
#include <iostream>

EstacionInspeccion::EstacionInspeccion(double nominal, double tolerancia)
{
    this->valorNominal = nominal;
    this->tolerancia = tolerancia;

    offset = 0.0;
    encendida = false;

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
}

bool EstacionInspeccion::inspeccionar(
    Componente& componente,
    double medida)
{
    if (!encendida)
    {
        std::cout << "La estacion esta apagada.\n";
        return false;
    }

    medida += offset;

    bool aprobado =
        medida >= (valorNominal - tolerancia) &&
        medida <= (valorNominal + tolerancia);

    componente.setInspeccionado(true);
    componente.setAprobado(aprobado);

    if (aprobado)
    {
        piezasOK++;

        std::cout
            << "Componente "
            << componente.getId()
            << " -> APROBADO\n";
    }
    else
    {
        piezasNOK++;

        std::cout
            << "Componente "
            << componente.getId()
            << " -> RECHAZADO\n";
    }

    return aprobado;
}

void EstacionInspeccion::mostrarReporte() const
{
    std::cout << "\n===== REPORTE =====\n";

    std::cout
        << "Piezas OK: "
        << piezasOK
        << "\n";

    std::cout
        << "Piezas NOK: "
        << piezasNOK
        << "\n";

    std::cout
        << "Total inspeccionadas: "
        << piezasOK + piezasNOK
        << "\n";
}