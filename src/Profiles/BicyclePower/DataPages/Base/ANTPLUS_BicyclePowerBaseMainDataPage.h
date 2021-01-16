#ifndef ANTPLUS_BICYCLEPOWERBASEMAINDATAPAGE_h
#define ANTPLUS_BICYCLEPOWERBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class BicyclePowerBaseMainDataPage : public BaseDataPage<BroadcastData> {
public:
    explicit BicyclePowerBaseMainDataPage(AntRxDataResponse& dp);
    uint8_t getDataPageNumber() override;
    uint8_t getUpdateEventCount();

};

#endif // ANTPLUS_BICYCLEPOWERPOWERONLYDATAPAGE_h
