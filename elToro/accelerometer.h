#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "pins.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include <Arduino.h>
#include "globals.h"

accelerometerData_t getAccelerometerData();

#endif