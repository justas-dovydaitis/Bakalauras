// Moto physical controls
// **

void configurePins()
{
    configureRelayPins();
}

void configureRelayPins()
{
    pinMode(GPIO_OUT_IGNITION, OUTPUT);
    pinMode(GPIO_OUT_STARTER, OUTPUT);
    pinMode(GPIO_OUT_MARKER, OUTPUT);
    pinMode(GPIO_OUT_HEADLIGHT, OUTPUT);
    pinMode(GPIO_OUT_BRAKELIGHT, OUTPUT);
    pinMode(GPIO_OUT_LEFT_TURN, OUTPUT);
    pinMode(GPIO_OUT_RIGHT_TURN, OUTPUT);
    pinMode(GPIO_OUT_HORN, OUTPUT);
    pinMode(GPIO_OUT_HIGH_BEAM, OUTPUT);

    digitalWrite(GPIO_OUT_IGNITION, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_STARTER, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_MARKER, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_HEADLIGHT, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_BRAKELIGHT, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_HORN, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_HIGH_BEAM, RELAY_CLOSED);
}