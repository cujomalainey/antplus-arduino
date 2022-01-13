#ifndef ANTPLUS_FECCAPABILITIESINFORMATIONDATAPAGE_h
#define ANTPLUS_FECCAPABILITIESINFORMATIONDATAPAGE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseCapabilitiesInformationDatapage : virtual public CoreDataPage<T> {
public:
    FecBaseCapabilitiesInformationDatapage();
    uint16_t getMaximumResistance();
    uint8_t getCapabilities();
};

class FecCapabilitiesInformationDatapage : public FecBaseMainDataPage, public FecBaseCapabilitiesInformationDatapage<BroadcastData> {
public:
    explicit FecCapabilitiesInformationDatapage(AntRxDataResponse& dp);
};

class FecCapabilitiesInformationMsg : public FecBaseMainDataPageMsg, public FecBaseCapabilitiesInformationDatapage<BroadcastDataMsg> {
public:
    FecCapabilitiesInformationMsg();
    void setMaximumResistance(uint16_t UserWeight);
    void setCapabitilies(uint8_t BikeWeight);
};

#endif // ANTPLUS_FECCAPABILITIESINFORMATIONDATAPAGE_h

