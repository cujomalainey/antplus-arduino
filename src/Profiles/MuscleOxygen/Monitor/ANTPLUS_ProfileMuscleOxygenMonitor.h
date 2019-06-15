#ifndef ANTPLUS_PROFILEMUSCLEOXYGENMONITOR_h
#define ANTPLUS_PROFILEMUSCLEOXYGENMONITOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/MuscleOxygen/DataPages/ANTPLUS_ProfileMuscleOxygenDataPages.h>
#include <Profiles/MuscleOxygen/ANTPLUS_MuscleOxygenPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileMuscleOxygenMonitor : public BaseMasterProfile {
public:
    ProfileMuscleOxygenMonitor(uint16_t deviceNumber, uint8_t transmissionType = ANTPLUS_MUSCLEOXYGEN_MONITOR_TRANSMISSIONTYPE);

    /**
     * Register callback to populate default data messages (Datapage 0)
     */
    void createMuscleOxygenDataMsg(void(*func)(MuscleOxygenBaseMainDataPageMsg&, uintptr_t), uintptr_t data = 0) { _createMuscleOxygenDataMsg.set(func, data); }

protected:
    virtual void transmitNextDataPage();
    virtual bool isDataPageValid(uint8_t dataPage) { return true; }

private:
    void setChannelConfig();
    void transmitMuscleOxygenMainPageMsg();
    
    uint8_t _patternStep;
    uint8_t _toggle;

    Callback<MuscleOxygenBaseMainDataPageMsg&> _createMuscleOxygenDataMsg;
};

#endif // ANTPLUS_PROFILEMUSCLEOXYGENMONITOR_h
