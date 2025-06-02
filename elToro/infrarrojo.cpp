// para medir el valor del sensor infrarrojo

#include "pins.h"
#include "infrarrojo.h"

//int infraData_D = 0; // Variable para almacenar el valor del sensor derecho
//int infraData_I = 0; // Variable para almacenar el valor del sensor izquierdo
//int infraData_A = 0; // Variable para almacenar el valor del sensor adelante

void getInfraData(infraData_t * infraData) {
  

  // lee el valor digital de 0 (veo el borde) a 1 (no veo el borde)
  infraData->infraData_D = digitalRead(sensorPin_D);
  infraData->infraData_I = digitalRead(sensorPin_I);
  infraData->infraData_A = digitalRead(sensorPin_A);


}

  //int sensorPin_D = 4; // TCRT5000 signal conectado al pin digital derecho
  //int sensorPin_I = 5; // TCRT5000 signal conectado al pin digital izquierdo
  //int sensorPin_A = 6; // TCRT5000 signal conectado al pin digital adelante

   // return infraData_D, infraData_I, infraData_A;