// para medir el valor del sensor infrarrojo

infrarrojoData getInfraData() {
  
  int sensorPin_D = 4; // TCRT5000 signal conectado al pin digital derecho
  int sensorPin_I = 5; // TCRT5000 signal conectado al pin digital izquierdo
  int sensorPin_A = 6; // TCRT5000 signal conectado al pin digital adelante

  int sensorValue_D = 0; // Variable para almacenar el valor del sensor derecho
  int sensorValue_I = 0; // Variable para almacenar el valor del sensor izquierdo
  int sensorValue_A = 0; // Variable para almacenar el valor del sensor adelante

  // lee el valor digital de 0 a 1
  infraData_D = digitalRead(sensorPin_D);
  infraData_I = digitalRead(sensorPin_I);
  infraData_A = digitalRead(sensorPin_A);

  return infraData_D, infraData_I, infraData_A;
}