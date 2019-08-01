#ifndef ANTPLUS_HEARTRATECAPABILITIESMSG_h
#define ANTPLUS_HEARTRATECAPABILITIESMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseCapabilities.h>

class HeartRateCapabilitiesMsg : public HeartRateBaseMainDataPageMsg, HeartRateBaseCapabilities<BroadcastDataMsg> {
public:
    HeartRateCapabilitiesMsg();
    void setFeaturesSupported(uint8_t supported);
    void setFeaturesEnabled(uint8_t enabled);
};

#endif // ANTPLUS_HEARTRATECAPABILITIESMSG_h
