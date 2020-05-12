#ifndef TASKS_H
#define TASKS_H

bool extern lTurnStatus = false;
bool extern rTurnStatus = false;
bool extern hazzardStatus = false;

void TaskIgnition(void *pvParameters)
{
    digitalWrite(GPIO_OUT_IGNITION, RELAY_OPEN);
    vTaskDelete(NULL);
}
void TaskIgnitionOff(void *pvParameters)
{
    digitalWrite(GPIO_OUT_IGNITION, RELAY_CLOSED);
    vTaskDelete(NULL);
}
void TaskStarter(void *pvParameters)
{
    digitalWrite(GPIO_OUT_STARTER, RELAY_OPEN);
    vTaskDelete(NULL);
}
void TaskStarterOff(void *pvParameters)
{
    digitalWrite(GPIO_OUT_STARTER, RELAY_CLOSED);
    vTaskDelete(NULL);
}
void TaskLTurn(void *pvParameters)
{
    rTurnStatus = false;
    lTurnStatus = true;
    hazzardStatus = false;
    while (lTurnStatus)
    {
        digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_OPEN);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_CLOSED);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}
void TaskRTurn(void *pvParameters)
{
    lTurnStatus = false;
    rTurnStatus = true;
    hazzardStatus = false;
    while (rTurnStatus)
    {
        digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_OPEN);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_CLOSED);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}
void TaskHazard(void *pvParameters)
{
    rTurnStatus = false;
    lTurnStatus = false;
    hazzardStatus = true;
    while (hazzardStatus)
    {
        digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_OPEN);
        digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_OPEN);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_CLOSED);
        digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_CLOSED);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}
void TaskTurnsOff(void *pvParameters)
{
    lTurnStatus = false;
    rTurnStatus = false;
    hazzardStatus = false;
    vTaskDelete(NULL);
}
void TaskHeadlight(void *pvParameters)
{
    vTaskDelete(NULL);
}
void TaskHeadlightOff(void *pvParameters)
{
    vTaskDelete(NULL);
}
void TaskHighBeam(void *pvParameters)
{
    vTaskDelete(NULL);
}
void TaskHighBeamOff(void *pvParameters)
{
    vTaskDelete(NULL);
}
void TaskMarkers(void *pvParameters)
{
    vTaskDelete(NULL);
}
void TaskMarkersOff(void *pvParameters)
{
    vTaskDelete(NULL);
}
void TaskBrakes(void *pvParameters)
{
    vTaskDelete(NULL);
}
void TaskBrakesOff(void *pvParameters)
{
    vTaskDelete(NULL);
}
void TaskHorn(void *pvParameters)
{
    vTaskDelete(NULL);
}
void TaskHornOff(void *pvParameters)
{
    vTaskDelete(NULL);
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
#endif
