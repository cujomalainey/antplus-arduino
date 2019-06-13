#ifndef ANTPLUS_PROFILESHIFTINGSHIFTER_h
#define ANTPLUS_PROFILESHIFTINGSHIFTER_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/Shifting/DataPages/ANTPLUS_ProfileShiftingDataPages.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileShiftingShifter : public BaseMasterProfile {
public:
    ProfileShiftingShifter(uint16_t deviceNumber, uint8_t transmissionType = ANTPLUS_SHIFTING_MASTER_TRANSMISSIONTYPE);

    /**
     * Register callback to populate default data messages (Datapage 0)
     */
    void createShiftingDataMsg(void(*func)(ShiftingBaseMainDataPageMsg&, uintptr_t), uintptr_t data = 0) { _createShiftingDataMsg.set(func, data); }

protected:
    virtual void transmitNextDataPage();
    virtual bool isDataPageValid(uint8_t dataPage) { return true; }

private:
    void setChannelConfig();
    void transmitShiftingMainPageMsg();

    uint8_t _patternStep;
    uint8_t _toggle;
    uint8_t _eventCount;

    Callback<ShiftingBaseMainDataPageMsg&> _createShiftingDataMsg;
};

#endif // ANTPLUS_PROFILESHIFTINGSHIFTER_h
