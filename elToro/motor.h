#ifndef MOTOR_H
#define MOTOR_H

//define variables
#define CICLO_BASE 128
#define APAGADO 0
#define ADELANTE 1
#define REVERSA 2

//includes
#include "pins.h"
#include "globals.h"
#include <Arduino.h>
#include <stdint.h>

//prototipos de las funciones
void setup_motor (elToroData_t *);
void motor_d (uint8_t potencia, uint8_t estado, elToroData_t *); 
void motor_i (uint8_t potencia, uint8_t estado, elToroData_t *);
void motores (uint8_t potencia, uint8_t estado, elToroData_t *);

#endif