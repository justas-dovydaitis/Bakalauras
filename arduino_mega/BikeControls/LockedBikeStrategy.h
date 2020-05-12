#ifndef LOCKED_BIKE_STRATEGY_H
#define LOCKED_BIKE_STRATEGY_H

#include "BikeStrategy.h"

class LockedBikeStrategy : public BikeStrategy
{
public:
    void TurnOnIgnition() const override
    {
        Serial.println("asd");
        xTaskCreate(TaskIgnition, "ignition", 1024, NULL, 2, NULL);
    }
    void LockBike() const override
    {
        controls->setStrategy(new LockedBikeStrategy);
    }
    void UnlockBike() const override
    {
    }
    void TurnOnStarter() const override
    {
        xTaskCreate(TaskStarter, "Starter", 1024, NULL, 1, NULL);
    }
    void TurnOffStarter() const override
    {
        xTaskCreate(TaskStarterOff, "Starter off", 1024, NULL, 2, NULL);
    }
    void TurnOffBike() const override
    {
        xTaskCreate(TaskIgnitionOff, "Ignition off", 1024, NULL, 3, NULL);
    }
    void TurnOnHeadlight() const override
    {
        xTaskCreate(TaskHeadlight, "Headlight", 1024, NULL, 1, NULL);
    }
    void TurnOffHeadlight() const override
    {
        xTaskCreate(TaskHeadlightOff, "Headlight off", 1024, NULL, 1, NULL);
    }
    void TurnOnHighBeam() const override
    {
        xTaskCreate(TaskHighBeam, "High Beam", 1024, NULL, 1, NULL);
    }
    void TurnOffHighBeam() const override
    {
        xTaskCreate(TaskHighBeamOff, "High Beam off", 1024, NULL, 1, NULL);
    }
    void TurnOnMarkers() const override
    {
        xTaskCreate(TaskMarkers, "Markers", 1024, NULL, 1, NULL);
    }
    void TurnOffMarkers() const override
    {
        xTaskCreate(TaskMarkersOff, "Markers off", 1024, NULL, 1, NULL);
    }
    void TurnOnHorn() const override
    {
        xTaskCreate(TaskHorn, "Horn", 1024, NULL, 1, NULL);
    }
    void TurnOffHorn() const override
    {
        xTaskCreate(TaskHornOff, "Horn off", 1024, NULL, 1, NULL);
    }
    void TurnOnBrakes() const override
    {
        xTaskCreate(TaskBrakes, "Brakes", 1024, NULL, 1, NULL);
    }
    void TurnOffBrakes() const override
    {
        xTaskCreate(TaskBrakesOff, "Brakes off", 1024, NULL, 1, NULL);
    }
    void TurnOnHazard() const override
    {
        xTaskCreate(TaskHazard, "Hazard", 1024, NULL, 1, NULL);
    }
    void TurnOffHazard() const override
    {
        xTaskCreate(TaskTurnsOff, "Hazard off", 1024, NULL, 1, NULL);
    }
    void TurnOnLeftTurn() const override
    {
        xTaskCreate(TaskLTurn, "L turn", 1024, NULL, 1, NULL);
    }
    void TurnOnRightTurn() const override
    {
        xTaskCreate(TaskRTurn, "R turn", 1024, NULL, 1, NULL);
    }
    void TurnOffTurns() const override
    {
        xTaskCreate(TaskTurnsOff, "Turns off", 1024, NULL, 1, NULL);
    }

private:
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
};

#endif