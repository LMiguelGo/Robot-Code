#ifndef Motor_h
#define Motor_h
#include "Arduino.h"

class Motor {
  private:
    int analogPin;
    int pinAdelante, pinAtras;
    int velocidad, velocidadMax;
  
  public:
    Motor(int anPin, int pinAdel, int pinAtr);
    void setVelocidad(int nuevaVelocidad);
    void setVelocidadMax(int nuevaVelocidad);
    void andarAdelante();
    void andarAtras();
    void detener();
};

#endif
