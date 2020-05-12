#ifndef RESTING_BIKE_STRATEGY_H
#define RESTING_BIKE_STRATEGY_H

#include "BikeStrategy.h"

class RestingBikeStrategy : public BikeStrategy
{
public:
    void TurnOnIgnition();
    void LockBike();
    void UnlockBike();
    void TurnOnStarter();
    void TurnOffStarter();
    void TurnOffBike();
    void TurnOnHeadlight();
    void TurnOffHeadlight();
    void TurnOnHighBeam();
    void TurnOffHighBeam();
    void TurnOnMarkers();
    void TurnOffMarkers();
    void TurnOnHorn();
    void TurnOffHorn();
    void TurnOnBrakes();
    void TurnOffBrakes();
    void TurnOnHazard();
    void TurnOffHazard();
    void TurnOnLeftTurn();
    void TurnOnRightTurn();
    void TurnOffTurns();
};

#endif