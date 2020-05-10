#include "BikeControls.h"

BikeControls::BikeControls(BikeStrategy *strategy = nullptr) : strategy_(strategy)
{
}
BikeControls::~BikeControls()
{
    delete this->strategy_;
}
void BikeControls::setStrategy(BikeStrategy *strategy)
{
    delete this->strategy_;
    this->strategy_ = strategy;
}

void BikeControls::LockBike()
{
    return this->strategy_->LockBike();
}
void BikeControls::UnlockBike()
{
    return this->strategy_->UnlockBike();
}
void BikeControls::TurnOnStarter()
{
    return this->strategy_->TurnOnStarter();
}
void BikeControls::TurnOffStarter()
{
    return this->strategy_->TurnOffStarter();
}
void BikeControls::TurnOffBike()
{
    return this->strategy_->TurnOffBike();
}
void BikeControls::TurnOnHeadlight()
{
    return this->strategy_->TurnOnHeadlight();
}
void BikeControls::TurnOffHeadlight()
{
    return this->strategy_->TurnOffHeadlight();
}
void BikeControls::TurnOnHighBeam()
{
    return this->strategy_->TurnOnHighBeam();
}
void BikeControls::TurnOffHighBeam()
{
    return this->strategy_->TurnOffHighBeam();
}
void BikeControls::TurnOnMarkers()
{
    return this->strategy_->TurnOnMarkers();
}
void BikeControls::TurnOffMarkers()
{
    return this->strategy_->TurnOffMarkers();
}
void BikeControls::TurnOnHorn()
{
    return this->strategy_->TurnOnHorn();
}
void BikeControls::TurnOffHorn()
{
    return this->strategy_->TurnOffHorn();
}
void BikeControls::TurnOnBrakes()
{
    return this->strategy_->TurnOnBrakes();
}
void BikeControls::TurnOffBrakes()
{
    return this->strategy_->TurnOffBrakes();
}
void BikeControls::TurnOnHazard()
{
    return this->strategy_->TurnOnHazard();
}
void BikeControls::TurnOffHazard()
{
    return this->strategy_->TrunOffHazard();
}
void BikeControls::TurnOnLeftTurn()
{
    return this->strategy_->TurnOnLeftTurn();
}
void BikeControls::TurnOnRightTurn()
{
    return this->strategy_->TurnOnRightTurn();
}
void BikeControls::TurnOffTurns()
{
    return this->strategy_->TurnOffTurns();
}
