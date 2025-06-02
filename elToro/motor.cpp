#include <stdint.h>
#include "motor.h"
#include "pins.h"
#include <Arduino.h>

static uint8_t estado_motor_d;
static uint8_t estado_motor_i;

//debe estar al principio del main para inicializar los pines a utilizar por los motores
void setup_motor ()
{
    pinMode(pin_PWM_D , OUTPUT); //inicializo el pin para la señal PWM
    pinMode(pin_PWM_I , OUTPUT);

    pinMode(pin_Motor_D1 , OUTPUT); //inicializo el pin para el motor derecho
    pinMode(pin_Motor_D2 , OUTPUT); 

    pinMode(pin_Motor_I1 , OUTPUT); //inicializo el pin para el motor izquierdo
    pinMode(pin_Motor_I2 , OUTPUT);

    estado_motor_d = APAGADO;
    estado_motor_i = APAGADO;
}


void motor_d (uint8_t potencia, uint8_t estado)
{
    if (estado_motor_d != estado) {
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, LOW);
    }
    estado_motor_d = estado;
    if(potencia > 255)      //verificacion de valor maximo
    {
        potencia=255; 
    }

    //configuro la velocidad 
    analogWrite(pin_PWM_D, potencia);  // potencia entre 0 (0%) y 255 (100%)

    //configuro la direccion
    switch (estado)
    {
    case APAGADO :
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, LOW);
        break;
    case ADELANTE :
        digitalWrite(pin_Motor_D1, HIGH);
        digitalWrite(pin_Motor_D2, LOW);
        break;
    case REVERSA :
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, HIGH);
        break;
    default:
        //si llega un valor no válido, apagar motor
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, LOW);     
        break;
    }
}


void motor_i (uint8_t potencia, uint8_t estado)
{
    if (estado_motor_i != estado) {
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, LOW);
    }
    estado_motor_i = estado;
    if(potencia > 255)      //verificacion de valor maximo
    {
        potencia=255; 
    }    

    //configuro la velocidad
    analogWrite(pin_PWM_I, potencia);  // potencia entre 0 (0%) y 255 (100%)

    //configuro la direccion
    switch (estado)
    {
    case APAGADO :
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, LOW);
        break;
    case ADELANTE :
        digitalWrite(pin_Motor_I1, HIGH);
        digitalWrite(pin_Motor_I2, LOW);
        break;
    case REVERSA :
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, HIGH);
        break;
    default:
        //si llega un valor no válido, apagar motor
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, LOW);     
        break;
    }    
}


void motores (uint8_t potencia, uint8_t estado)
{
    if (estado_motor_d != estado) {
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, LOW);
    }
    if (estado_motor_i != estado) {
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, LOW);
    }
    estado_motor_d = estado;
    estado_motor_i = estado;

    if(potencia > 255)      //verificacion de valor maximo
    {
        potencia=255; 
    }

    //configuro la velocidad
    analogWrite(pin_PWM_D, potencia);  // potencia entre 0 (0%) y 255 (100%)
    analogWrite(pin_PWM_I, potencia);  

    //configuro la direccion
    switch (estado)
    {
    case APAGADO :
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, LOW);
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, LOW);
        break;
    case ADELANTE :
        digitalWrite(pin_Motor_D1, HIGH);
        digitalWrite(pin_Motor_D2, LOW);
        digitalWrite(pin_Motor_I1, HIGH);
        digitalWrite(pin_Motor_I2, LOW);
        break;
    case REVERSA :
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, HIGH);    
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, HIGH);
        break;
    default:
        //si llega un valor no válido, apagar motor
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, LOW);
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, LOW);     
        break;
    }  
}

