#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

#include "motor.h"
#include "ultraSonico.h"
#include "infrarrojo.h"
#include "pins.h"
#include "globals.h"
#include <Arduino.h>

void choqueBorde(char direccion, elToroData_t *elToroData);
void searchAndDestroy(elToroData_t *elToroData);

#endif