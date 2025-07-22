#include "pins_arduino.h"
#include "pins.h"
#include "searchAndDestroy.h"
#include "motor.h"
#include <Arduino.h>

void searchAndDestroy() {
  
  long t; // tiempo entre que se emite y se recibe el pulso
  long d; // distancia hasta el objeto en cm

  int freq = 0;
  
  // Emito 10us de pulso desde Trig
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // Recibo pulso desde Echo
  t = pulseIn(Echo, HIGH, 30000);
  d = t/59;

  
  //@FLOWCHART: "Lo Veo?"
  if (d > 15 && d < 100) {
    //Motores max hacia adelante (voy a buscarlo)
    digitalWrite(ledLejos, HIGH);
    digitalWrite(ledCerca, LOW);
    motores(100, ADELANTE);
  } else {

    //@TODO:
    //Logica de frenado y giro para buscarlo

    digitalWrite(ledLejos, LOW);
    digitalWrite(ledCerca, HIGH);
    motores(100, APAGADO);
  }


  // Serial.print("Distancia: ");
  // Serial.print(d);      //Printeo distancia en cm medida por us
  // Serial.print("cm");
  // Serial.println();
  delay(5);        
  
}