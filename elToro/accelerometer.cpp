#include "accelerometer.h"

accelerometerData_t getAccelerometerData() {
  int ax, ay, az;
  int gx, gy, gz;

  accelerometer.getAcceleration(&ax, &ay, &az);
  accelerometer.getRotation(&gx, &gy, &gz);

  accelerometerData_t accData;

  accData.ax = ax * (9.81 / 16384.0);
  accData.ay = ay * (9.81 / 16384.0);
  accData.az = az * (9.81 / 16384.0);
  accData.gx = gx * (250.0 / 32768.0);
  accData.gy = gy * (250.0 / 32768.0);
  accData.gz = gz * (250.0 / 32768.0);

  Serial.print("a[x y z](m/s2) g[x y z](deg/s):\t");
  Serial.print(accData.ax); Serial.print("\t");
  Serial.print(accData.ay); Serial.print("\t");
  Serial.print(accData.az); Serial.print("\t");
  Serial.print(accData.gx); Serial.print("\t");
  Serial.print(accData.gy); Serial.print("\t");
  Serial.println(accData.gz);

  return accData;
}

/*Codigo para medir rotacion en grados:
    accumulatedAngleX += gx_deg_s * deltaTime; // integrar velocidad angular
    Serial.print("Ángulo acumulado X: ");
    Serial.println(accumulatedAngleX);

    if (abs(accumulatedAngleX) >= 90.0) {
      Serial.println("Rotación de 90 grados completada");
      detectingRotation = false;
      digitalWrite(Led, LOW);
    }
*/