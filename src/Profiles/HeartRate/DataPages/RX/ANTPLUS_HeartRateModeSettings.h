#ifndef ANTPLUS_HEARTRATEMODESETTINGS_h
#define ANTPLUS_HEARTRATEMODESETTINGS_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

#include "ANT.h"

class HeartRateModeSettings : public BroadcastData {
public:
    HeartRateModeSettings();
    uint8_t getSportMode();
};

#endif // ANTPLUS_HEARTRATEMODESETTINGS_h