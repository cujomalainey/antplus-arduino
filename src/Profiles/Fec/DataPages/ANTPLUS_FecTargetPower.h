#ifndef ANTPLUS_FECTARGETPOWER_h
#define ANTPLUS_FECTARGETPOWER_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseTargetPower : virtual public CoreDataPage<T> {
public:
    FecBaseTargetPower();
    uint16_t getTargetPower();
};

class FecTargetPower : public FecBaseMainDataPage, public FecBaseTargetPower<BroadcastData> {
public:
    explicit FecTargetPower(AntRxDataResponse& dp);
};

class FecTargetPowerMsg : public FecBaseMainDataPageMsg, public FecBaseTargetPower<BroadcastDataMsg> {
public:
    FecTargetPowerMsg();
    void setTargetPower(uint16_t targetPower);
};


#endif // ANTPLUS_FECTARGETPOWER_h

