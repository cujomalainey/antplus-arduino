#ifndef ANTPLUS_LEVBASESPEEDSYSTEMINFORMATION_h
#define ANTPLUS_LEVBASESPEEDSYSTEMINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>

template<class T>
class LevCoreSpeedSystemInformation : virtual public CoreDataPage<T> {
public:
    LevCoreSpeedSystemInformation();
    uint8_t getCurrentRegenerativeLevel();
    uint8_t getCurrentAssistLevel();
    uint8_t getSystemState();
    uint8_t getCurrentFrontGear();
    uint8_t getCurrentRearGear();
    uint8_t getManualAutoState();
    uint8_t getGearExist();
    uint16_t getSpeed(); // in 1/10 km/h
};

class LevBaseSpeedSystemInformation : public LevBaseMainDataPage, public LevCoreSpeedSystemInformation<BroadcastData> {
public:
    explicit LevBaseSpeedSystemInformation(AntRxDataResponse& dp);
};

class LevBaseSpeedSystemInformationMsg : public LevBaseMainDataPageMsg<BroadcastDataMsg>, public LevCoreSpeedSystemInformation<BroadcastDataMsg> {
public:
    explicit LevBaseSpeedSystemInformationMsg(uint8_t dataPageNumber);
    void setCurrentRegenerativeLevel(uint8_t level);
    void setCurrentAssistLevel(uint8_t level);
    void setSystemState(uint8_t state);
    void setCurrentFrontGear(uint8_t gear);
    void setCurrentRearGear(uint8_t gear);
    void setManualAutoState(uint8_t state);
    void setGearExist(uint8_t exists);
    void setSpeed(uint16_t speed); // in 1/10 km/h
};

#endif // ANTPLUS_LEVBASESPEEDSYSTEMINFORMATION_h
