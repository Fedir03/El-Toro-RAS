#ifndef PINS_H
#define PINS_H

#include "MPU6050.h"

const int Trigger = 2;
const int Echo = 3;

const int Led = 13;
const int Buzzer = 8;

extern MPU6050 accelerometer;

//pongo cualquier pin despues ver cuales tengo disponibles
//estan en el orden del puente H
const int pin_PWM_D = 6;           //ENA
const int pin_Motor_D1 = 10;        //IN1 
const int pin_Motor_D2 = 11;        //IN2
const int pin_Motor_I1 = 17;        //IN3
const int pin_Motor_I2 = 18;        //IN4
const int pin_PWM_I = 19;           //ENB

#endif