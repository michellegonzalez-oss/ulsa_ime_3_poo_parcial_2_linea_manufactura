// include/Fresadora.h
#ifndef FRESADORA_H
#define FRESADORA_H

#include "Maquina.h"
#include "Componente.h"

class Fresadora : public Maquina {
private:
    int numEjes;

public:
    Fresadora(int id, const std::string& nombre, int numEjes);
    bool fresarSuperficie(Componente& comp, int tiempoSeg);
    void reparar();
};

#endif