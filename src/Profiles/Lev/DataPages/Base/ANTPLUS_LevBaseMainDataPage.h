#ifndef ANTPLUS_LEVBASEMAINDATAPAGE_h
#define ANTPLUS_LEVBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class LevBaseMainDataPage : public BaseDataPage<BroadcastData> {
public:
    LevBaseMainDataPage(AntRxDataResponse& dp);
};

#endif // ANTPLUS_LEVBASEMAINDATAPAGE_h
