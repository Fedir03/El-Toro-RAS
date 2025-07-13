// codigo para cuando el robot encuentra el borde
#include "choqueBorde.h"

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
