#ifndef BIKE_STRATEGY_H
#define BIKE_STRATEGY_H

class BikeStrategy
{
public:
    virtual ~BikeStrategy() {}

    virtual void LockBike() = 0;
    virtual void UnlockBike() = 0;
    virtual void TurnOnStarter() = 0;
    virtual void TurnOffStarter() = 0;
    virtual void TurnOffBike() = 0;
    virtual void TurnOnHeadlight() = 0;
    virtual void TurnOffHeadlight() = 0;
    virtual void TurnOnHighBeam() = 0;
    virtual void TurnOffHighBeam() = 0;
    virtual void TurnOnMarkers() = 0;
    virtual void TurnOffMarkers() = 0;
    virtual void TurnOnHorn() = 0;
    virtual void TurnOffHorn() = 0;
    virtual void TurnOnBrakes() = 0;
    virtual void TurnOffBrakes() = 0;
    virtual void TurnOnHazard() = 0;
    virtual void TurnOffHazard() = 0;
    virtual void TurnOnLeftTurn() = 0;
    virtual void TurnOnRightTurn() = 0;
    virtual void TurnOffTurns() = 0;
};

#endif