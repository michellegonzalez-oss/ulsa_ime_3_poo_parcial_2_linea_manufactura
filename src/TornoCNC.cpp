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

// Operacion de cilindrado
bool TornoCNC::cilindrar(
    const Componente& pieza,
    double diametro
) {
    if (!puedeProcesar()) {
        std::cout
            << "Torno CNC: no puede procesar. "
            << "La maquina esta apagada o en falla.\n";
        return false;
    }

    if (diametro <= 0 || diametro > diametroMaximo) {
        std::cout
            << "Torno CNC: diametro no valido para la pieza "
            << pieza.getNombre() << ".\n";
        return false;
    }

    std::cout
        << "Torno CNC: cilindrando la pieza "
        << pieza.getNombre()
        << " (ID: " << pieza.getId() << ").\n";

    // Registrar el trabajo realizado
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    // Desgastar el husillo
    husillo.desgastar();

    std::cout
        << "Vida util restante del husillo: "
        << husillo.getVidaUtilRestante()
        << " de "
        << husillo.getVidaUtilMaxima()
        << ".\n";

    // Comprobar si el husillo se agoto
    if (husillo.necesitaMantenimiento()) {
        reportarFalla();

        std::cout
            << "Torno CNC: el husillo agoto su vida util. "
            << "Se requiere mantenimiento.\n";
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

// Mostrar estado de la maquina y del componente
void TornoCNC::mostrarEstado() const {
    Maquina::mostrarEstado();

    std::cout << "\n--- Datos del Torno CNC ---\n";

    std::cout
        << "Velocidad de corte: "
        << velocidadCorte << '\n';

    std::cout
        << "Diametro maximo: "
        << diametroMaximo << '\n';

    std::cout
        << "Tiempo por pieza: "
        << tiempoPorPieza << " segundos\n";

    std::cout
        << "Componente mecanico: "
        << husillo.getNombre() << '\n';

    std::cout
        << "Vida util del husillo: "
        << husillo.getVidaUtilRestante()
        << " de "
        << husillo.getVidaUtilMaxima()
        << '\n';
}

// Consultar velocidad de corte
double TornoCNC::getVelocidadCorte() const {
    return velocidadCorte;
}

// Consultar diametro maximo
double TornoCNC::getDiametroMaximo() const {
    return diametroMaximo;
}

// Consultar vida util restante del husillo
int TornoCNC::getVidaUtilHusillo() const {
    return husillo.getVidaUtilRestante();
}