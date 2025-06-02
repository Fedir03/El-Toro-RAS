#ifndef PINS_H
#define PINS_H

#include "MPU6050.h"

const int Trigger = 7;
const int Echo = 8;

const int Led = 13;
const int Buzzer = 11;

extern MPU6050 accelerometer;

//pongo cualquier pin despues ver cuales tengo disponibles
//estan en el orden del puente H
const int pin_PWM_D = 5;           //ENA
const int pin_Motor_D1 = 1;        //IN1 
const int pin_Motor_D2 = 2;        //IN2
const int pin_Motor_I1 = 3;        //IN3
const int pin_Motor_I2 = 4;        //IN4
const int pin_PWM_I = 6;           //ENB


//pines para test
int ENA = pin_PWM_D;  // D5 es un pin PWM en el Arduino Uno
int IN1 = pin_Motor_D1;  // D2
int IN2 = pin_Motor_D2;  // D4
int ENB = pin_Motor_I1;  // D5 es un pin PWM en el Arduino Uno
int IN3 = pin_Motor_I2;  // D2
int IN4 = pin_PWM_I;  // D4

const int trigPin = Trigger;
const int echoPin = Echo;

// Pines de los LEDs
const int ledCerca = 9;  // Se enciende a 5 cm
const int ledLejos = 10;  // Se enciende si NO está a 5 cm


//pines del infrarrojo
// el 1 es el adelante
// 2 derecha
// 3 izquierda
const int sensorPin_D = 11;
const int sensorPin_I = 12;
const int sensorPin_A = 13;

// botoncitos
const int batalla = 14;
const int modo = 13;

#endif