#ifndef ANTPLUS_LEVSPEEDSYSTEMINFORMATION1_h
#define ANTPLUS_LEVSPEEDSYSTEMINFORMATION1_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>

class LevSpeedSystemInformation1 : public LevBaseMainDataPage {
public:
    LevSpeedSystemInformation1(AntRxDataResponse& dp);
    uint8_t getBatteryTemperatureState();
    uint8_t getBatteryTemperatureAlert();
    uint8_t getMotorTemperatureState();
    uint8_t getMotorTemperatureAlert();
    uint8_t getCurrentRegenerativeLevel();
    uint8_t getCurrentAssistLevel();
    uint8_t getSystemState();
    uint8_t getCurrentFrontGear();
    uint8_t getCurrentRearGear();
    uint8_t getManualAutoState();
    uint8_t getGearExist();
    uint8_t getErrorMessage();
    uint16_t getSpeed(); // in 1/10 km/h
};

#endif // ANTPLUS_LEVSPEEDSYSTEMINFORMATION1_h
