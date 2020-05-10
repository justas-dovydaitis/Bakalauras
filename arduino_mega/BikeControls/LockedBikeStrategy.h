#ifndef LOCKED_BIKE_STRATEGY_H
#define LOCKED_BIKE_STRATEGY_H

#include "BikeStrategy.h"

class LockedBikeStrategy : public BikeStrategy
{
public:
    void LockBike() override;
    void UnlockBike() override;
    void TurnOnStarter() override;
    void TurnOffStarter() override;
    void TurnOffBike() override;
    void TurnOnHeadlight() override;
    void TurnOffHeadlight() override;
    void TurnOnHighBeam() override;
    void TurnOffHighBeam() override;
    void TurnOnMarkers() override;
    void TurnOffMarkers() override;
    void TurnOnHorn() override;
    void TurnOffHorn() override;
    void TurnOnBrakes() override;
    void TurnOffBrakes() override;
    void TurnOnHazard() override;
    void TurnOffHazard() override;
    void TurnOnLeftTurn() override;
    void TurnOnRightTurn() override;
    void TurnOffTurns() override;

private:
    void alarm();
};

#endif