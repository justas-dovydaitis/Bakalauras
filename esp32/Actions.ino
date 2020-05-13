#include "./Command.h"

void sendShutOff()
{
    arduinoSerial.println(IGNITION_OFF);
}
