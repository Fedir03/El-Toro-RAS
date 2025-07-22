#include "motor.h"


//debe estar al principio del main para inicializar los pines a utilizar por los motores
void setup_motor (elToroData_t *Toro)
{
    pinMode(pin_PWM_D , OUTPUT); //inicializo el pin para la señal PWM
    pinMode(pin_PWM_I , OUTPUT);

    pinMode(pin_Motor_D1 , OUTPUT); //inicializo el pin para el motor derecho
    pinMode(pin_Motor_D2 , OUTPUT); 

    pinMode(pin_Motor_I1 , OUTPUT); //inicializo el pin para el motor izquierdo
    pinMode(pin_Motor_I2 , OUTPUT);

    Toro->estado_motor_d = APAGADO;
    Toro->estado_motor_i = APAGADO;

    digitalWrite(pin_Motor_D1, LOW);
    digitalWrite(pin_Motor_D2, LOW);
    digitalWrite(pin_Motor_I1, LOW);
    digitalWrite(pin_Motor_I2, LOW);    
}


void motor_d (uint8_t potencia, uint8_t estado, elToroData_t *Toro)
{
    if (Toro->estado_motor_d != estado) {
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, LOW);
    }
    Toro->estado_motor_d = estado;

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


void motor_i (uint8_t potencia, uint8_t estado, elToroData_t *Toro)
{
    if (Toro->estado_motor_i != estado) {
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, LOW);
    }
    Toro->estado_motor_i = estado;

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


void motores (uint8_t potencia, uint8_t estado, elToroData_t *Toro)
{
    if (Toro->estado_motor_d != estado) {
        digitalWrite(pin_Motor_D1, LOW);
        digitalWrite(pin_Motor_D2, LOW);
    }
    if (Toro->estado_motor_i != estado) {
        digitalWrite(pin_Motor_I1, LOW);
        digitalWrite(pin_Motor_I2, LOW);
    }
    Toro->estado_motor_d = estado;
    Toro->estado_motor_i = estado;

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

