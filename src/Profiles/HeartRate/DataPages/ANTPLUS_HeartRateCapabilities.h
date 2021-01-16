#ifndef ANTPLUS_HEARTRATECAPABILITIES_h
#define ANTPLUS_HEARTRATECAPABILITIES_h

#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>

template<class T>
class HeartRateBaseCapabilities : virtual public CoreDataPage<T> {
public:
    HeartRateBaseCapabilities();
    uint8_t getFeaturesSupported();
    uint8_t getFeaturesEnabled();
};

class HeartRateCapabilities : public HeartRateBaseMainDataPage, public HeartRateBaseCapabilities<BroadcastData> {
public:
    explicit HeartRateCapabilities(AntRxDataResponse& dp);
};

class HeartRateCapabilitiesMsg : public HeartRateBaseMainDataPageMsg, HeartRateBaseCapabilities<BroadcastDataMsg> {
public:
    HeartRateCapabilitiesMsg();
    void setFeaturesSupported(uint8_t supported);
    void setFeaturesEnabled(uint8_t enabled);
};

#endif // ANTPLUS_HEARTRATECAPABILITIES_h
