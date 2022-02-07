#ifndef ANTPLUS_LEVBATTERYINFORMATION_h
#define ANTPLUS_LEVBATTERYINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>

template<class T>
class LevBaseBatteryInformation : virtual public CoreDataPage<T> {
public:
    LevBaseBatteryInformation();
    uint16_t getChargingCycleCount();
    uint16_t getFuelConsumption();
    uint8_t getBatteryVoltage();
    uint16_t getDistanceOnCurrentCharge();
};

class LevBatteryInformation : public LevBaseMainDataPage, public LevBaseBatteryInformation<BroadcastData> {
public:
    explicit LevBatteryInformation(AntRxDataResponse& dp);
};

class LevBatteryInformationMsg : public LevBaseMainDataPageMsg<BroadcastDataMsg>, public LevBaseBatteryInformation<BroadcastDataMsg> {
public:
    LevBatteryInformationMsg();
    void setChargingCycleCount(uint16_t cycleCount);
    void setFuelConsumption(uint16_t consumption);
    void setBatteryVoltage(uint8_t voltage);
    void setDistanceOnCurrentCharge(uint16_t distance);
};
#endif // ANTPLUS_LEVBATTERYINFORMATION_h
