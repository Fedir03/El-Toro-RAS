#include <Arduino.h>
#include "interrupts.h"
#include "globals.h"

void onTimerInterrupt() {
  readAccelerometerFlag = true;
  readInfraFlag = true;
}