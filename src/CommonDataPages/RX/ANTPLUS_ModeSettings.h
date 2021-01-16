#ifndef ANTPLUS_MODESETTINGS_h
#define ANTPLUS_MODESETTINGS_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <CommonDataPages/Base/ANTPLUS_BaseModeSettings.h>

#include "ANT.h"

// Common page 76

class ModeSettings : public BaseDataPage<BroadcastData>, public BaseModeSettings<BroadcastData> {
public:
    explicit ModeSettings(AntRxDataResponse& dp);
};

#endif // ANTPLUS_MODESETTINGS_h
