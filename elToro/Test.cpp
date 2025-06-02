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
  digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
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
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  analogWrite(ENA, 100); // Velocidad media (0 a 255)
  analogWrite(ENB, 100);
  
  } else {
    digitalWrite(ledCerca, LOW);
    digitalWrite(ledLejos, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 100); // Velocidad media (0 a 255)
    analogWrite(ENB, 100);
  }

  delay(400); // Pequeño retardo para estabilidad
}
