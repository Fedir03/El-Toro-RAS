// codigo para cuando el robot encuentra el borde
#include "estrategias.h"

void choqueBorde(char direccion) {

  // para los motores
  motores(0, APAGADO);

  // gira dependiendo de que infrarrojo viò el borde
  if (direccion == 'D'){
    // gira a la izquierda
    motor_d(200, ADELANTE);
    motor_i(100, REVERSA);
  }
  if (direccion == 'I'){
    // gira a la derecha
    motor_i(200, ADELANTE);
    motor_d(100, REVERSA);
  }
  if (direccion == 'A'){
    // va para atras
    motores(100, REVERSA);

    // aca deberiamos elegir si girar a la izquierda o a la derecha
    // izquierda:
    //motor_d(200, "ADELANTE")
    //motor_i(100, "REVERSA")
    // derecha:
    //motor_i(200, "ADELANTE")
    //motor_d(100, "REVERSA")
  }

}

void searchAndDestroy(elToroData_t *elToroData) {
  
  elToroData->d = ultraSonico();
  
  //@FLOWCHART: "Lo Veo?"
  if (elToroData->d > 15 && elToroData->d < 100) {
    //Motores max hacia adelante (voy a buscarlo)
    digitalWrite(ledLejos, HIGH);
    digitalWrite(ledCerca, LOW);
    motores(100, ADELANTE);
  } else {

    //@TODO:
    //Logica de frenado y giro para buscarlo

    digitalWrite(ledLejos, LOW);
    digitalWrite(ledCerca, HIGH);
    motores(100, APAGADO);
  }


  // Serial.print("Distancia: ");
  // Serial.print(d);      //Printeo distancia en cm medida por us
  // Serial.print("cm");
  // Serial.println();
  delay(5);        
  
}