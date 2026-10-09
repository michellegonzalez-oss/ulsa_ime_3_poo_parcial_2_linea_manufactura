// include/Componente.h
#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <string>

class Componente {
private:
    int id;
    std::string nombre;
    bool inspeccionado;
    bool aprobado;

public:
    Componente(int id, const std::string& nombre);

    int getId() const;
    std::string getNombre() const;
    bool estaInspeccionado() const;
    bool estaAprobado() const;

    void setInspeccionado(bool estado);
    void setAprobado(bool estado);
};

#endif