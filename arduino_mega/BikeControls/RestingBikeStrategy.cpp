#include "RestingBikeStrategy.h"

void RestingBikeStrategy::LockBike() override
{
    xTaskCreate(TaskBlinkAndBeep, "BlinkAndBeeb", 128, NULL, 1, NULL);
}
void RestingBikeStrategy::UnlockBike() override
{
    return;
}
void RestingBikeStrategy::TurnIgnitionOn() override
{
    xTaskCreate(TaskIgnition, "Ignition", 128, NULL, 1, NULL);
}

