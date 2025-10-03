#ifndef PINS_H
#define PINS_H

#include "pins_arduino.h"
#include "MPU6050.h"

// Ultrasonido
//const int Trigger = 12;
//const int Echo = 0;

// Ultrasonido derecho e izquierdo
const int Trigger_D = A2;
const int Echo_D = 13;
const int Trigger_I = 9;
const int Echo_I = 12;

extern MPU6050 accelerometer;

// Pines para el puente H (H-Bridge)
const int pin_PWM_I = 5;        // ENA
const int pin_Motor_I2 = 4;     // IN1 
const int pin_Motor_I1 = 1;    // IN2
const int pin_Motor_D2 = 7;     // IN3
const int pin_Motor_D1 = 8;     // IN4
const int pin_PWM_D = 6;        // ENB
const int pin_STBY = 0;          // STBY

// Pines para test
const int ENA = pin_PWM_D;
const int IN1 = pin_Motor_D1;
const int IN2 = pin_Motor_D2;
const int ENB = pin_Motor_I1;
const int IN3 = pin_Motor_I2;
const int IN4 = pin_PWM_I;

//const int trigPin = Trigger;
//const int echoPin = Echo;

// Pines de los LEDs
const int ledCerca = A1;
const int ledLejos = A0;

// Pines del infrarrojo
//const int sensorPin_A = 2;  // IR1 (Atras)
const int sensorPin_D = 3;  // IR2 (Derecha) - INTERRUPCIÓN 1
const int sensorPin_I = 2;  // IR3 (Izquierda) - INTERRUPCIÓN 0

// botoncitos
const int batalla = 11;
const int modo = 10;

#endif  