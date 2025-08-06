#ifndef PINS_H
#define PINS_H

#include "pins_arduino.h"
#include "MPU6050.h"

// Ultrasonido
const int Trigger = 12;
const int Echo = 0;

extern MPU6050 accelerometer;

// Pines para el puente H (H-Bridge)
const int pin_PWM_D = 5;        // ENA
const int pin_Motor_D1 = 4;     // IN1 
const int pin_Motor_D2 = A1;    // IN2
const int pin_Motor_I1 = 6;     // IN3
const int pin_Motor_I2 = 7;     // IN4
const int pin_PWM_I = 9;        // ENB

// Pines para test
const int ENA = pin_PWM_D;
const int IN1 = pin_Motor_D1;
const int IN2 = pin_Motor_D2;
const int ENB = pin_Motor_I1;
const int IN3 = pin_Motor_I2;
const int IN4 = pin_PWM_I;

const int trigPin = Trigger;
const int echoPin = Echo;

// Pines de los LEDs
const int ledCerca = 13;
const int ledLejos = A0;

// Pines del infrarrojo
const int sensorPin_A = 2;  // IR1 (Adelante) - INTERRUPCIÓN 0
const int sensorPin_D = 3;  // IR2 (Derecha) - INTERRUPCIÓN 1
const int sensorPin_I = 1;  // IR3 (Izquierda)

// botoncitos
const int batalla = 14;
// const int modo = 13;

#endif  