#ifndef ANTPLUS_LEVBASESPEEDSYSTEMINFORMATION_h
#define ANTPLUS_LEVBASESPEEDSYSTEMINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>

class LevBaseSpeedSystemInformation : public LevBaseMainDataPage {
public:
    explicit LevBaseSpeedSystemInformation(AntRxDataResponse& dp);
    uint8_t getCurrentRegenerativeLevel();
    uint8_t getCurrentAssistLevel();
    uint8_t getSystemState();
    uint8_t getCurrentFrontGear();
    uint8_t getCurrentRearGear();
    uint8_t getManualAutoState();
    uint8_t getGearExist();
    uint16_t getSpeed(); // in 1/10 km/h
};

#endif // ANTPLUS_LEVBASESPEEDSYSTEMINFORMATION_h
