#ifndef ANTPLUS_FECGENERALSEETTINGSDATAPAGE_h
#define ANTPLUS_FECGENERALSEETTINGSDATAPAGE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseGeneralSettingsDataPage : virtual public CoreDataPage<T> {
public:
    FecBaseGeneralSettingsDataPage();
    uint8_t getCycleLength();
    uint8_t getInclineValue();
    uint8_t getResistanceLevel();
    uint8_t getCapabilitiesBits();
    uint8_t getFEStateBits();
};

class FecGeneralSettingsDataPage : public FecBaseMainDataPage, public FecBaseGeneralSettingsDataPage<BroadcastData> {
public:
    explicit FecGeneralSettingsDataPage(AntRxDataResponse& dp);
};

class FecGeneralSettingsDataMsg : public FecBaseMainDataPageMsg, public FecBaseGeneralSettingsDataPage<BroadcastDataMsg> {
public:
    FecGeneralSettingsDataMsg();
    void setResistanceLevel(uint8_t ResistanceLevel);
};


#endif // ANTPLUS_FECGENERALSETTINGSDATAPAGE_h
