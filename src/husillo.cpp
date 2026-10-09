#include "husillo.h"

#include <stdexcept>

Husillo::Husillo(const std::string& nombre, int vidaUtil)
    : nombre(nombre),
      vidaUtilMaxima(vidaUtil),
      vidaUtilRestante(vidaUtil) {

    if (nombre.empty()) {
        throw std::invalid_argument(
            "El nombre del husillo no puede estar vacio."
        );
    }

    if (vidaUtil <= 0) {
        throw std::invalid_argument(
            "La vida util debe ser mayor que cero."
        );
    }
}

std::string Husillo::getNombre() const {
    return nombre;
}

int Husillo::getVidaUtilMaxima() const {
    return vidaUtilMaxima;
}

int Husillo::getVidaUtilRestante() const {
    return vidaUtilRestante;
}

bool Husillo::desgastar() {
    if (vidaUtilRestante <= 0) {
        return false;
    }

    --vidaUtilRestante;

    return true;
}

void Husillo::restaurar() {
    vidaUtilRestante = vidaUtilMaxima;
}

bool Husillo::necesitaMantenimiento() const {
    return vidaUtilRestante == 0;
}