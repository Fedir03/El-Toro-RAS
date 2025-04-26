#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

typedef struct {
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
} accelerometerData;

accelerometerData getAccelerometerData();

#endif