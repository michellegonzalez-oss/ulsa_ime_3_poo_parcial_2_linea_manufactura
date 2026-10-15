#ifndef SENSORCALIBRACION_H
#define SENSORCALIBRACION_H

class SensorCalibracion {
private:
    int lecturasRestantes; // Lecturas de precisión que le quedan al sensor
    int lecturasMaximas;   // Capacidad total de lecturas antes de requerir recalibración
    double precisionMm;    // Tolerancia actual en mm (ej. 0.01 mm)

public:
    SensorCalibracion(int lecturasMaximas = 30, double precisionMm = 0.01);

    bool desgastar();
    void recalibrar();
    int getLecturasRestantes() const;
    int getLecturasMaximas() const;
    double getPrecision() const;
};

#endif
