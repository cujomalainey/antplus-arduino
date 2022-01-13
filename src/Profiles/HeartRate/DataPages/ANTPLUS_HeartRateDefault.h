#ifndef ANTPLUS_HEARTRATEDEFAULT_h
#define ANTPLUS_HEARTRATEDEFAULT_h

#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>

class HeartRateDefault : public HeartRateBaseMainDataPage {
public:
    explicit HeartRateDefault(AntRxDataResponse& dp);
};

class HeartRateDefaultMsg : public HeartRateBaseMainDataPageMsg {
public:
    HeartRateDefaultMsg();
};

#endif // ANTPLUS_HEARTRATEDEFAULT_h
