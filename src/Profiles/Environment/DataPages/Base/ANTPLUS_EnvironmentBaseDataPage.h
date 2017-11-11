#ifndef ANTPLUS_ENVIRONMENTBASEMAINDATAPAGE_h
#define ANTPLUS_ENVIRONMENTBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class EnvironmentBaseDataPage : public BaseDataPage<BroadcastData> {
public:
    EnvironmentBaseDataPage(AntRxDataResponse& dp);
    uint8_t getDataPageNumber();
};

#endif // ANTPLUS_ENVIRONMENTBASEMAINDATAPAGE_h
