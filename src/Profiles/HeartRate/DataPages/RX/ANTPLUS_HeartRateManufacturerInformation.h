#ifndef ANTPLUS_HEARTRATEMANUFACTURERINFORMATION_h
#define ANTPLUS_HEARTRATEMANUFACTURERINFORMATION_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseManufacturerInformation.h>

class HeartRateManufacturerInformation : public HeartRateBaseMainDataPage, public HeartRateBaseManufacturerInformation<BroadcastData> {
public:
    explicit HeartRateManufacturerInformation(AntRxDataResponse& dp);
};

#endif // ANTPLUS_HEARTRATEMANUFACTURERINFORMATION_h
