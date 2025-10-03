#include "pins.h"
#include "accelerometer.h"
#include "globals.h"
#include "infrarrojo.h"
#include "motor.h"
#include "ultraSonico.h"

#define TIME_BETWEEN_INTERRUPTS 20000000  //nanosegundos

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

  // Inicializo ultrasónicos derecho e izquierdo
  pinMode(Trigger_D, OUTPUT);
  pinMode(Echo_D, INPUT);
  pinMode(Trigger_I, OUTPUT);
  pinMode(Echo_I, INPUT);
  digitalWrite(Trigger_D, LOW);
  digitalWrite(Trigger_I, LOW);

  setup_motor(&elToroData);

  // Inicializo acelerómetro
  Wire.begin();
  accelerometer.initialize();

  setupInfra();

  attachInterrupt(digitalPinToInterrupt(sensorPin_I), isr_Infra_I, FALLING);
  attachInterrupt(digitalPinToInterrupt(sensorPin_D), isr_Infra_D, FALLING);

  pinMode(LED_BUILTIN, OUTPUT);  // Configuramos el LED interno como salida

  pinMode(batalla, INPUT_PULLUP);
}

void loop() {

  if (!inicioSolicitado && digitalRead(batalla) == LOW) {
    inicioSolicitado = true;
    tiempoInicioConteo = millis();
    digitalWrite(ledLejos, HIGH);
  }

  bool isEnemyOnTheRight;
  bool isEnemyOnTheLeft;

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
        elToroData.d_d = ultraSonico_D();
        elToroData.d_i = ultraSonico_I();

        isEnemyOnTheRight = (elToroData.d_d > MIN_DISTANCE && elToroData.d_d < MAX_DISTANCE);
        isEnemyOnTheLeft = (elToroData.d_i > MIN_DISTANCE && elToroData.d_i < MAX_DISTANCE);

        if (isEnemyOnTheLeft && isEnemyOnTheRight) {
          estadoActual = MODO_ATAQUE;
        }
        else if (isEnemyOnTheRight || isEnemyOnTheLeft) {
          int rightWheelDirection = isEnemyOnTheRight ? REVERSA : ADELANTE;
          int leftWheelDirection = isEnemyOnTheRight ? ADELANTE : REVERSA;
          motor_d(50, rightWheelDirection, &elToroData);
          motor_i(50, leftWheelDirection, &elToroData);
          estadoActual = MODO_ATAQUE;
        }
        else {
          motor_d(100, ADELANTE, &elToroData);
          motor_i(100, REVERSA, &elToroData);
        }
        break;

      case MODO_ATAQUE:
        motores(255, ADELANTE, &elToroData);
        elToroData.d_d = ultraSonico_D();
        elToroData.d_i = ultraSonico_I();
        isEnemyOnTheRight = (elToroData.d_d > MIN_DISTANCE && elToroData.d_d < MAX_DISTANCE);
        isEnemyOnTheLeft = (elToroData.d_i > MIN_DISTANCE && elToroData.d_i < MAX_DISTANCE);
        if ((isEnemyOnTheLeft != isEnemyOnTheRight) || (!isEnemyOnTheLeft && !isEnemyOnTheRight)) {
          motores(0, APAGADO, &elToroData);
          estadoActual = MODO_BUSQUEDA;
          enManiobra = false;
        }
        break;

      case MODO_EVASION_D:
        if (enManiobra) {
          if (millis() - tiempoInicioManiobra < 600) {
            motor_d(50, ADELANTE, &elToroData);
            motor_i(50, REVERSA, &elToroData);
          }
          else if (millis() - tiempoInicioManiobra < 900) {
            motores(80, ADELANTE, &elToroData);
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
          if (millis() - tiempoInicioManiobra < 600) {
            motor_d(50, REVERSA, &elToroData);
            motor_i(50, ADELANTE, &elToroData);
          }
          else if (millis() - tiempoInicioManiobra < 900) {
            motores(80, ADELANTE, &elToroData);
          }
          else {
            motores(0, APAGADO, &elToroData);
            enManiobra = false;
            estadoActual = MODO_BUSQUEDA;
          }
        }
      break;
    }
  }
}