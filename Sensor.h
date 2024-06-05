#ifndef Sensor_h
#define Sensor_h
#include <Arduino.h>

class Sensor {
  private:
    int pinEntrada;
    int valorReferencia;

  public:
    Sensor(int pin);
    int leerValor();
    bool detectarLinea();
};

#endif
