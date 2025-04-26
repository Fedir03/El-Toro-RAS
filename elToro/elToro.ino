#include "pins.h"
#include "searchAndDestroy.h"
#include "accelerometer.h"

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  
  pinMode(Led, OUTPUT);
  pinMode(Buzzer, OUTPUT);  

  Wire.begin();
  accelerometer.initialize();
  if (accelerometer.testConnection()) Serial.println("Acelerometro iniciado correctamente");
  else Serial.println("Error al iniciar acelerometro");
}

void loop() {
  //Si la interrupcion seteó el flag, leo
  if (readAccelerometerFlag) {
    //Reseteo el flag y leo
    readAccelerometerFlag = false
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

  searchAndDestroy();
}
