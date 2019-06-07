#ifndef ANTPLUS_LEVBASEMAINDATAPAGE_h
#define ANTPLUS_LEVBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class LevBaseMainDataPage : public BaseDataPage<BroadcastData> {
public:
	LevBaseMainDataPage(AntRxDataResponse& dp);
    uint8_t getDataPageNumber();
};

#endif // ANTPLUS_LEVBASEMAINDATAPAGE_h
