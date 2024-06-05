#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor(int pin) {
  pinEntrada = pin;
  pinMode(pinEntrada, INPUT);
  valorReferencia = 500;
}

int Sensor::leerValor() {
  return analogRead(pinEntrada);
}

bool Sensor::detectarLinea() {
  int valorDetectado = analogRead(pinEntrada);
  if (valorDetectado < valorReferencia){
    return false;
  }else{
    return true;
  }
}
