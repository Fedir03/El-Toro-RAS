#include <stdint.h>
#include "motor.h"
#include "pins.h"
#include <Arduino.h>

//debe estar al principio del main para inicializar los pines a utilizar por los motores
void setup_motor ()
{
    pinMode(pin_PWM_D , OUTPUT); //inicializo el pin para la señal PWM
    pinMode(pin_PWM_I , OUTPUT);

    pinMode(pin_Motor_D1 , OUTPUT); //inicializo el pin para el motor derecho
    pinMode(pin_Motor_D2 , OUTPUT); 

    pinMode(pin_Motor_I1 , OUTPUT); //inicializo el pin para el motor izquierdo
    pinMode(pin_Motor_I2 , OUTPUT); 
}


void motor_d (uint8_t dutyCycle, uint8_t estado)
{
    //configuro la velocidad (deberiamos chequear la frecuencia del pin)
    analogWrite(pin_PWM_D, dutyCycle);  // dutyCycle entre 0 (0%) y 255 (100%)

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
    //configuro la velocidad
    analogWrite(pin_PWM_I, dutyCycle);  // dutyCycle entre 0 (0%) y 255 (100%)

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
    //configuro la velocidad
    analogWrite(pin_PWM_D, dutyCycle);  // dutyCycle entre 0 (0%) y 255 (100%)
    analogWrite(pin_PWM_I, dutyCycle);  

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