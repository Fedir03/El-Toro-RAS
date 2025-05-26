#ifndef PINS_H
#define PINS_H

#include "MPU6050.h"

const int Trigger = 5;
const int Echo = 2;

const int Led = 13;
const int Buzzer = 11;

extern MPU6050 accelerometer;

//pongo cualquier pin despues ver cuales tengo disponibles
//estan en el orden del puente H
const int pin_PWM_D = 6;           //ENA
const int pin_Motor_D1 = 7;        //IN1 
const int pin_Motor_D2 = 8;        //IN2
const int pin_Motor_I1 = 9;        //IN3
const int pin_Motor_I2 = 10;        //IN4
const int pin_PWM_I = 12;           //ENB

//pines del infrarrojo
// el 1 es el adelante
// 2 derecha
// 3 izquierda
const int sensorPin_D = 20;
const int sensorPin_I = 1;
const int sensorPin_A = 15;

// botoncitos
const int batalla = 14;
const int modo = 13;

#endif