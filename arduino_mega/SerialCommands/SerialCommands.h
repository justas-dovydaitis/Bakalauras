#ifndef SERIAL_COMMANDER_H
#define SERIAL_COMMANDER_H

class SerialCommander
{
private:
    SerialCommander() {}

public:
    void SendToEsp(message);
}

#endif