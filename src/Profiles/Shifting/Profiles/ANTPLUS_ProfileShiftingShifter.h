#ifndef ANTPLUS_PROFILESHIFTINGSHIFTER_h
#define ANTPLUS_PROFILESHIFTINGSHIFTER_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/Shifting/ANTPLUS_ProfileShiftingDataPages.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileShiftingShifter : public BaseMasterProfile {
public:
    explicit ProfileShiftingShifter(uint16_t deviceNumber,
            uint8_t transmissionType = 0,
            uint16_t componentsSupported = ANTPLUS_SHIFTING_COMPONENTIDENTIFIER_SYSTEM_FLAG);
    /**
     * Register callback to populate default data messages (Datapage 1)
     */
    void createShiftingShiftSystemStatusMsg(void(*func)(ShiftingShiftSystemStatusMsg&, uintptr_t), uintptr_t data = 0) { _createShiftingShiftSystemStatusMsg.set(func, data); }
    /**
     * Register callback to populate multi component system manufacturer information data messages (Datapage 78)
     */
    void createMultiComponentSystemManufacturersInformationMsg(void(*func)(MultiComponentSystemManufacturersInformationMsg&, uintptr_t), uintptr_t data = 0) { _createMultiComponentSystemManufacturersInformationMsg.set(func, data); }
    /**
     * Register callback to populate multi component system product information data messages (Datapage 79)
     */
    void createMultiComponentSystemProductInformationMsg(void(*func)(MultiComponentSystemProductInformationMsg&, uintptr_t), uintptr_t data = 0) { _createMultiComponentSystemProductInformationMsg.set(func, data); }
    /**
     * Register callback to populate battery status data messages (Datapage 82)
     */
    void createBatteryStatusMsg(void(*func)(BatteryStatusMsg&, uintptr_t), uintptr_t data = 0) { _createBatteryStatusMsg.set(func, data); }
    /**
     * Register callback to handle incoming request dataPage. The profile will automatically
     * adjust the broadcast pattern, there is no need for you to do anything with this message.
     */
    void onRequestDataPage(void (*func)(RequestDataPage&, uintptr_t), uintptr_t data = 0) { _onRequestDataPage.set(func, data); }

protected:
    virtual void transmitNextDataPage() override;
    virtual bool isDataPageValid(uint8_t dataPage) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;
    void onBroadcastData(BroadcastData& msg) override;

private:
    void transmitShiftingMainPageMsg();
    void transmitMultiComponentSystemManufacturersInformationMsg();
    void transmitMultiComponentSystemProductInformationMsg();
    void transmitBatteryStatusMsg();
    bool handleRequestDataPage(BaseDataPage<AcknowledgedData>& dataPage);
    bool isSupportedComponent(uint8_t id);
    bool isMultiComponentDevice();
    uint8_t getLowestBitPosition(uint16_t id);

    void transmitBackgroundDataPage();
    void setChannelConfig();

    uint8_t _patternStep = 0;
    uint8_t _backgroundStep = 0;
    uint8_t _shiftCounter = 0;
    uint8_t _componentState = 0;
    uint16_t _componentFlags;
    uint8_t _interleaveStep;
    uint8_t _componentCount = 0;

    AntCallback<ShiftingShiftSystemStatusMsg&> _createShiftingShiftSystemStatusMsg = { .func = NULL };
    AntCallback<MultiComponentSystemManufacturersInformationMsg&> _createMultiComponentSystemManufacturersInformationMsg = { .func = NULL };
    AntCallback<MultiComponentSystemProductInformationMsg&> _createMultiComponentSystemProductInformationMsg = { .func = NULL };
    AntCallback<BatteryStatusMsg&> _createBatteryStatusMsg = { .func = NULL };
    AntCallback<RequestDataPage&> _onRequestDataPage = { .func = NULL };
};

#endif // ANTPLUS_PROFILESHIFTINGSHIFTER_h
