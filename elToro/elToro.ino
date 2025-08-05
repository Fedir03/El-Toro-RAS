#include <TimerOne.h>
#include "pins.h"
#include "accelerometer.h"
#include "interrupts.h"
#include "globals.h"
#include "infrarrojo.h"
#include "estrategias.h"

#define TIME_BETWEEN_INTERRUPTS 20000000 //nanosegundos

// Variables globales
volatile bool readAccelerometerFlag = false;
MPU6050 accelerometer;

volatile bool readInfraFlag = false;

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
  
  // Configuro timer para que interrumpa cada 100ms 
  // Timer1.initialize(TIME_BETWEEN_INTERRUPTS);
  // Timer1.attachInterrupt(onTimerInterrupt);
  // setupInfra();
}

void loop() {
  // // Si la interrupcion seteó el flag, leo
  // if (readAccelerometerFlag) {
    //Reseteo el flag y leo
    // readAccelerometerFlag = false;
  //   elToroData.accData = getAccelerometerData();
    
  //   //Veo si me pegaron de costado
  //   if (elToroData.accData.ay > 2 || elToroData.accData.ay < -2) {
  //       motores(250, ADELANTE, &elToroData);
  //       delay(500);
  //       motores(0, APAGADO, &elToroData);
  //     }
  // // }

  // // if (readInfraFlag) {
  //   //Reseteo el flag y leo
  //   // readInfraFlag = false;
  //   getInfraData(&elToroData.infraData);
    
  //   // si el sensor manda 0 es porque ve el limite del borde
  //   if (elToroData.infraData.infraData_D == 0 ){  
  //     choqueBorde('D', &elToroData);
  //   }
  //   else if (elToroData.infraData.infraData_I == 0){
  //     choqueBorde('I', &elToroData);
  //   }
  //   else if (elToroData.infraData.infraData_A == 0){
  //     choqueBorde('A', &elToroData);
  //   }
  // }

  searchAndDestroy(&elToroData);
}
