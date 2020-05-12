#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setupGyroscope()
{
  Wire.begin(21, 22);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void gyroscopeService(void *pvParams)
{

  mpu6050.update();
  Serial.print("gyroAngleX : ");
  Serial.print(mpu6050.getGyroAngleX());
  Serial.print("\tgyroAngleY : ");
  Serial.print(mpu6050.getGyroAngleY());
  Serial.print("\tgyroAngleZ : ");
  Serial.println(mpu6050.getGyroAngleZ());

  // Serial.print("angleX : ");
  // Serial.print(mpu6050.getAngleX());
  // Serial.print("\tangleY : ");
  // Serial.print(mpu6050.getAngleY());
  // Serial.print("\tangleZ : ");
  // Serial.println(mpu6050.getAngleZ());
  Serial.println("=======================================================\n");

  vTaskDelete(NULL);
}
int gyroCheckInterval = 500;
int lastCheck = 0;
void checkGyroscope()
{
  int currentMillis = millis();
  // Serial.println(currentMillis - lastCheck);
  if (currentMillis - lastCheck > gyroCheckInterval)
  {
    xTaskCreate(gyroscopeService, "Gyro", 2048, NULL, 3, NULL);
    lastCheck = currentMillis;
  }
}