#ifndef ANTPLUS_LEVSPEEDSYSTEMINFORMATION1_h
#define ANTPLUS_LEVSPEEDSYSTEMINFORMATION1_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>

class LevSpeedSystemInformation1 : public LevBaseSpeedSystemInformation {
public:
    LevSpeedSystemInformation1(AntRxDataResponse& dp);
    uint8_t getBatteryTemperatureState();
    uint8_t getBatteryTemperatureAlert();
    uint8_t getMotorTemperatureState();
    uint8_t getMotorTemperatureAlert();
    uint8_t getErrorMessage();
};

#endif // ANTPLUS_LEVSPEEDSYSTEMINFORMATION1_h
