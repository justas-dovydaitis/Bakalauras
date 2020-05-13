
#include <Arduino_FreeRTOS.h>
// #include <JsonParser.h>
#include <TinyGPS++.h>

#include "./defines/GPIOConf.h"
#include "./defines/Command.h"

#include "./BikeControls/Tasks.h"
#include "./BikeControls/BikeControls.h"
#include "./BikeControls/LockedBikeStrategy.h"
#include "./BikeControls/RestingBikeStrategy.h"
#include "./BikeControls/RunningBikeStrategy.h"

/**
 * VARIABLES
 */
BikeControls *BIKE_CONTROLS;
float lat, lon;
TinyGPSPlus gps; // create gps object

/**
 * FUNCTIONS
 */
// GSM
int sendSMS(String message);
int makeCall();
void setupGSM();
void updateGSM();
// GPS
void gpsSetup()
{
  Serial.println("The GPS Received Signal:");
  Serial2.begin(115200); // connect gps sensor
}

void gpsLoop()
{
  while (Serial2.available())
  {                             // check for gps data
    gps.encode(Serial2.read()); // encode gps data

    if (gps.location.isUpdated())
    {
      // gps.f_get_position(&lat, &lon); // get latitude and longitude

      Serial.print("Position: ");

      //Latitude
      Serial.print("Latitude: ");
      Serial.print(lat, 6);

      Serial.print(",");

      //Longitude
      Serial.print("Longitude: ");
      Serial.println(lon, 6);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  configurePins();
  Serial.println("asdasdasdasd");
  setupGSM();
  // gpsSetup();

  BIKE_CONTROLS = new BikeControls(new RunningBikeStrategy);
}

void loop()
{
}
void serialEvent()
{
  sendSMS("bbd");
  makeCall();
}
void serialEvent1()
{
  String x = Serial1.readStringUntil("\n");
  Serial.println("serialEvent1 - " + x);
  Command command = (Command)x.toInt();

  handleBTControls(command);
  // controls->TurnOnBrakes();
}