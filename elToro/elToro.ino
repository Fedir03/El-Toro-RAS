#include "pins.h"
#include "accelerometer.h"
#include "globals.h"
#include "infrarrojo.h"
#include "motor.h"
#include "ultraSonico.h"

#define TIME_BETWEEN_INTERRUPTS 20000000 //nanosegundos

volatile bool infraDetectado_I = false;
volatile bool infraDetectado_D = false;

bool inicioSolicitado = false;
unsigned long tiempoInicioConteo;

void isr_Infra_I() {
  infraDetectado_I = true;
}

void isr_Infra_D() {
  infraDetectado_D = true;
}
  
enum RobotState {
  MODO_BUSQUEDA,
  MODO_ATAQUE,
  MODO_EVASION_D,
  MODO_EVASION_I,
  MODO_EVASION_A
};

RobotState estadoActual = MODO_BUSQUEDA;
unsigned long tiempoInicioManiobra = 0;
bool enManiobra = false;

MPU6050 accelerometer;

elToroData_t elToroData;

void setup() {
  // Serial.begin(9600);

  //Inicializo ultasonico (us)
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  
   setup_motor(&elToroData);

  // Inicializo acelerometro
  Wire.begin();
  accelerometer.initialize();
  
  setupInfra();

  attachInterrupt(digitalPinToInterrupt(sensorPin_I), isr_Infra_I, FALLING);
  attachInterrupt(digitalPinToInterrupt(sensorPin_D), isr_Infra_D, FALLING);

  pinMode(batalla, INPUT_PULLUP); 
}

void loop() {
  if (!inicioSolicitado && digitalRead(batalla) == LOW) {
    inicioSolicitado = true;
    tiempoInicioConteo = millis();
    digitalWrite(ledLejos, HIGH);
  }

  if (inicioSolicitado && (millis() - tiempoInicioConteo > 5000)) {
    digitalWrite(ledLejos, LOW);

    if (infraDetectado_D) {
      infraDetectado_D = false;
      estadoActual = MODO_EVASION_D;
      tiempoInicioManiobra = millis();
      enManiobra = true;
    } else if (infraDetectado_I) {
      infraDetectado_I = false;
      estadoActual = MODO_EVASION_I;
      tiempoInicioManiobra = millis();
      enManiobra = true;
    }

    switch (estadoActual) {

      case MODO_BUSQUEDA:
        elToroData.d = ultraSonico();
        if (elToroData.d > 0 && elToroData.d < 30) {
          estadoActual = MODO_ATAQUE;
        } else {
          motor_d(80, ADELANTE, &elToroData);
          motor_i(80, REVERSA, &elToroData);
        }
        break;

      case MODO_ATAQUE:
        motores(255, ADELANTE, &elToroData);
        elToroData.d = ultraSonico();
        if (elToroData.d >= 30 || elToroData.d < 0) {
          motores(0, APAGADO, &elToroData);
          estadoActual = MODO_BUSQUEDA;
          enManiobra = false;
        }
        break;

      case MODO_EVASION_D:
        if (enManiobra) {
          if (millis() - tiempoInicioManiobra < 500) {
            motor_d(100, ADELANTE, &elToroData);
            motor_i(100, REVERSA, &elToroData);
          }
          else if (millis() - tiempoInicioManiobra < 800) {
            motores(120, ADELANTE, &elToroData);
          }
          else {
            motores(0, APAGADO, &elToroData);
            enManiobra = false;
            estadoActual = MODO_BUSQUEDA;
          }
        }
        break;

      case MODO_EVASION_I:
        if (enManiobra) {
          if (millis() - tiempoInicioManiobra < 500) {
            motor_d(100, REVERSA, &elToroData);
            motor_i(100, ADELANTE, &elToroData);
          }
          else if (millis() - tiempoInicioManiobra < 800) {
            motores(120, ADELANTE, &elToroData);
          }
          else {
            motores(0, APAGADO, &elToroData);
            enManiobra = false;
            estadoActual = MODO_BUSQUEDA;
          }
        }
      break;

      case MODO_EVASION_A:
        getInfraData(&elToroData.infraData);
        if (elToroData.infraData.infraData_A == 0) {
          motores(200, APAGADO, &elToroData);
        } else {
          elToroData.d = ultraSonico();
          if (elToroData.d >= 0 && elToroData.d < 100) {
            estadoActual = MODO_ATAQUE;
          } else {
            motores(0, APAGADO, &elToroData);
            estadoActual = MODO_BUSQUEDA;
          }
        }
      break;
    }
  }
}