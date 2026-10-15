#include "SensorCalibracion.h"

SensorCalibracion::SensorCalibracion(int lecturasMaximas, double precisionMm)
    : lecturasMaximas(lecturasMaximas > 0 ? lecturasMaximas : 30),
      lecturasRestantes(lecturasMaximas > 0 ? lecturasMaximas : 30),
      precisionMm(precisionMm > 0.0 ? precisionMm : 0.01) {}

bool SensorCalibracion::desgastar() {
    if (lecturasRestantes > 0) {
        lecturasRestantes--;
    }
    // Si llega a 0 lecturas, el sensor pierde calibración y entra en falla
    return lecturasRestantes == 0;
}

void SensorCalibracion::recalibrar() {
    lecturasRestantes = lecturasMaximas;
}

int SensorCalibracion::getLecturasRestantes() const {
    return lecturasRestantes;
}

int SensorCalibracion::getLecturasMaximas() const {
    return lecturasMaximas;
}

double SensorCalibracion::getPrecision() const {
    return precisionMm;
}