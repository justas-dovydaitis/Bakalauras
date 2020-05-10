#include "RunningBikeStrategy.h"

void RunningBikeStrategy::TurnOnStarter() override
{
    xTaskCreate(TaskStarter, "Starter", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOffStarter() override
{
    xTaskCreate(TaskStarterOff, "Starter off", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnIgnitionOff() override
{
    xTaskCreate(TaskIgnitionOff, "Ignition off", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOnHeadlight() override
{
    xTaskCreate(TaskHeadlight, "Headlight", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOffHeadlight() override
{
    xTaskCreate(TaskHeadlightOff, "Headlight off", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOnHighBeam() override
{
    xTaskCreate(TaskHighBeam, "High Beam", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOffHighBeam() override
{
    xTaskCreate(TaskHighBeamOff, "High Beam off", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOnMarkers() override
{
    xTaskCreate(TaskMarkers, "Markers", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOffMarkers() override
{
    xTaskCreate(TaskMarkersOff, "Markers off", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOnHorn() override
{
    xTaskCreate(TaskHorn, "Horn", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOffHorn() override
{
    xTaskCreate(TaskHornOff, "Horn off", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOnBrakes() override
{
    xTaskCreate(TaskBrakes, "Brakes", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOffBrakes() override
{
    xTaskCreate(TaskBrakesOff, "Brakes off", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOnHazard() override
{
    xTaskCreate(TaskHazard, "Hazard", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOnLeftTurn() override
{
    xTaskCreate(TaskLTurn, "L turn", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOnRightTurn() override
{
    xTaskCreate(TaskRTurn, "R turn", 128, NULL, 1, NULL);
}
void RunningBikeStrategy::TurnOffTurns() override
{
    xTaskCreate(TaskTurnsOff, "Turns off", 128, NULL, 1, NULL);
}
