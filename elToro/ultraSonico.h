#ifndef ULTRASONICO_H
#define ULTRASONICO_H

#include "pins.h"
#include "globals.h"
#include <Arduino.h>

#define MAX_DISTANCE 15
#define MIN_DISTANCE 0

long int ultraSonico();
long int ultraSonico_D();  // Sensor derecho
long int ultraSonico_I();  // Sensor izquierdo

#endif