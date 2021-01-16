#ifndef ANTPLUS_HEARTRATEDEFAULT_h
#define ANTPLUS_HEARTRATEDEFAULT_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

class HeartRateDefault : public HeartRateBaseMainDataPage {
public:
    explicit HeartRateDefault(AntRxDataResponse& dp);
};

#endif // ANTPLUS_HEARTRATEDEFAULT_h
