#include "Fresadora.h"
#include <iostream>

Fresadora::Fresadora(int id, const std::string& nombre, int vidaHerramienta, int profundidad, int tiempoPorPieza)
    : Maquina(id, nombre), herramienta(vidaHerramienta),
      profundidadCorte(profundidad > 0 ? profundidad : 2),
      tiempoPorPieza(tiempoPorPieza > 0 ? tiempoPorPieza : 45) {}

bool Fresadora::procesarPieza() {
    if (!puedeProcesar()) {
        std::cout << "[ERROR] " << getNombre() << " no puede procesar la pieza. Verifique encendido o fallas." << std::endl;
        return false;
    }

    // Procesa pieza
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    // Revisa desgaste del componente
    if (herramienta.desgastar()) {
        reportarFalla();
        std::cout << "[ALERTA] " << getNombre() << ": La herramienta de corte se desgastó por completo. Máquina en falla." << std::endl;
    }
    return true;
}

void Fresadora::darMantenimiento() {
    herramienta.reemplazar();
    registrarMantenimiento();
    std::cout << "[MANTENIMIENTO] " << getNombre() << ": Herramienta reemplazada. Estado restaurado." << std::endl;
}

int Fresadora::getProfundidadCorte() const {
    return profundidadCorte;
}

void Fresadora::mostrarEstado() const {
    // Reutiliza el método base
    Maquina::mostrarEstado();
    // Agrega la información propia y de su componente
    std::cout << "  └─ [Fresadora Especifics] Profundidad: " << profundidadCorte
              << "mm | Vida útil de herramienta: " << herramienta.getVidaUtil()
              << "/" << herramienta.getVidaMaxima() << " piezas" << std::endl;
}