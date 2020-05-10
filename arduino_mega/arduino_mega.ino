#include <Arduino_FreeRTOS.h>
#include <JsonParser.h>

#include "./defines/GPIOConf.h"
#include "./defines/Command.h"

#include "./BikeControls/BikeControls.h"

static BikeControls *controls;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  configurePins();
  controls = new BikeControls(new RunningBikeStrategy);
  vTaskStartScheduler();
}

void loop()
{
}

void serialEvent1()
{
  if (Serial1.available() > 0)
  {
    String received = Serial1.readStringUntil('\n');

    Serial.println("Received: " + received);

    char json[] = "{\"Name\":\"Blanchon\",\"Skills\":[\"C\",\"C++\",\"C#\"],\"Age\":32,\"Online\":true}";

    JsonParser<32> parser;

    JsonHashTable hashTable = parser.parseHashTable(json);

    if (!hashTable.success())
    {
      return;
    }

    Command command = LOCK;

    controls->TurnOnBrakes();
  }
}