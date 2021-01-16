#ifndef ANTPLUS_ENVIRONMENTBASEMAINDATAPAGE_h
#define ANTPLUS_ENVIRONMENTBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class EnvironmentBaseDataPage : public BaseDataPage<BroadcastData> {
public:
    explicit EnvironmentBaseDataPage(AntRxDataResponse& dp);
};

#endif // ANTPLUS_ENVIRONMENTBASEMAINDATAPAGE_h
