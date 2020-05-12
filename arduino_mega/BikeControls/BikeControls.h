#ifndef BIKE_CONTROLLS_H
#define BIKE_CONTROLLS_H

#include "BikeStrategy.h"

// #include "LockedBikeStrategy.h"
// #include "RestingBikeStrategy.h"
// #include "RunningBikeStrategy.h"

class BikeControls
{
private:
    BikeStrategy *strategy_;

public:
    BikeControls(BikeStrategy *strategy = nullptr) : strategy_(strategy){};
    ~BikeControls()
    {
        delete this->strategy_;
    }
    void setStrategy(BikeStrategy *strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }

    void TurnOnIgnition()
    {
        // Serial.println("WTF");
        this->strategy_->TurnOnIgnition();
    }
    void LockBike()
    {
        this->strategy_->LockBike();
    }
    void UnlockBike()
    {
        this->strategy_->UnlockBike();
    }
    void TurnOnStarter()
    {
        this->strategy_->TurnOnStarter();
    }
    void TurnOffStarter()
    {
        this->strategy_->TurnOffStarter();
    }
    void TurnOffBike()
    {
        this->strategy_->TurnOffBike();
    }
    void TurnOnHeadlight()
    {
        this->strategy_->TurnOnHeadlight();
    }
    void TurnOffHeadlight()
    {
        this->strategy_->TurnOffHeadlight();
    }
    void TurnOnHighBeam()
    {
        this->strategy_->TurnOnHighBeam();
    }
    void TurnOffHighBeam()
    {
        this->strategy_->TurnOffHighBeam();
    }
    void TurnOnMarkers()
    {
        this->strategy_->TurnOnMarkers();
    }
    void TurnOffMarkers()
    {
        this->strategy_->TurnOffMarkers();
    }
    void TurnOnHorn()
    {
        this->strategy_->TurnOnHorn();
    }
    void TurnOffHorn()
    {
        this->strategy_->TurnOffHorn();
    }
    void TurnOnBrakes()
    {
        this->strategy_->TurnOnBrakes();
    }
    void TurnOffBrakes()
    {
        this->strategy_->TurnOffBrakes();
    }
    void TurnOnHazard()
    {
        this->strategy_->TurnOnHazard();
    }
    void TurnOffHazard()
    {
        this->strategy_->TurnOffHazard();
    }
    void TurnOnLeftTurn()
    {
        this->strategy_->TurnOnLeftTurn();
    }
    void TurnOnRightTurn()
    {
        this->strategy_->TurnOnRightTurn();
    }
    void TurnOffTurns()
    {
        this->strategy_->TurnOffTurns();
    }
};
extern const BikeControls *BIKE_CONTROLS;
#endif