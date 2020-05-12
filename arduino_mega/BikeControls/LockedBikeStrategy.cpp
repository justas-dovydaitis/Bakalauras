#include "LockedBikeStrategy.h"

void LockedBikeStrategy::LockBike() 
{
    // Bike is already locked;
    return
}
void LockedBikeStrategy::UnlockBike() 
{
    xTaskCreate(TaskBlinkAndBeep, "BlinkAndBeeb", 128, NULL, 2, NULL);
}
void LockedBikeStrategy::TurnOnStarter() 
{
    alarm();
}
void LockedBikeStrategy::TurnOffStarter() 
{
    alarm();
}
void LockedBikeStrategy::TurnOffBike() 
{
    alarm();
}
void LockedBikeStrategy::TurnOnIgnition(){
    alarm();
}
void LockedBikeStrategy::TurnOnHeadlight() 
{
    alarm();
}
void LockedBikeStrategy::TurnOffHeadlight() 
{
    alarm();
}
void LockedBikeStrategy::TurnOnHighBeam() 
{
    alarm();
}
void LockedBikeStrategy::TurnOffHighBeam() 
{
    alarm();
}
void LockedBikeStrategy::TurnOnMarkers() 
{
    alarm();
}
void LockedBikeStrategy::TurnOffMarkers() 
{
    alarm();
}
void LockedBikeStrategy::TurnOnHorn() 
{
    alarm();
}
void LockedBikeStrategy::TurnOffHorn() 
{
    alarm();
}
void LockedBikeStrategy::TurnOnBrakes() 
{
    alarm();
}
void LockedBikeStrategy::TurnOffBrakes() 
{
    alarm();
}
void LockedBikeStrategy::TurnOnHazard() 
{
    alarm();
}
void LockedBikeStrategy::TurnOffHazard() 
{
    alarm();
}
void LockedBikeStrategy::TurnOnLeftTurn() 
{
    alarm();
}
void LockedBikeStrategy::TurnOnRightTurn() 
{
    alarm();
}
void LockedBikeStrategy::TurnOffTurns() 
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