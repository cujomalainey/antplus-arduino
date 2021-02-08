#ifndef ANTPLUS_BICYCLEPOWERSTANDARDWHEELTORQUE_h
#define ANTPLUS_BICYCLEPOWERSTANDARDWHEELTORQUE_h

#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>

template<class T>
class BicyclePowerBaseStandardWheelTorque : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseStandardWheelTorque();
    uint8_t getWheelTicks();
    uint8_t getInstantaneousCadence(); // TODO(is valid check) May not be available, 0xFF indicates invalid
    uint16_t getWheelPeriod();
    uint16_t getAccumulatedTorque();
};

class BicyclePowerStandardWheelTorque :
    public BicyclePowerBaseMainDataPage,
    public BicyclePowerBaseStandardWheelTorque<BroadcastData> {
public:
    explicit BicyclePowerStandardWheelTorque(AntRxDataResponse& dp);
};

class BicyclePowerStandardWheelTorqueMsg :
    public BicyclePowerBaseMainDataPageMsg,
    public BicyclePowerBaseStandardWheelTorque<BroadcastDataMsg> {
public:
    BicyclePowerStandardWheelTorqueMsg();
    void setWheelTicks(uint8_t ticks);
    void setInstantaneousCadence(uint8_t cadence); // TODO(is valid check) May not be available, 0xFF indicates invalid
    void setWheelPeriod(uint16_t period);
    void setAccumulatedTorque(uint16_t torque);
};

#endif // ANTPLUS_BICYCLEPOWERSTANDARDWHEELTORQUE_h
