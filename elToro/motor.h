#ifndef MOTOR_H
#define MOTOR_H

//define variables
#define CICLO_BASE 128
#define APAGADO 0
#define ADELANTE 1
#define REVERSA 2

//prototipos de las funciones
void setup_motor ();
void motor_d (uint8_t dutyCycle, uint8_t estado);
void motor_i (uint8_t dutyCycle, uint8_t estado);
void motores (uint8_t dutyCycle, uint8_t estado);

#endif