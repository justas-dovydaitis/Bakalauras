#include "RestingBikeStrategy.h"

void RestingBikeStrategy::LockBike() 
{
    xTaskCreate(TaskBlinkAndBeep, "BlinkAndBeeb", 128, NULL, 1, NULL);
}
void RestingBikeStrategy::UnlockBike() 
{
    return;
}
void RestingBikeStrategy::TurnIgnitionOn() 
{
    xTaskCreate(TaskIgnition, "Ignition", 128, NULL, 1, NULL);
}

