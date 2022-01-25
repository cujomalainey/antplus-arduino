#ifndef ANTPLUS_FECBASICRESISTANCE_h
#define ANTPLUS_FECBASICRESISTANCE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseBasicResistance : virtual public CoreDataPage<T> {
public:
    FecBaseBasicResistance();
    uint8_t getTotalResistance();
};

class FecBasicResistance : public FecBaseMainDataPage, public FecBaseBasicResistance<BroadcastData> {
public:
    explicit FecBasicResistance(AntRxDataResponse& dp);
};

class FecBasicResistanceMsg : public FecBaseMainDataPageMsg, public FecBaseBasicResistance<BroadcastDataMsg> {
public:
    FecBasicResistanceMsg();
    void setTotalResistance(uint8_t totalResistance);
};


#endif // ANTPLUS_FECBASICRESISTANCE_h
