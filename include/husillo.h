#ifndef HUSILLO_H
#define HUSILLO_H

#include <string>

class Husillo {
private:
    std::string nombre;
    int vidaUtilMaxima;
    int vidaUtilRestante;

public:
    // Constructor
    Husillo(const std::string& nombre, int vidaUtil);

    // Consultas
    std::string getNombre() const;
    int getVidaUtilMaxima() const;
    int getVidaUtilRestante() const;

    // Desgaste y mantenimiento
    bool desgastar();
    void restaurar();

    bool necesitaMantenimiento() const;
};

#endif