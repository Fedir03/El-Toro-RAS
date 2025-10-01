#ifndef GLOBALS_H
#define GLOBALS_H

extern volatile bool readAccelerometerFlag;
extern volatile bool readInfraFlag;

typedef struct {
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
} accelerometerData_t;

typedef struct 
{
  bool infraData_D;
  bool infraData_I;
  bool infraData_A;
} infraData_t;

typedef struct {
  accelerometerData_t accData;
  infraData_t infraData;
  long int d;        // distancia central (para compatibilidad)
  long int d_d;      // distancia sensor derecho
  long int d_i;      // distancia sensor izquierdo
  short estado_motor_d;
  short estado_motor_i;
} elToroData_t;

#endif