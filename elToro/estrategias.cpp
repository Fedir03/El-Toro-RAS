// codigo para cuando el robot encuentra el borde
#include "estrategias.h"

#define GIRO_EVASIVO(der, izq)          \
    motor_d(200, der, elToroData);      \
    motor_i(100, izq, elToroData);      \
    delay(500);                         \
    motores(0, APAGADO, elToroData);    \
    motores(100, REVERSA, elToroData);  \
    delay(300);                         \
    motores(0, APAGADO, elToroData);    \
  

void choqueBorde(char direccion, elToroData_t *elToroData) {

  // para los motores
  motores(0, APAGADO, elToroData);

  // gira dependiendo de que infrarrojo viò el borde
  if (direccion == 'D'){
    // gira a la izquierda por medio segundo
    GIRO_EVASIVO(ADELANTE, REVERSA);
  } else if (direccion == 'I'){
    GIRO_EVASIVO(REVERSA, ADELANTE);
  } else if (direccion == 'A'){
    // va para atras por medio segundo
    motores(100, REVERSA, elToroData);
    delay(500);
    motores(0, APAGADO, elToroData);
    motor_d(200, ADELANTE, elToroData); // gira hacia la izquierda por 300ms
    motor_i(100, REVERSA, elToroData);
    delay(300);
    motores(0, APAGADO, elToroData);
  }

}

void searchAndDestroy(elToroData_t *elToroData) {
  
  elToroData->d = ultraSonico();
  
  //@FLOWCHART: "Lo Veo?"
  if (elToroData->d > 15 && elToroData->d < 100) {
    //Motores max hacia adelante (voy a buscarlo)
    digitalWrite(ledLejos, HIGH);
    digitalWrite(ledCerca, LOW);
    motores(50, ADELANTE, elToroData);
    
  } else {

    //@TODO:
    //Logica de frenado y giro para buscarlo

    digitalWrite(ledLejos, LOW);
    digitalWrite(ledCerca, HIGH);
    motor_d(50, ADELANTE, elToroData); // gira hacia la izquierda por medio segundo
    motor_i(50, REVERSA, elToroData);
    delay(100);
    motores(0, APAGADO, elToroData);
  }


  // Serial.print("Distancia: ");
  // Serial.print(d);      //Printeo distancia en cm medida por us
  // Serial.print("cm");
  // Serial.println();
  delay(5);        
  
}