#ifndef ANTPLUS_FECGENERALMAINDATAPAGE_h
#define ANTPLUS_FECGENERALMAINDATAPAGE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseGeneralMainDataPage : virtual public CoreDataPage<T> {
public:
    FecBaseGeneralMainDataPage();
    uint8_t getEquipmentTypeBits();
    uint8_t getElapsedTime();
    uint8_t getDistanceTraveled();
    uint16_t getSpeed(bool km);
    uint8_t getHeartRate();
    uint8_t getCapabilitiesBits();
    uint8_t getFEStateBits();
};

class FecGeneralMainDataPage : public FecBaseMainDataPage, public FecBaseGeneralMainDataPage<BroadcastData> {
public:
    explicit FecGeneralMainDataPage(AntRxDataResponse& dp);
};

class FecGeneralMainDataMsg : public FecBaseMainDataPageMsg, public FecBaseGeneralMainDataPage<BroadcastDataMsg> {
public:
    FecGeneralMainDataMsg();
  //  void setSoftwareRevision(uint16_t SoftwareRevision);
};


#endif // ANTPLUS_FECGENERALMAINDATAPAGE_h
