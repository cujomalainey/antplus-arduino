#ifndef ANTPLUS_LEVBATTERYINFO_h
#define ANTPLUS_LEVBATTERYINFO_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>

class LevBatteryInfo : public LevBaseMainDataPage {
public:
    LevBatteryInfo(AntRxDataResponse& dp);
    uint16_t getChargingCycleCount();
    uint16_t getFuelConsumption();
    uint8_t getBatteryVoltage();
    uint16_t getDistanceOnCurrentCharge();
};

#endif // ANTPLUS_LEVBATTERYINFO_h
