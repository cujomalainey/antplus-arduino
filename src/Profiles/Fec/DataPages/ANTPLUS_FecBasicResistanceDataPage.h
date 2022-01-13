#ifndef ANTPLUS_FECBASICRESISTANCEDATAPAGE_h
#define ANTPLUS_FECBASICRESISTANCEDATAPAGE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseBasicResistanceDataPage : virtual public CoreDataPage<T> {
public:
    FecBaseBasicResistanceDataPage();
    uint8_t getPower();
};

class FecBasicResistanceDataPage : public FecBaseMainDataPage, public FecBaseBasicResistanceDataPage<BroadcastData> {
public:
    explicit FecBasicResistanceDataPage(AntRxDataResponse& dp);
};

class FecBasicResistanceDataMsg : public FecBaseMainDataPageMsg, public FecBaseBasicResistanceDataPage<BroadcastDataMsg> {
public:
    FecBasicResistanceDataMsg();
    void setPower(uint8_t Power);
};


#endif // ANTPLUS_FECBASICRESISTANCEDATAPAGE_h

