#include "./Command.h"
String res;
void sendShutOff(void *pvParams)
{
    arduinoSerial.println(IGNITION_OFF);
    while (!arduinoSerial.available())
        ;
    res += arduinoSerial.read();
    if (res != "OK")
        xTaskCreate(sendShutOff, "retrying to shut off", 1024, NULL, 3, NULL);

    vTaskDelete(NULL);
}
