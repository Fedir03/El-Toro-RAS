#include "TestInfra.h"

// codigo de prueba para testear los sensores a infrarrojos y los motores

void setup_test_infra(void) {
  pinMode(sensorPin_D, INPUT);
  pinMode(sensorPin_I, INPUT);
  pinMode(sensorPin_A, INPUT);
  
  pinMode(ledCerca, OUTPUT);
  pinMode(ledLejos, OUTPUT);
  motores(0, APAGADO);
  Serial.begin(9600);
}


void test_infra(void) {

  int infra_D = 1;
  int infra_I = 1;
  int infra_A = 1;

  // ver que mandan los sensores infras
  infra_D = digitalRead(sensorPin_D);
  infra_I = digitalRead(sensorPin_I);
  infra_A = digitalRead(sensorPin_A);
  
  // Encender LED correspondiente y girar
  if (infra_D == 0 || infra_I == 0 || infra_A == 0) {
    if (infra_D == 0) {// si ve algo a la derecha gira a la izquierda y aprende el ledCerca
        digitalWrite(ledCerca, HIGH);
        digitalWrite(ledLejos, LOW);
        motor_d(100, ADELANTE);
    
    } else if (infra_I == 0){// si ve algo a la izquierda gira a la derecha y aprende el ledLejos
        digitalWrite(ledCerca, LOW);
        digitalWrite(ledLejos, HIGH);
        motor_i(100, ADELANTE);
    
    } else if (infra_A == 0){// si ve algo adelante va para atras, aprende ambos los leds y genera sonido
        digitalWrite(ledCerca, HIGH);
        digitalWrite(ledLejos, HIGH);
        motores(100, REVERSA);

        digitalWrite(trigPin, HIGH);
        delay(500);
        digitalWrite(trigPin, LOW);
    }
  } else {// si no ve nada apaga los leds
    digitalWrite(ledCerca, LOW);
    digitalWrite(ledLejos, LOW);
    motores(100, APAGADO);

  }

  delay(400); // Pequeño retardo para estabilidad

}