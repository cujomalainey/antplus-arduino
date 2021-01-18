#ifndef ANTPLUS_BICYCLESPEEDBATTERYSTATUS_h
#define ANTPLUS_BICYCLESPEEDBATTERYSTATUS_h

#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

template<class T>
class BicycleSpeedBaseBatteryStatus : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseBatteryStatus();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVoltage();
    uint8_t getBatteryStatus();
};

class BicycleSpeedBatteryStatus : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseBatteryStatus<BroadcastData> {
public:
    explicit BicycleSpeedBatteryStatus(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDBATTERYSTATUS_h
