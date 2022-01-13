#ifndef ANTPLUS_FECUSERINFORMATIONDATAPAGE_h
#define ANTPLUS_FECUSERINFORMATIONDATAPAGE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseUserInformationDatapage : virtual public CoreDataPage<T> {
public:
    FecBaseUserInformationDatapage();
    uint16_t getUserWeight();
    uint16_t getBikeWeight();
};

class FecUserInformationDatapage : public FecBaseMainDataPage, public FecBaseUserInformationDatapage<BroadcastData> {
public:
    explicit FecUserInformationDatapage(AntRxDataResponse& dp);
};

class FecUserInformationMsg : public FecBaseMainDataPageMsg, public FecBaseUserInformationDatapage<BroadcastDataMsg> {
public:
    FecUserInformationMsg();
    void setUserWeight(uint16_t UserWeight);
    void setBikeWeight(uint16_t BikeWeight);
};

#endif // ANTPLUS_FECUSERINFORMATIONDATAPAGE_h

