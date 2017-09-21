#ifndef ANTPLUS_HEARTRATECAPABILITIESMSG_h
#define ANTPLUS_HEARTRATECAPABILITIESMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>

class HeartRateCapabilitiesMsg : public HeartRateBaseMainDataPageMsg {
public:
    HeartRateCapabilitiesMsg();
    uint8_t getFeaturesSupported();
    uint8_t getFeaturesEnabled();
    void setFeaturesSupported(uint8_t supported);
    void setFeaturesEnabled(uint8_t enabled);
};

#endif // ANTPLUS_HEARTRATECAPABILITIESMSG_h