#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int analog, int adelPin, int atrPin){
  analogPin = analog;
  pinAdelante = adelPin;
  pinAtras = atrPin;
  velocidad = 255;
  velocidadMax = 255;
  pinMode(analogPin, OUTPUT);
  pinMode(pinAdelante, OUTPUT);
  pinMode(pinAtras, OUTPUT);
}

void Motor::setVelocidad(int nuevaVelocidad){
  //Se manejará una entrada entre 0 y 100
  velocidad = (nuevaVelocidad*velocidadMax)/100;
}

void Motor::setVelocidadMax(int nuevaVelocidad){
  velocidadMax = nuevaVelocidad;
}

void Motor::andarAdelante(){
  analogWrite(analogPin, velocidad);
  digitalWrite(pinAdelante, HIGH);
  digitalWrite(pinAtras,LOW);
}

void Motor::andarAtras(){
  analogWrite(analogPin, velocidad);
  digitalWrite(pinAdelante, LOW);
  digitalWrite(pinAtras,HIGH);
}

void Motor::detener(){
  analogWrite(analogPin, 0);
  digitalWrite(pinAdelante, LOW);
  digitalWrite(pinAtras,LOW);
}
