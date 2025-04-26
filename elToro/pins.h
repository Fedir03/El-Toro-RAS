#ifndef PINS_H
#define PINS_H

#include "MPU6050.h"

const int Trigger = 2;
const int Echo = 3;

const int Led = 13;
const int Buzzer = 8;

extern MPU6050 accelerometer;

#endif