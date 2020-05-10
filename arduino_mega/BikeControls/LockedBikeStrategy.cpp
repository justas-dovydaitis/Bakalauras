#include "LockedBikeStrategy.h"

void LockedBikeStrategy::LockBike() override
{
    // Bike is already locked;
    return
}
void LockedBikeStrategy::UnlockBike() override
{
    xTaskCreate(TaskBlinkAndBeep, "BlinkAndBeeb", 128, NULL, 2, NULL);
}
void LockedBikeStrategy::TurnOnStarter() override
{
    alarm();
}
void LockedBikeStrategy::TurnOffStarter() override
{
    alarm();
}
void LockedBikeStrategy::TurnOffBike() override
{
    alarm();
}
void LockedBikeStrategy::TurnOnHeadlight() override
{
    alarm();
}
void LockedBikeStrategy::TurnOffHeadlight() override
{
    alarm();
}
void LockedBikeStrategy::TurnOnHighBeam() override
{
    alarm();
}
void LockedBikeStrategy::TurnOffHighBeam() override
{
    alarm();
}
void LockedBikeStrategy::TurnOnMarkers() override
{
    alarm();
}
void LockedBikeStrategy::TurnOffMarkers() override
{
    alarm();
}
void LockedBikeStrategy::TurnOnHorn() override
{
    alarm();
}
void LockedBikeStrategy::TurnOffHorn() override
{
    alarm();
}
void LockedBikeStrategy::TurnOnBrakes() override
{
    alarm();
}
void LockedBikeStrategy::TurnOffBrakes() override
{
    alarm();
}
void LockedBikeStrategy::TurnOnHazard() override
{
    alarm();
}
void LockedBikeStrategy::TurnOffHazard() override
{
    alarm();
}
void LockedBikeStrategy::TurnOnLeftTurn() override
{
    alarm();
}
void LockedBikeStrategy::TurnOnRightTurn() override
{
    alarm();
}
void LockedBikeStrategy::TurnOffTurns() override
{
    alarm();
}
void LockedBikeStrategy::alarm()
{
    digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_OPEN);
    digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_OPEN);
    digitalWrite(GPIO_OUT_HEADLIGHT, RELAY_OPEN);
    digitalWrite(GPIO_OUT_MARKER, RELAY_OPEN);
    digitalWrite(GPIO_OUT_HORN, RELAY_OPEN);

    Delay(400 / portTICK_PERIOD_MS);

    digitalWrite(GPIO_OUT_LEFT_TURN, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_RIGHT_TURN, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_HEADLIGHT, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_MARKER, RELAY_CLOSED);
    digitalWrite(GPIO_OUT_HORN, RELAY_CLOSED);
}