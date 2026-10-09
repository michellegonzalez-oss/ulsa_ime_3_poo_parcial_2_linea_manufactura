#ifndef TORNOCNC_H
#define TORNOCNC_H

#include "Maquina.h"
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

    bool cilindrar(double diametro);
    void realizarMantenimiento();

    void mostrarEstado() const;

    double getVelocidadCorte() const;
    double getDiametroMaximo() const;
    int getVidaUtilHusillo() const;
};

#endif