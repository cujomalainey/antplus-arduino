#ifndef ANTPLUS_BICYCLESPEEDBATTERYSTATUS_h
#define ANTPLUS_BICYCLESPEEDBATTERYSTATUS_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

class BicycleSpeedBatteryStatus : public BicycleSpeedBaseMainDataPage {
public:
    BicycleSpeedBatteryStatus(AntRxDataResponse& dp);
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVoltage();
    uint8_t getBatteryStatus();
};

#endif // ANTPLUS_BICYCLESPEEDBATTERYSTATUS_h
