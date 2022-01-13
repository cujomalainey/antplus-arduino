#ifndef ANTPLUS_HEARTRATEBATTERYSTATUS_h
#define ANTPLUS_HEARTRATEBATTERYSTATUS_h

#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>

template<class T>
class HeartRateBaseBatteryStatus : virtual public CoreDataPage<T> {
public:
    HeartRateBaseBatteryStatus();
    uint8_t getBatteryLevel();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVoltage();
    uint8_t getBatteryStatus();
};

class HeartRateBatteryStatus : public HeartRateBaseMainDataPage, public HeartRateBaseBatteryStatus<BroadcastData> {
public:
    explicit HeartRateBatteryStatus(AntRxDataResponse& dp);
};

class HeartRateBatteryStatusMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseBatteryStatus<BroadcastDataMsg> {
public:
    HeartRateBatteryStatusMsg();
    void setBatteryLevel(uint8_t level);
    void setFractionalBatteryVoltage(uint8_t voltage);
    void setCoarseBatteryVolage(uint8_t voltage);
    void setBatteryStatus(uint8_t status);
};

#endif // ANTPLUS_HEARTRATEBATTERYSTATUS_h
