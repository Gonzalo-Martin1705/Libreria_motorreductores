#include <Arduino.h>
#include <MotorMapeo.h>
#include <DistanceSensor.h>
#include <Variables.h> 
const uint8_t ena = 11;
const uint8_t enb = 3;
const int echoPin = 5;
const int trigPin = 4;
const uint8_t IN1 = 9;  
const uint8_t IN2 = 8;  
const uint8_t IN4 = 7;  
const uint8_t IN3 = 6;  

void INIT(){
    pinMode(ena, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(enb, OUTPUT);
    pinMode(trigPin, INPUT);
    pinMode(echoPin, INPUT);
    analogWrite(ena, map(vel, 0, 100, 0, 255));
    analogWrite(enb, map(vel, 0, 100, 0, 255));
    Serial.begin(9600);
}

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
        encendido(); // Enciende los motores
        adelante(); // Mueve hacia adelante
        delay(t2);
        avanzar = true;
        retroceso = false;
    }
}

void mapeo_retroceso() {
    if ((distance2 < 10) && (distance2 != 400)) { 
        encendido(); // Enciende los motores
        atras(); // Mueve hacia atrás
        delay(t);
        avanzar = false;
        retroceso = true;
    }
}

void izquierda() {
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
