#ifndef ANTPLUS_PROFILEFECDISPLAY_h
#define ANTPLUS_PROFILEFECDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/Fec/ANTPLUS_FecDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileFecDisplay : public BaseSlaveProfile {
public:
    ProfileFecDisplay(uint16_t deviceNumber = 0, uint8_t transmissionType = 0);
    void onFecTrainerData(void (*func)(FecSpecificTrainerData&, uintptr_t), uintptr_t data = 0) { _onFecSpecificTrainerData.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg);
    void onAcknowledgedData(AcknowledgedData& msg);

    bool handleDataPage(BaseDataPage<BroadcastData>& dp);

    bool handleTrainerData(BaseDataPage<BroadcastData>& dataPage);
    AntCallback<FecSpecificTrainerData&> _onFecSpecificTrainerData = { .func = NULL };
};

#endif // ANTPLUS_PROFILEFECDISPLAY_h
