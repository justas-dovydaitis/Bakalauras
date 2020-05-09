
void handleBTControls(int command)
{
    Serial.println("Handler has " + String(command));

    switch (command)
    {
    case 0:
        Serial.println("ON IGNITION");
        xTaskCreate(TaskIgnition, "Ignition", 128, NULL, 1, NULL);
        break;
    case IGNITION_OFF:
        xTaskCreate(TaskIgnitionOff, "Ignition off", 128, NULL, 1, NULL);
        break;
    case STARTER:
        xTaskCreate(TaskStarter, "Starter", 128, NULL, 1, NULL);
        break;
    case STARTER_OFF:
        xTaskCreate(TaskStarterOff, "Starter off", 128, NULL, 1, NULL);
        break;
    case LEFT_TURN:
        xTaskCreate(TaskLTurn, "LTurn", 128, NULL, 1, NULL);
        break;
    case RIGHT_TURN:
        xTaskCreate(TaskRTurn, "RTurn", 128, NULL, 1, NULL);
        break;
    case HAZARD:
        xTaskCreate(TaskHazard, "Hazzard", 128, NULL, 1, NULL);
        break;
    case TURNS_OFF:
        xTaskCreate(TaskTurnsOff, "Turns off", 128, NULL, 1, NULL);
        break;
    case HEADLIGHT:
        xTaskCreate(TaskHeadlight, "Headlight", 128, NULL, 1, NULL);
        break;
    case HEADLIGHT_OFF:
        xTaskCreate(TaskHeadlightOff, "Headlight off", 128, NULL, 1, NULL);
        break;
    case HIGH_BEAM:
        xTaskCreate(TaskHighBeam, "High beam", 128, NULL, 1, NULL);
        break;
    case HIGH_BEAM_OFF:
        xTaskCreate(TaskHighBeamOff, "High beam off", 128, NULL, 1, NULL);
        break;
    case MARKERS:
        xTaskCreate(TaskMarkers, "Markers", 128, NULL, 1, NULL);
        break;
    case MARKERS_OFF:
        xTaskCreate(TaskMarkersOff, "Markers off", 128, NULL, 1, NULL);
        break;
    case HORN:
        xTaskCreate(TaskHorn, "Horn", 128, NULL, 1, NULL);
        break;
    case HORN_OFF:
        xTaskCreate(TaskHornOff, "Horn off", 128, NULL, 1, NULL);
        break;
    }
};