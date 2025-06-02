#include <TimerOne.h>
#include "pins.h"
#include "searchAndDestroy.h"
#include "accelerometer.h"
#include "interrupts.h"
#include "globals.h"
#include "infrarrojo.h"
#include "Test.h"
#include "choqueBorde.h"

#define TIME_BETWEEN_INTERRUPTS 100000 //nanosegundos

// Variables globales
volatile bool readAccelerometerFlag = false;
MPU6050 accelerometer;


infraData_t infraData;

void setup() {
  Serial.begin(9600);
  
  pinMode(Led, OUTPUT);
  pinMode(Buzzer, OUTPUT);  

  //Inicializo ultasonico (us)
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);

  //Inicializo acelerometro
  Wire.begin();
  accelerometer.initialize();
  if (accelerometer.testConnection()) Serial.println("Acelerometro iniciado correctamente");
  else Serial.println("Error al iniciar acelerometro");

  //Configuro timer para que interrumpa cada 100ms 
  Timer1.initialize(TIME_BETWEEN_INTERRUPTS);
  Timer1.attachInterrupt(onTimerInterrupt);

}

void loop() {
  //Si la interrupcion seteó el flag, leo
  if (readAccelerometerFlag) {
    //Reseteo el flag y leo
    readAccelerometerFlag = false;
    accelerometerData accData = getAccelerometerData();
    
    //Veo si me pegaron de costado
    if (accData.ay > 2 || accData.ay < -2) {
      tone(Buzzer, 1500);
      delay(200);
      noTone(Buzzer);

      //@TODO:
      //Motores max hacia adelante por poquito tiempo (me escapo)
    }
  }

  if (readInfraFlag) {
    //Reseteo el flag y leo
    readInfraFlag = false;
    getInfraData(&infraData);
    
    if (infraData.infraData_D == 0 ){  // si el sensor manda 0 es porque ve el limite del borde
      choqueBorde("D");
    }
    else if (infraData.infraData_I == 0){
      choqueBorde("I");
    }
    else if (infraData.infraData_A == 0){
      choqueBorde("A");
    }
  }
  
  //searchAndDestroy();
}
