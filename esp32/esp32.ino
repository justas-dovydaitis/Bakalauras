
#include <HardwareSerial.h>
#include "./Command.h"

#include <string.h>

HardwareSerial arduinoSerial(2);

BaseType_t gyroscopeServiceTask;

void setupGyroscope();
void checkGyroscope();
void gyroscopeService();

void setupBT();

void setup()
{
  Serial.begin(115200);
  arduinoSerial.begin(115200, SERIAL_8N1, 16, 17);
  Serial.println("Starting BLE work!");

  setupBT();
  setupGyroscope();


  // gyroscopeServiceTask = TaskCreate(gyroscopeService, "Gyro", 2048, NULL, 3, NULL);
}

int intervalMilis = 500;

void loop()
{
  checkGyroscope();
 
  // put your main code here, to run repeatedly:
}
