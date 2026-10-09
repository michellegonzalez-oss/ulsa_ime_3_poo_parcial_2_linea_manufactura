#ifndef TORNOCNC_H
#define TORNOCNC_H

#include "Maquina.h"
#include "Componente.h"
#include "husillo.h"

class TornoCNC : public Maquina {
private:
    double velocidadCorte;
    double diametroMaximo;
    int tiempoPorPieza;

    Husillo husillo;

public:
    TornoCNC(
        int id,
        const std::string& nombre,
        double velocidadCorte,
        double diametroMaximo,
        int vidaUtilHusillo
    );

    // Operación propia del torno
    bool cilindrar(
        const Componente& pieza,
        double diametro
    );

    // Mantenimiento
    void realizarMantenimiento();

    // Mostrar información de la máquina
    void mostrarEstado() const;

    // Consultas propias del torno
    double getVelocidadCorte() const;
    double getDiametroMaximo() const;
    int getVidaUtilHusillo() const;
};

#endif