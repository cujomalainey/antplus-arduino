#ifndef ANTPLUS_ENVIRONMENTTEMPERATURE_h
#define ANTPLUS_ENVIRONMENTTEMPERATURE_h

#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseDataPage.h>

class EnvironmentTemperature : public EnvironmentBaseDataPage {
public:
    EnvironmentTemperature(AntRxDataResponse& dp);
    uint8_t getEventCount();
    uint16_t get24HourLow();
    uint16_t get24HourHigh();
    uint16_t getCurrentTemp();
};

#endif // ANTPLUS_ENVIRONMENTTEMPERATURE_h

