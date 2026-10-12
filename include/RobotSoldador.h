// include/RobotSoldador.h
#ifndef ROBOTSOLDADOR_H
#define ROBOTSOLDADOR_H

#include "Maquina.h"
#include "Componente.h"

class RobotSoldador : public Maquina {
private:
    float temperaturaActual;
    int piezasSoldadas;

public:
    RobotSoldador(int id, const std::string& nombre, float tempInicial);
    
    bool soldarComponente(Componente& comp, int tiempoSeg);
    void calibrarAntorcha();
    void enfriar();
    void reparar();
};

#endif