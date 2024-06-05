#include "Sensor.h"
#include "Motor.h"

// Definición de los pines de los sensores
const int pinSensorIzquierdo = A0;
const int pinSensorDerecho = A1;

// Definición de los pines de los motores
const int motorIzquierdoAnalog = 10;
const int motorIzquierdoAdelante = 9;
const int motorIzquierdoAtras = 8;
const int motorDerechoAnalog = 5;
const int motorDerechoAdelante = 6;
const int motorDerechoAtras = 7;

// Creación de instancias de sensores y motores
Sensor sensorIzquierdo(pinSensorIzquierdo);
Sensor sensorDerecho(pinSensorDerecho);
Motor motorIzquierdo(motorIzquierdoAnalog, motorIzquierdoAdelante, motorIzquierdoAtras);
Motor motorDerecho(motorDerechoAnalog, motorDerechoAdelante, motorDerechoAtras);

//Variables de detección de línea
bool sIzqEnLinea = true;
bool sDerEnLinea = true;

void setup() {
  motorIzquierdo.setVelocidadMax(127);
  motorIzquierdo.setVelocidad(70);
  motorDerecho.setVelocidadMax(255);
  motorDerecho.setVelocidad(70);
}

void loop() {
  sIzqEnLinea = sensorIzquierdo.detectarLinea();
  sDerEnLinea = sensorDerecho.detectarLinea();

  if (!sIzqEnLinea && !sDerEnLinea){
    motorDerecho.andarAdelante();
    motorIzquierdo.andarAdelante();
  }else if (!sIzqEnLinea && sDerEnLinea){
    motorDerecho.detener();
    motorIzquierdo.andarAdelante();
  }else if (sIzqEnLinea && !sDerEnLinea){
    motorDerecho.andarAdelante();
    motorIzquierdo.detener();
  }else{
    motorDerecho.detener();
    motorIzquierdo.detener();
  }
}
