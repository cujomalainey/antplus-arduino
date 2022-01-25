#ifndef ANTPLUS_FECTARGETPOWERDATAPAGE_h
#define ANTPLUS_FECTARGETPOWERDATAPAGE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseTargetPowerDataPage : virtual public CoreDataPage<T> {
public:
    FecBaseTargetPowerDataPage();
    uint16_t getTargetPower();
};

class FecTargetPowerDataPage : public FecBaseMainDataPage, public FecBaseTargetPowerDataPage<BroadcastData> {
public:
    explicit FecTargetPowerDataPage(AntRxDataResponse& dp);
};

class FecTargetPowerDataMsg : public FecBaseMainDataPageMsg, public FecBaseTargetPowerDataPage<BroadcastDataMsg> {
public:
    FecTargetPowerDataMsg();
    void setTargetPower(uint16_t TargetPower);
};


#endif // ANTPLUS_FECTARGETPOWERDATAPAGE_h

