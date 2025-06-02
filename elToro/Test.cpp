// Pines del sensor
#include "Test.h"


void setup_test(void) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledCerca, OUTPUT);
  pinMode(ledLejos, OUTPUT);
  Serial.begin(9600);
}

void test(void) {
  // Generar pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir duración del eco
  long duration = pulseIn(echoPin, HIGH);

  // Calcular distancia en cm
  float distance = duration * 0.0343 / 2;

  // Mostrar en el monitor serie
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Encender LED correspondiente
  if (abs(distance) < 5) {
    digitalWrite(ledCerca, HIGH);
    digitalWrite(ledLejos, LOW);
    motores(100, ADELANTE);
  
  } else {
    digitalWrite(ledCerca, LOW);
    digitalWrite(ledLejos, HIGH);
    motores(100, REVERSA);
  }

  delay(400); // Pequeño retardo para estabilidad
}
