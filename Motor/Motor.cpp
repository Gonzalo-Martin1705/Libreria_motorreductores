#include <Arduino.h>
#include <MotorMapeo.h>
bool Girar_Der, Girar_Izq, avanzar, retroceso;
const uint8_t ena;
const uint8_t enb;
const uint8_t IN1;  //n1 es del lado Izquierdo
const uint8_t IN2;  //n2 es del lado Izquierdo
const uint8_t IN4;  //n4 es del lado Derecho
const uint8_t IN3;  //n3 es del lado Derecho




void motIzqAdelante() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
void motIzqAtras() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
void motDerAdelante() {
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
  }
void motDerAtras() {
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
  }
void encendido() {
    analogWrite(ena, map(vel, 0, 100, 0, 255));
    analogWrite(enb, map(vel, 0, 100, 0, 255));
  }
void parar() {
    analogWrite(ena, 0);
    analogWrite(enb, 0);
  }
void adelante() {
    motIzqAdelante();
    motDerAdelante();
  }
void atras() {
    motIzqAtras();
    motDerAtras();
  }
void mapeo_avance() {
  if ((distance2 > 10) && (distance2 != 400)) { 
    encendido();                                 //enciende devuelta los motorreductores
    delay(t);
    adelante();  //adelante
    delay(t2);
    avanzar = true;
    retroceso = false;
  }
}
void mapeo_retroceso() {
  if ((distance2 < 10) && (distance2 != 400)) { 
    atras();
    delay(t);
    avanzar = false;
    retroceso = true;
  }void izquierda() {
    motIzqAtras();
    motDerAdelante();
    Girar_Der = false;
    Girar_Izq = true;
  }
void derecha() {
    motIzqAdelante();
    motDerAtras();
    Girar_Der = true;
    Girar_Izq = false;
  }
}