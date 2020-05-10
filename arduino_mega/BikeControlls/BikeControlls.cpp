#include "BikeControlls.h"

BikeControlls::BikeControlls(BikeStrategy *strategy = nullptr) : strategy_(strategy)
{
}
BikeControlls::~BikeControlls()
{
    delete this->strategy_;
}
void BikeControlls::setStrategy(BikeStrategy *strategy)
{
    delete this->strategy_;
    this->strategy_ = strategy;
}

void BikeControlls::LockBike() const
{
    return this->strategy_->LockBike();
}
void BikeControlls::UnlockBike() const
{
    return this->strategy_->UnlockBike();
}
void BikeControlls::TurnOnStarter() const
{
    return this->strategy_->TurnOnStarter();
}
void BikeControlls::TurnOffStarter() const
{
    return this->strategy_->TurnOffStarter();
}
void BikeControlls::TurnOffBike() const
{
    return this->strategy_->TurnOffBike();
}
void BikeControlls::TurnOnHeadlight() const
{
    return this->strategy_->TurnOnHeadlight();
}
void BikeControlls::TurnOffHeadlight() const
{
    return this->strategy_->TurnOffHeadlight();
}
void BikeControlls::TurnOnHighBeam() const
{
    return this->strategy_->TurnOnHighBeam();
}
void BikeControlls::TurnOffHighBeam() const
{
    return this->strategy_->TurnOffHighBeam();
}
void BikeControlls::TurnOnMarkers() const
{
    return this->strategy_->TurnOnMarkers();
}
void BikeControlls::TurnOffMarkers() const
{
    return this->strategy_->TurnOffMarkers();
}
void BikeControlls::TurnOnHorn() const
{
    return this->strategy_->TurnOnHorn();
}
void BikeControlls::TurnOffHorn() const
{
    return this->strategy_->TurnOffHorn();
}
void BikeControlls::TurnOnBrakes() const
{
    return this->strategy_->TurnOnBrakes();
}
void BikeControlls::TurnOffBrakes() const
{
    return this->strategy_->TurnOffBrakes();
}
void BikeControlls::TurnOnHazard() const
{
    return this->strategy_->TurnOnHazard();
}
void BikeControlls::TurnOffHazard() const
{
    return this->strategy_->TrunOffHazard();
}
void BikeControlls::TurnOnLeftTurn() const
{
    return this->strategy_->TurnOnLeftTurn();
}
void BikeControlls::TurnOnRightTurn() const
{
    return this->strategy_->TurnOnRightTurn();
}
void BikeControlls::TurnOffTurns() const
{
    return this->strategy_->TurnOffTurns();
}
