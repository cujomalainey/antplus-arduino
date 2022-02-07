#ifndef ANTPLUS_PROFILEMUSCLEOXYGENMONITOR_h
#define ANTPLUS_PROFILEMUSCLEOXYGENMONITOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/MuscleOxygen/ANTPLUS_ProfileMuscleOxygenDataPages.h>
#include <Profiles/MuscleOxygen/ANTPLUS_MuscleOxygenPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileMuscleOxygenMonitor : public BaseMasterProfile {
public:
    explicit ProfileMuscleOxygenMonitor(uint16_t deviceNumber, uint8_t transmissionType = 0, uint32_t flags = 0);

    /**
     * Register callback to populate Muscle Oxygen data messages (Datapage 0x01)
     */
    void createMuscleOxygenMuscleOxygenDataMsg(void(*func)(MuscleOxygenMuscleOxygenDataMsg&, uintptr_t), uintptr_t data = 0) { _createMuscleOxygenMuscleOxygenDataMsg.set(func, data); }
    /**
     * Register callback to populate manufacturer information data messages (Datapage 0x50)
     */
    void createManufacturerInformationMsg(void(*func)(ManufacturersInformationMsg&, uintptr_t), uintptr_t data = 0) { _createManufacturersInformationMsg.set(func, data); }
    /**
     * Register callback to populate product information data messages (Datapage 0x51)
     */
    void createProductInformationMsg(void(*func)(ProductInformationMsg&, uintptr_t), uintptr_t data = 0) { _createProductInformationMsg.set(func, data); }
    /**
     * Register callback to populate battery status data messages (Datapage 0x52)
     */
    void createProductInformationMsg(void(*func)(BatteryStatusMsg&, uintptr_t), uintptr_t data = 0) { _createBatteryStatusMsg.set(func, data); }

protected:
    void transmitNextDataPage() override;
    bool isDataPageValid(uint8_t dataPage) override;

private:
    void setChannelConfig();
    void transmitMuscleOxygenMuscleOxygenDataMsg();
    void transmitManufacturerInformationMsg();
    void transmitProductInformationMsg();
    void transmitBatteryStatusMsg();

    uint8_t _patternStep = 0;
    uint8_t _backgroundStep = 0;
    uint8_t _backgroundStepSize = 0;
    uint32_t _flags;

    AntCallback<MuscleOxygenMuscleOxygenDataMsg&> _createMuscleOxygenMuscleOxygenDataMsg = { .func = NULL };
    AntCallback<ManufacturersInformationMsg&> _createManufacturersInformationMsg = { .func = NULL };
    AntCallback<ProductInformationMsg&> _createProductInformationMsg = { .func = NULL };
    AntCallback<BatteryStatusMsg&> _createBatteryStatusMsg = { .func = NULL };
};

#endif // ANTPLUS_PROFILEMUSCLEOXYGENMONITOR_h
