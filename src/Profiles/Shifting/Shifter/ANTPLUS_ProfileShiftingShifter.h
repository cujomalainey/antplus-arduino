#ifndef ANTPLUS_PROFILESHIFTINGSHIFTER_h
#define ANTPLUS_PROFILESHIFTINGSHIFTER_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/Shifting/DataPages/ANTPLUS_ProfileShiftingDataPages.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileShiftingShifter : public BaseMasterProfile {
public:
    ProfileShiftingShifter(uint16_t deviceNumber, uint8_t transmissionType = ANTPLUS_SHIFTING_SHIFTER_TRANSMISSIONTYPE);

    /**
     * Register callback to populate default data messages (Datapage 0)
     */
    void createShiftingSystemStatusMsg(void(*func)(ShiftingBaseMainDataPageMsg&, uintptr_t), uintptr_t data = 0) { _createShiftingSystemStatusMsg.set(func, data); }
    /**
     * Register callback to populate manufacturer information data messages (Datapage 2)
     */
    void createShiftingManufacturerInformationMsg(void(*func)(ManufacturersInformationMsg&, uintptr_t), uintptr_t data = 0) { _createShiftingManufacturerInformationMsg.set(func, data); }
    /**
     * Register callback to populate product information data messages (Datapage 3)
     */
    void createShiftingProductInformationMsg(void(*func)(ProductInformationMsg&, uintptr_t), uintptr_t data = 0) { _createShiftingProductInformationMsg.set(func, data); }

protected:
    virtual void transmitNextDataPage();
    virtual bool isDataPageValid(uint8_t dataPage);

    void transmitShiftingManufacturerInformationMsg();
    void transmitShiftingProductInformationMsg();

private:
    void setChannelConfig();
    void transmitShiftingMainPageMsg();

    uint8_t _patternStep;
    uint8_t _toggle;

    Callback<ShiftingBaseMainDataPageMsg&> _createShiftingSystemStatusMsg;
    Callback<ManufacturersInformationMsg&> _createShiftingManufacturerInformationMsg;
    Callback<ProductInformationMsg&> _createShiftingProductInformationMsg;
};

#endif // ANTPLUS_PROFILESHIFTINGSHIFTER_h
