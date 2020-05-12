
void handleBTControls(int command)
{
    // Serial.println("Handler has " + String(command));

    switch (command)
    {
    case IGNITION:
        Serial.println("ignition");
        BIKE_CONTROLS->TurnOnIgnition();
        break;
    case IGNITION_OFF:

        BIKE_CONTROLS->TurnOffBike();
        break;
    case STARTER:
        BIKE_CONTROLS->TurnOnStarter();
        break;
    case STARTER_OFF:
        BIKE_CONTROLS->TurnOffStarter();
        break;
    case LEFT_TURN:
        BIKE_CONTROLS->TurnOnLeftTurn();
        break;
    case RIGHT_TURN:
        BIKE_CONTROLS->TurnOnRightTurn();
        break;
    case HAZARD:
        BIKE_CONTROLS->TurnOnHazard();
        break;
    case TURNS_OFF:
        BIKE_CONTROLS->TurnOffTurns();
        break;
    case HEADLIGHT:
        BIKE_CONTROLS->TurnOnHeadlight();
        break;
    case HEADLIGHT_OFF:
        BIKE_CONTROLS->TurnOffHeadlight();
        break;
    case HIGH_BEAM:
        BIKE_CONTROLS->TurnOnHighBeam();
        break;
    case HIGH_BEAM_OFF:
        BIKE_CONTROLS->TurnOffHighBeam();
        break;
    case MARKERS:
        BIKE_CONTROLS->TurnOnMarkers();
        break;
    case MARKERS_OFF:
        BIKE_CONTROLS->TurnOffMarkers();
        break;
    case HORN:
        BIKE_CONTROLS->TurnOnHorn();
        break;
    case HORN_OFF:
        BIKE_CONTROLS->TurnOffHorn();
        break;
    case LOCK:
        BIKE_CONTROLS->LockBike();
    }
};