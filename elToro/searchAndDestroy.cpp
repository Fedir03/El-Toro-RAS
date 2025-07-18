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
  t = pulseIn(Echo, HIGH);
  d = t/59;

  
  //@FLOWCHART: "Lo Veo?"
  if (d > 0 && d < 77) {
    //Prendo led
    digitalWrite(Led, HIGH);
    
    //@TODO:
    //Motores max hacia adelante (voy a buscarlo)
    for (int i = 200; i > 0; i--) {
      motor_d(i, ADELANTE);
      delay(20);
    }
    //Grita mas agudo mientras mas cerca lo ve :D
    freq = map(d, 0, 100, 1500, 100);
    tone(Buzzer, freq);
    
  } else {
    noTone(Buzzer);
    digitalWrite(Led, LOW);
    motor_d(254, REVERSA);

    //@TODO:
    //Logica de frenado y giro para buscarlo

    motores(250, APAGADO);
  }


  Serial.print("Distancia: ");
  Serial.print(d);      //Printeo distancia en cm medida por us
  Serial.print("cm");
  Serial.println();
  delay(5);        
  
}