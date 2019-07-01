#ifndef ANTPLUS_LEVSPEEDSYSTEMINFORMATION2_h
#define ANTPLUS_LEVSPEEDSYSTEMINFORMATION2_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseSpeedSystemInformation.h>

class LevSpeedSystemInformation2 : public LevBaseSpeedSystemInformation {
public:
    LevSpeedSystemInformation2(AntRxDataResponse& dp);
    uint8_t getBatterySOC();
    uint8_t getBatteryEmptyWarning();
    uint8_t getTravelModeState();
    uint8_t getSystemState();
    uint8_t getGearState();
    uint8_t getPercentAssist();
    uint16_t getSpeed(); // in 1/10 km/h
};

#endif // ANTPLUS_LEVSPEEDSYSTEMINFORMATION2_h
