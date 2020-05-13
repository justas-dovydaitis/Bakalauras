// #include <SoftwareSerial1a.h>
#include <HardwareSerial.h>
//Create software Serial1a object to communicate with SIM800L
// SoftwareSerial1a mySerial1a(3, 1); //SIM800L Tx & Rx is connected to Arduino #3 & #2
HardwareSerial Serial1a(0);
void setup()
{
    //Begin Serial1a communication with Arduino and Arduino IDE (Serial1a Monitor)
    Serial1a.begin(9600);

    //Begin Serial1a communication with Arduino and SIM800L
    // mySerial1a.begin(9600);

    Serial1a.println("Initializing...");
    delay(1000);

    Serial1a.println("AT"); //Once the handshake test is successful, it will back to OK
    updateSerial1a();
    Serial1a.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
    updateSerial1a();
    Serial1a.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
    updateSerial1a();
    Serial1a.println("AT+CREG?"); //Check whether it has registered in the network
    updateSerial1a();
    Serial1a.println("ATD+ +37060545482;");
    delay(20000);          // wait for 20 seconds...
    Serial1a.println("ATH"); //hang up
    updateSerial1a();
}

void loop()
{
    updateSerial1a();
}

void updateSerial1a()
{
    delay(500);
    while (Serial1a.available())
    {
        Serial1a.read(); //Forward what Serial1a received to Software Serial1a Port
    }
    //   while(mySerial1a.available())
    //   {
    //     Serial1a.write(mySerial1a.read());//Forward what Software Serial1a received to Serial1a Port
    //   }
}