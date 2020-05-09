#include <Arduino_FreeRTOS.h>
#include "./defines/GPIOConf.h"
#include "./defines/BTCommand.h"

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  configurePins();

  vTaskStartScheduler();
}

void loop()
{
  if (Serial1.available())
  {
    String command = Serial1.readStringUntil('\n');
    Serial1.writeln("GOOD SHit");
    Serial.println("BT Sent " + command);
    handleBTControls(command);
  }
}
