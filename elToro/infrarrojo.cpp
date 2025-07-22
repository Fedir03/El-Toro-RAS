#include "infrarrojo.h"

void setupInfra(void) {
  pinMode(sensorPin_D, INPUT);
  pinMode(sensorPin_I, INPUT);
  pinMode(sensorPin_A, INPUT);
  
  pinMode(ledCerca, OUTPUT);
  pinMode(ledLejos, OUTPUT);
}

void getInfraData(infraData_t * infraData) {
  
  // lee el valor digital de 0 (veo el borde) a 1 (no veo el borde)
  infraData->infraData_D = digitalRead(sensorPin_D);
  infraData->infraData_I = digitalRead(sensorPin_I);
  infraData->infraData_A = digitalRead(sensorPin_A);

}