// src/Componente.cpp
#include "Componente.h"

Componente::Componente(int id, const std::string& nombre)
    : id(id), nombre(nombre), inspeccionado(false), aprobado(false) {}

int Componente::getId() const { return id; }
std::string Componente::getNombre() const { return nombre; }
bool Componente::estaInspeccionado() const { return inspeccionado; }
bool Componente::estaAprobado() const { return aprobado; }

void Componente::setInspeccionado(bool estado) { inspeccionado = estado; }
void Componente::setAprobado(bool estado) { aprobado = estado; }