#ifndef INFRARROJO_H
#define INFRARROJO_H

#include "pins.h"
#include "globals.h"
#include <Arduino.h>

void setupInfra(void);
void getInfraData(infraData_t * infraData);
 
#endif