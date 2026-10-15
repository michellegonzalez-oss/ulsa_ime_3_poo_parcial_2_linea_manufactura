#ifndef HERRAMIENTACORTE_H
#define HERRAMIENTACORTE_H

class HerramientaCorte {
private:
    int vidaUtil;      // Piezas restantes
    int vidaMaxima;    // Límite de vida útil

public:
    HerramientaCorte(int vidaMaxima = 10);

    bool desgastar();
    void reemplazar();
    int getVidaUtil() const;
    int getVidaMaxima() const;
};

#endif