#ifndef ANTPLUS_LEVSPEEDSYSINFO1_h
#define ANTPLUS_LEVSPEEDSYSINFO1_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>

class LevSpeedSysinfo1 : public LevBaseMainDataPage {
public:
    LevSpeedSysinfo1(AntRxDataResponse& dp);
    uint8_t getTempState();
    uint8_t getTravelModeState();
    uint8_t getSystemState();
    uint8_t getGearState();
    uint8_t getError();
    uint16_t getSpeed(); // in 1/10 km/h
};

#endif // ANTPLUS_LEVSPEEDSYSINFO1_h
