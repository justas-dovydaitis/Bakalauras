#ifndef BIKE_CONTROLLS_H
#define BIKE_CONTROLLS_H

#include "BikeStrategy.h"

#include "LockedBikeStrategy.h"
#include "RestingBikeStrategy.h"
#include "RunningBikeStrategy.h"

class BikeControls
{
private:
    BikeStrategy *strategy_;

public:
    BikeControls(BikeStrategy *strategy = nullptr) : strategy_(strategy){};
    ~BikeControls();
    void setStrategy(BikeStrategy *strategy);
    void LockBike() const;
    void UnlockBike() const;
    void TurnOnStarter() const;
    void TurnOffStarter() const;
    void TurnOffBike() const;
    void TurnOnHeadlight() const;
    void TurnOffHeadlight() const;
    void TurnOnHighBeam() const;
    void TurnOffHighBeam() const;
    void TurnOnMarkers() const;
    void TurnOffMarkers() const;
    void TurnOnHorn() const;
    void TurnOffHorn() const;
    void TurnOnBrakes();
    void TurnOffBrakes() const;
    void TurnOnHazard() const;
    void TurnOffHazard() const;
    void TurnOnLeftTurn() const;
    void TurnOnRightTurn() const;
    void TurnOffTurns() const;
};

#endif