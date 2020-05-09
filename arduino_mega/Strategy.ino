
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

class Context
{
private:
    BikeStrategy *strategy_;

public:
    Context(BikeStrategy *strategy = nullptr) : strategy_(strategy)
    {
    }
    ~Context()
    {
        delete this->strategy_;
    }
    void set_strategy(BikeStrategy *strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }

    void DoSomeBusinessLogic() const
    {
    }
};
class RestingBikeStrategy : public BikeStrategy
{
    void LockBike() override
    {
        xTaskCreate(TaskBlinkAndBeep, "BlinkAndBeeb", 128, NULL, 1, NULL);
    }
    void UnlockBike() override
    {
        return;
    }
    void TurnIgnitionOn() override
    {
        xTaskCreate(TaskIgnition, "Ignition", 128, NULL, 1, NULL);
    }
};

class RunningBikeStrategy : public BikeStrategy
{
public:
    void TurnOnStarter() override
    {
        xTaskCreate(TaskStarter, "Starter", 128, NULL, 1, NULL);
    }
    void TurnOffStarter() override
    {
        xTaskCreate(TaskStarterOff, "Starter off", 128, NULL, 1, NULL);
    }
    void TurnIgnitionOff() override
    {
        xTaskCreate(TaskIgnitionOff, "Ignition off", 128, NULL, 1, NULL);
    }
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
};
class LockedBikeStrategy : public BikeStrategy
{
    void LockBike() override
    {
        // Bike is already locked;
        return
    }
    void UnlockBike() override
    {
        xTaskCreate(TaskBlinkAndBeep, "BlinkAndBeeb", 128, NULL, 2, NULL);
    }
    void TurnOnStarter() override
    {
        alarm();
    }
    void TurnOffStarter() override
    {
        alarm();
    }
    void TurnOffBike() override
    {
        alarm();
    }
    void TurnOnHeadlight() override
    {
        alarm();
    }
    void TurnOffHeadlight() override
    {
        alarm();
    }
    void TurnOnHighBeam() override
    {
        alarm();
    }
    void TurnOffHighBeam() override
    {
        alarm();
    }
    void TurnOnMarkers() override
    {
        alarm();
    }
    void TurnOffMarkers() override
    {
        alarm();
    }
    void TurnOnHorn() override
    {
        alarm();
    }
    void TurnOffHorn() override
    {
        alarm();
    }
    void TurnOnBrakes() override
    {
        alarm();
    }
    void TurnOffBrakes() override
    {
        alarm();
    }
    void TurnOnHazard() override
    {
        alarm();
    }
    void TurnOffHazard() override
    {
        alarm();
    }
    void TurnOnLeftTurn() override
    {
        alarm();
    }
    void TurnOnRightTurn() override
    {
        alarm();
    }
    void TurnOffTurns() override
    {
        alarm();
    }

private:
    void alarm()
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
