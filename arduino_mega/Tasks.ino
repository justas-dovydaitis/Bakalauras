void TaskIgnition(void *pvParameters)
{
    digitalWrite(GPIO_OUT_IGNITION, RELAY_OPEN);
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
    digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_OPEN);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_CLOSED);
    vTaskDelay(500 / portTICK_PERIOD_MS);
}
void TaskRTurn(void *pvParameters)
{
    while (1)
    {
        digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_OPEN);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_CLOSED);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
void TaskHazard(void *pvParameters)
{
    digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_OPEN);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_CLOSED);
    vTaskDelay(500 / portTICK_PERIOD_MS);
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
void TaskBrakes(void *pvParameters)
{
}
void TaskBrakesOff(void *pvParameters)
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