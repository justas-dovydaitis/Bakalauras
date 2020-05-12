
#include <HardwareSerial.h>

#include <string.h>

HardwareSerial hSerial(1);

String valor;
// BaseType_t gyroscopeServiceTask;

void setupGyroscope();
void checkGyroscope();
void setupBT();

void setup()
{
  Serial.begin(115200);
  hSerial.begin(115200, SERIAL_8N1, 16, 17);
  Serial.println("Starting BLE work!");

  setupBT();
  // setupGyroscope();
}

int intervalMilis = 500;

void loop()
{
  // checkGyroscope();
  // put your main code here, to run repeatedly:
}
