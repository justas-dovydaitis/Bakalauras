/*
 * SIM800L SMS RELAY v1.0
 * Arduino Hardware (Author): Nano V3 (ATmega328)
 * Arduino IDE (Author): 1.6.9
 * T.K.Hareendran/2018
 */
#include <HardwareSerial.h>
// #include <SoftwareSerial.h>
// #include <TinyGsmClient.h>
//      Serial2(16,17);  // (Rx,Tx  > Tx,Rx)



void setup()
{
    //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
    Serial.begin(9600);

    //Begin serial communication with Arduino and SIM800L
    Serial2.begin(9600);

    Serial.println("Initializing...");
    delay(1000);

    Serial2.println("AT"); //Once the handshake test is successful, i t will back to OK
    updateSerial();

    Serial2.println("AT+COPS"); //Once the handshake test is successful, i t will back to OK
    updateSerial();

    Serial2.println("ATD+37060513161;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
    updateSerial();
    delay(20000);           // wait for 20 seconds...
    Serial2.println("ATH"); //hang up
    updateSerial();
}

void loop()
{
}

void updateSerial()
{
    delay(500);
    while (Serial.available())
    {
        Serial2.write(Serial.read()); //Forward what Serial received to Software Serial Port
    }
    while (Serial2.available())
    {
        Serial.write(Serial2.read()); //Forward what Software Serial received to Serial Port
    }
}