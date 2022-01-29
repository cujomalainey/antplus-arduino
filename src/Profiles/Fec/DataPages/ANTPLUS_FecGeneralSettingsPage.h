#ifndef ANTPLUS_FECGENERALSEETTINGSDATAPAGE_h
#define ANTPLUS_FECGENERALSEETTINGSDATAPAGE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseGeneralSettingsPage : virtual public CoreDataPage<T> {
public:
    FecBaseGeneralSettingsPage();
    uint8_t getCycleLength();
    uint16_t getIncline();
    uint8_t getResistanceLevel();
    // Capability bits are reserved
    uint8_t getFeState();
    uint8_t getLapToggleBit();
};

class FecGeneralSettingsPage : public FecBaseMainDataPage, public FecBaseGeneralSettingsPage<BroadcastData> {
public:
    explicit FecGeneralSettingsPage(AntRxDataResponse& dp);
};

class FecGeneralSettingsPageMsg : public FecBaseMainDataPageMsg, public FecBaseGeneralSettingsPage<BroadcastDataMsg> {
public:
    FecGeneralSettingsPageMsg();
    void setCycleLength(uint8_t cycleLength);
    void setIncline(uint16_t incline);
    void setResistanceLevel(uint8_t resistanceLevel);
    // Capability bits are reserved
    void setFeState(uint8_t state);
    void setLapToggleBit(uint8_t toggle);
};


#endif // ANTPLUS_FECGENERALSETTINGSDATAPAGE_h
