#ifndef BIKE_STRATEGY_H
#define BIKE_STRATEGY_H

class BikeStrategy
{
public:
    virtual ~BikeStrategy() {}

    virtual void TurnOnIgnition() const = 0;
    virtual void LockBike() const = 0;
    virtual void UnlockBike() const = 0;
    virtual void TurnOnStarter() const = 0;
    virtual void TurnOffStarter() const = 0;
    virtual void TurnOffBike() const = 0;
    virtual void TurnOnHeadlight() const = 0;
    virtual void TurnOffHeadlight() const = 0;
    virtual void TurnOnHighBeam() const = 0;
    virtual void TurnOffHighBeam() const = 0;
    virtual void TurnOnMarkers() const = 0;
    virtual void TurnOffMarkers() const = 0;
    virtual void TurnOnHorn() const = 0;
    virtual void TurnOffHorn() const = 0;
    virtual void TurnOnBrakes() const = 0;
    virtual void TurnOffBrakes() const = 0;
    virtual void TurnOnHazard() const = 0;
    virtual void TurnOffHazard() const = 0;
    virtual void TurnOnLeftTurn() const = 0;
    virtual void TurnOnRightTurn() const = 0;
    virtual void TurnOffTurns() const = 0;
};

#endif