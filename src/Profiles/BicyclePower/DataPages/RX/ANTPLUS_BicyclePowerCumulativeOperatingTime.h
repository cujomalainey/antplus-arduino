#ifndef ANTPLUS_BICYCLEPOWERCUMULATIVEOPERATINGTIME_h
#define ANTPLUS_BICYCLEPOWERCUMUATIVEOPERATINGTIME_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseCumulativeOperatingTime.h>

class BicyclePowerCumulativeOperatingTime : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseCumulativeOperatingTime<BroadcastData> {
public:
    BicyclePowerCumulativeOperatingTime(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERCUMULITIVEOPERATINGTIME_h
