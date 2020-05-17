#include <Arduino.h>
#include <TinyMPU6050.h>
#include <Wire.h>

#define MAX_SAFE_LEAN_ANGLE 55   // Degrees
#define GYRO_CHECK_INTERVAL 100.0  // MS
#define MAX_NORMAL_LEAN_SPEED 70.0 // Degrees per second

#define MAX_NORMAL_LEAN_SPEED_PER_CHECK MAX_NORMAL_LEAN_SPEED / GYRO_CHECK_INTERVAL

MPU6050 mpu6050(Wire);

void setupGyroscope()
{
  Wire.begin(21, 22);
  mpu6050.Initialize();
  mpu6050.Calibrate();
}

int lastCheckTimeStamp = 0;
float lastCheckXAngle = NULL;
float lastCheckYAngle = NULL;
float xAngle = NULL;
float yAngle = NULL;

void checkGyroscope()
{

  int currentMillis = millis();

  if ((currentMillis - lastCheckTimeStamp) > GYRO_CHECK_INTERVAL)
  {
    mpu6050.Execute();
    xAngle = mpu6050.GetAngAccX();
    yAngle = mpu6050.GetAngAccY();

    Serial.print(String(xAngle));
    Serial.print("\t" + String(yAngle)+"\t"+MAX_NORMAL_LEAN_SPEED_PER_CHECK);
    if (lastCheckYAngle && abs(lastCheckYAngle - yAngle) > MAX_NORMAL_LEAN_SPEED_PER_CHECK)
    {
      arduinoSerial.print(IGNITION_OFF);
      Serial.println("BOOM too fast");
    }
    else if (abs(yAngle) > MAX_SAFE_LEAN_ANGLE ||
             abs(xAngle) > MAX_SAFE_LEAN_ANGLE)
    {
      Serial.println("BOOM too far");
    }
    Serial.println("");
    lastCheckXAngle = xAngle;
    lastCheckYAngle = yAngle;
  }

}
