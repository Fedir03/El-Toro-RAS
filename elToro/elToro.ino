#include "pins.h"
#include "searchAndDestroy.h"

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  
  pinMode(Led, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  
  digitalWrite(Trigger, LOW);
}

void loop() {
  searchAndDestroy();
}
