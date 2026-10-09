#include "TornoCNC.h"

#include <iostream>
#include <stdexcept>

// Constructor del Torno CNC
TornoCNC::TornoCNC(
    int id,
    const std::string& nombre,
    double velocidadCorte,
    double diametroMaximo,
    int vidaUtilHusillo
)
    : Maquina(id, nombre),
      velocidadCorte(velocidadCorte),
      diametroMaximo(diametroMaximo),
      tiempoPorPieza(30),
      husillo("Husillo", vidaUtilHusillo) {

    if (velocidadCorte <= 0) {
        throw std::invalid_argument(
            "La velocidad de corte debe ser mayor que cero."
        );
    }

    if (diametroMaximo <= 0) {
        throw std::invalid_argument(
            "El diametro maximo debe ser mayor que cero."
        );
    }
}

// Operacion propia: cilindrar una pieza
bool TornoCNC::cilindrar(double diametro) {

    if (!puedeProcesar()) {
        std::cout
            << "Torno CNC: no se puede procesar. "
            << "La maquina esta apagada o en falla.\n";
        return false;
    }

    if (diametro <= 0 || diametro > diametroMaximo) {
        std::cout
            << "Torno CNC: diametro de pieza no valido.\n";
        return false;
    }

    std::cout << "Torno CNC: cilindrando pieza...\n";

    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    husillo.desgastar();

    if (husillo.necesitaMantenimiento()) {
        reportarFalla();

        std::cout
            << "Torno CNC: el husillo agoto su vida util. "
            << "La maquina entro en falla.\n";
    }

    return true;
}

// Mantenimiento del torno
void TornoCNC::realizarMantenimiento() {

    if (!estaEnFalla()) {
        std::cout
            << "Torno CNC: no necesita mantenimiento.\n";
        return;
    }

    husillo.restaurar();
    registrarMantenimiento();

    std::cout
        << "Torno CNC: mantenimiento realizado. "
        << "Husillo restaurado.\n";
}

// Mostrar el estado general y particular del torno
void TornoCNC::mostrarEstado() const {

    Maquina::mostrarEstado();

    std::cout << "\n--- Datos del Torno CNC ---\n";
    std::cout << "Velocidad de corte: "
              << velocidadCorte << '\n';

    std::cout << "Diametro maximo: "
              << diametroMaximo << '\n';

    std::cout << "Tiempo por pieza: "
              << tiempoPorPieza << " segundos\n";

    std::cout << "Componente: "
              << husillo.getNombre() << '\n';

    std::cout << "Vida util del husillo: "
              << husillo.getVidaUtilRestante()
              << " de "
              << husillo.getVidaUtilMaxima()
              << '\n';
}

// Getters
double TornoCNC::getVelocidadCorte() const {
    return velocidadCorte;
}

double TornoCNC::getDiametroMaximo() const {
    return diametroMaximo;
}

int TornoCNC::getVidaUtilHusillo() const {
    return husillo.getVidaUtilRestante();
}