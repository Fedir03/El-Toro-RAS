//#include "pins_arduino.h"

#include "ultraSonico.h"

// long int ultraSonico() {
  
//   long t; // tiempo entre que se emite y se recibe el pulso
//   long d; // distancia hasta el objeto en cm

//   int freq = 0;
  
//   // Emito 10us de pulso desde Trig
//   digitalWrite(Trigger, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(Trigger, LOW);

//   // Recibo pulso desde Echo
//   t = pulseIn(Echo, HIGH, 30000);
//   d = t/59;

//   return d;
// }

long int ultraSonico_D() {
  long t;
  long d;
  
  digitalWrite(Trigger_D, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger_D, LOW);

  t = pulseIn(Echo_D, HIGH, 30000);
  d = t/59;

  return d;
}

long int ultraSonico_I() {
  long t;
  long d;
  
  digitalWrite(Trigger_I, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger_I, LOW);

  t = pulseIn(Echo_I, HIGH, 30000);
  d = t/59;

  return d;
}