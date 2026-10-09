#ifndef BANDATRANSPORTADORA_H
#define BANDATRANSPORTADORA_H

#include "Maquina.h"
#include "Motor.h"
#include "Componente.h"

class BandaTransportadora : public Maquina {
private:
    Motor motor;
    float velocidad;

public:
    BandaTransportadora(int id, const std::string& nombre);

    void encender();  // redefinimos comportamiento
    void apagar();

    void moverComponente(Componente& c);
};

#endif
