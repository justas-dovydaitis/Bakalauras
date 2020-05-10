
void handleBTControls(int command)
{
    // Serial.println("Handler has " + String(command));

    switch (command)
    {
    case IGNITION:

        break;
    case IGNITION_OFF:
        controls->TurnOffBike();
        break;
    case STARTER:
        controls->TurnOnStarter();
        break;
    case STARTER_OFF:
        controls->TurnOffStarter();
        break;
    case LEFT_TURN:
        controls->TurnOnLeftTurn();
        break;
    case RIGHT_TURN:
        controls->TurnOnRightTurn();
        break;
    case HAZARD:
        controls->TurnOnHazard();
        break;
    case TURNS_OFF:
        controls->TurnOffTurns();
        break;
    case HEADLIGHT:
        controls->TurnOnHeadlight();
        break;
    case HEADLIGHT_OFF:
        controls->TurnOffHeadlight();
        break;
    case HIGH_BEAM:
        controls->TurnOnHighBeam();
        break;
    case HIGH_BEAM_OFF:
        controls->TurnOffHighBeam();
        break;
    case MARKERS:
        controls->TurnOnMarkers();
        break;
    case MARKERS_OFF:
        controls->TurnOffMarkers();
        break;
    case HORN:
        controls->TurnOnHorn();
        break;
    case HORN_OFF:
        controls->TurnOffHorn();
        break;
    }
};