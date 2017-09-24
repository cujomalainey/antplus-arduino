#ifndef ANTPLUS_HEARTRATEDEFAULT_h
#define ANTPLUS_HEARTRATEDEFAULT_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

class HeartRateDefault : public HeartRateBaseMainDataPage {
public:
    HeartRateDefault(BroadcastData& dp);
};

#endif // ANTPLUS_HEARTRATEDEFAULT_h