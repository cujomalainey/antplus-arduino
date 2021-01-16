#ifndef ANTPLUS_HEARTRATEBASEMAINDATAPAGE_h
#define ANTPLUS_HEARTRATEBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateCoreMainDataPage.h>

#include "ANT.h"

class HeartRateBaseMainDataPage : public BaseDataPage<BroadcastData>, public HeartRateCoreMainDataPage<BroadcastData> {
public:
    explicit HeartRateBaseMainDataPage(AntRxDataResponse& dp);
};

#endif // ANTPLUS_HEARTRATEBASEMAINDATAPAGE_h
