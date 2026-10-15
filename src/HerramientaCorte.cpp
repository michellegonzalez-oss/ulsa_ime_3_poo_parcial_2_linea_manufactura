#include "HerramientaCorte.h"
#include <iostream>

HerramientaCorte::HerramientaCorte(int vidaMaxima)
    : vidaMaxima(vidaMaxima > 0 ? vidaMaxima : 10), vidaUtil(vidaMaxima > 0 ? vidaMaxima : 10) {}

bool HerramientaCorte::desgastar() {
    if (vidaUtil > 0) {
        vidaUtil--;
    }
    return vidaUtil == 0; // Retorna verdadero si alcanzó el límite de desgaste
}

void HerramientaCorte::reemplazar() {
    vidaUtil = vidaMaxima;
}

int HerramientaCorte::getVidaUtil() const {
    return vidaUtil;
}

int HerramientaCorte::getVidaMaxima() const {
    return vidaMaxima;
}