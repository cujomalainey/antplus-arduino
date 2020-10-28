#ifndef ANTPLUS_PROFILEFECDISPLAY_h
#define ANTPLUS_PROFILEFECDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/FEC/DataPages/ANTPLUS_ProfileFECDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

#include "ANT.h"

class ProfileFECDisplay : public BaseSlaveProfile {
public:
    ProfileFECDisplay();
    ProfileFECDisplay(uint16_t deviceNumber);
    ProfileFECDisplay(uint16_t deviceNumber, uint8_t transmissionType);
    void onFECTrainerData(void (*func)(FECTrainerData&, uintptr_t), uintptr_t data = 0) { _onFECTrainerData.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg);
    void onAcknowledgedData(AcknowledgedData& msg);

    bool handleDataPage(BaseDataPage<BroadcastData>& dp);

    bool handleTrainerData(BaseDataPage<BroadcastData>& dataPage);
    AntCallback<FECTrainerData&> _onFECTrainerData;
};

#endif // ANTPLUS_PROFILEFECDISPLAY_h
