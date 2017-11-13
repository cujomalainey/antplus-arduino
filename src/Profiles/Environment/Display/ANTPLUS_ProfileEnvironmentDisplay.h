#ifndef ANTPLUS_PROFILEHEARTRATEMONITOR_h
#define ANTPLUS_PROFILEHEARTRATEMONITOR_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/Environment/DataPages/ANTPLUS_ProfileEnvironmentDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

#include "ANT.h"

class ProfileEnvironmentDisplay : public BaseSlaveProfile {
public:
    ProfileEnvironmentDisplay();
    ProfileEnvironmentDisplay(uint16_t deviceNumber);
    ProfileEnvironmentDisplay(uint16_t deviceNumber, uint8_t transmissionType);
    void onEnvironmentGeneralInformation(void (*func)(EnvironmentGeneralInformation&, uintptr_t), uintptr_t data = 0) { _onEnvironmentGeneralInformation.set(func, data); }
    void onManufacturersInformation(void (*func)(ManufacturersInformation&, uintptr_t), uintptr_t data = 0) { _onManufacturersInformation.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg);
    void onAcknowledgedData(AcknowledgedData& msg);

    bool handleGeneralInformation(EnvironmentGeneralInformation& dataPage);
    Callback<EnvironmentGeneralInformation&> _onEnvironmentGeneralInformation;
    Callback<ManufacturersInformation&> _onManufacturersInformation;
};

#endif // ANTPLUS_PROFILEHEARTRATEMONITOR_h
