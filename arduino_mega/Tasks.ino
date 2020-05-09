void TaskIgnition(void *pvParameters)
{
    Serial.println("TAsk ignition");
    while (1)
    {
        Serial.println("TAsk ignition loop");
        digitalWrite(GPIO_OUT_IGNITION, RELAY_OPEN);
        vTaskDelay(200 / portTICK_PERIOD_MS);

        digitalWrite(GPIO_OUT_IGNITION, RELAY_CLOSED);
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}
void TaskIgnitionOff(void *pvParameters)
{
    digitalWrite(GPIO_OUT_IGNITION, RELAY_CLOSED);
}
void TaskStarter(void *pvParameters)
{
    digitalWrite(GPIO_OUT_STARTER, RELAY_OPEN);
}
void TaskStarterOff(void *pvParameters)
{
    digitalWrite(GPIO_OUT_STARTER, RELAY_CLOSED);
}
void TaskLTurn(void *pvParameters)
{
}
void TaskRTurn(void *pvParameters)
{
}
void TaskHazard(void *pvParameters)
{
}
void TaskTurnsOff(void *pvParameters)
{
}
void TaskHeadlight(void *pvParameters)
{
}
void TaskHeadlightOff(void *pvParameters)
{
}
void TaskHighBeam(void *pvParameters)
{
}
void TaskHighBeamOff(void *pvParameters)
{
}
void TaskMarkers(void *pvParameters)
{
}
void TaskMarkersOff(void *pvParameters)
{
}
void TaskHorn(void *pvParameters)
{
}
void TaskHornOff(void *pvParameters)
{
}
void TaskBlinkAndBeep(void *pvParameters)
{
    digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_OPEN);
    digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_OPEN);
    digitalWrite(GPIO_OUT_HORN, RELAY_OPEN);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(GPIO_OUT_HORN, RELAY_CLOSED);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_CLOSED);

    vTaskDelete(NULL);
}
void TaskSignalisation(void *pvParameters)
{
    digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_OPEN);
    digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_OPEN);
    digitalWrite(GPIO_OUT_HEADLIGHT, RELAY_OPEN);
    digitalWrite(GPIO_OUT_MARKER, RELAY_OPEN);
    digitalWrite(GPIO_OUT_HORN, RELAY_OPEN);

    vTaskDelay(400 / portTICK_PERIOD_MS);
    
    digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_HEADLIGHT, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_MARKER, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_HORN, RELAY_CLOSED);

    vTaskDelete(NULL);
}