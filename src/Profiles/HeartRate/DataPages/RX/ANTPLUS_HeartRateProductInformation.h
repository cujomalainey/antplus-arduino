#ifndef ANTPLUS_HEARTRATEPRODUCTIONINFORMATION_h
#define ANTPLUS_HEARTRATEPRODUCTIONINFORMATION_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseProductInformation.h>

class HeartRateProductInformation : public HeartRateBaseMainDataPage, public HeartRateBaseProductInformation<BroadcastData> {
public:
    explicit HeartRateProductInformation(AntRxDataResponse& dp);
};

#endif // ANTPLUS_HEARTRATEPRODUCTIONINFORMATION_h
