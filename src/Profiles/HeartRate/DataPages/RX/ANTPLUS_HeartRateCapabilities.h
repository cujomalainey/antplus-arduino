#ifndef ANTPLUS_HEARTRATECAPABILITIES_h
#define ANTPLUS_HEARTRATECAPABILITIES_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

class HeartRateCapabilities : public HeartRateBaseMainDataPage {
public:
    HeartRateCapabilities(BroadcastData& dp);
    uint8_t getFeaturesSupported();
    uint8_t getFeaturesEnabled();
};

#endif // ANTPLUS_HEARTRATECAPABILITIES_h