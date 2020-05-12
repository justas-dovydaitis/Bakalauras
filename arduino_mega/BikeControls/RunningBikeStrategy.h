#ifndef RUNNING_BIKE_STRATEGY_H
#define RUNNING_BIKE_STRATEGY_H

#include <Arduino_FreeRTOS.h>
#include "Tasks.h"
#include "BikeStrategy.h"
#include "LockedBikeStrategy.h"

class RunningBikeStrategy : public BikeStrategy
{
public:
    void TurnOnIgnition() const override
    {
        Serial.println("asd");
        xTaskCreate(TaskIgnition, "ignition", 1024, NULL, 2, NULL);
    }
    void LockBike() const override
    {
        BIKE_CONTROLS->setStrategy(new LockedBikeStrategy);
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
};
#endif