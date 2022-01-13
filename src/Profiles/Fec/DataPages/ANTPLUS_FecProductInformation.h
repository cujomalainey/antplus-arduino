#ifndef ANTPLUS_FECPRODUCTINFORMATION_h
#define ANTPLUS_FECPRODUCTINFORMATION_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseProductInformation : virtual public CoreDataPage<T> {
public:
    FecBaseProductInformation();
    uint16_t getSoftwareRevision();
};

class FecProductInformation : public FecBaseMainDataPage, public FecBaseProductInformation<BroadcastData> {
public:
    explicit FecProductInformation(AntRxDataResponse& dp);
};

class FecProductInformationMsg : public FecBaseMainDataPageMsg, public FecBaseProductInformation<BroadcastDataMsg> {
public:
    FecProductInformationMsg();
    void setSoftwareRevision(uint16_t SoftwareRevision);
};

#endif // ANTPLUS_FECPRODUCTINFORMATION_h
