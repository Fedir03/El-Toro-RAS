#include "infrarrojo.h"

void setupInfra(void) {
  pinMode(sensorPin_I, INPUT_PULLUP);
  pinMode(sensorPin_D, INPUT_PULLUP);
  pinMode(sensorPin_A, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensorPin_I), isr_Infra_I, FALLING);
  attachInterrupt(digitalPinToInterrupt(sensorPin_D), isr_Infra_D, FALLING);

  pinMode(ledCerca, OUTPUT);
  pinMode(ledLejos, OUTPUT);
}