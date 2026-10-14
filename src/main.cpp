// Proyecto Parcial 2: Simulador de una Planta de Manufactura Automatizada
//
// Programa principal del equipo (bloque 6).
// La guía completa está en PROYECTO.md, sección 2.5.
//
// Compilar:
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o planta
// Ejecutar:
//   ./planta

#include <iostream>
#include "BandaTransportadora.h"
#include "Componente.h"
#include "EstacionInspeccion.h"
#include "Fresadora.h"
#include "husillo.h"
#include "Maquina.h"
#include "Motor.h"
#include "Planta.h"
#include "RobotSoldador.h"
#include "TornoCNC.h"

int main() {
    // 1. Crear las máquinas y registrarlas en la planta.
    EstacionInspeccion inspector(
        50.0,
        0.5
    );
    Componente pieza1(1, "Eje");
    Componente pieza2(2, "Engrane");
    Componente pieza3(3, "Soporte");
    // 2. Intentar procesar una pieza con las máquinas apagadas,
    //    para mostrar el rechazo.

    // 3. Encender todas las máquinas.
    inspector.encender();
    inspector.calibrar(50.0);

    // 4. Procesar un lote de 20 piezas.
    inspector.inspeccionar(pieza1, 49.9);
    inspector.inspeccionar(pieza2, 50.2);
    inspector.inspeccionar(pieza3, 51.1);

    // 5. Mostrar el reporte del turno y apagar.
    inspector.mostrarReporte();
    inspector.apagar();

    return 0;
}