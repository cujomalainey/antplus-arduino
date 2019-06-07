#ifndef ANTPLUS_LEVSPEEDSYSINFO2_h
#define ANTPLUS_LEVSPEEDSYSINFO2_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>

class LevSpeedSysinfo2 : public LevBaseMainDataPage {
public:
    LevSpeedSysinfo2(AntRxDataResponse& dp);
    uint8_t getBatterySOC();
    uint8_t getTravelModeState();
    uint8_t getSystemState();
    uint8_t getGearState();
    uint8_t getPercentAssist();
    uint16_t getSpeed(); // in 1/10 km/h
};

#endif // ANTPLUS_LEVSPEEDSYSINFO2_h
