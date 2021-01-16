#ifndef ANTPLUS_HEARTRATECAPABILITIES_h
#define ANTPLUS_HEARTRATECAPABILITIES_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseCapabilities.h>

class HeartRateCapabilities : public HeartRateBaseMainDataPage, public HeartRateBaseCapabilities<BroadcastData> {
public:
    explicit HeartRateCapabilities(AntRxDataResponse& dp);
};

#endif // ANTPLUS_HEARTRATECAPABILITIES_h
