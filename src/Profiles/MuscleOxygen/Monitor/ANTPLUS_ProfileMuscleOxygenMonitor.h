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
     * Register callback to populate Muscle Oxygen data messages (Datapage 0)
     */
    void createMuscleOxygenMuscleOxygenDataMsg(void(*func)(MuscleOxygenBaseMainDataPageMsg&, uintptr_t), uintptr_t data = 0) { _createMuscleOxygenMuscleOxygenDataMsg.set(func, data); }
    /**
     * Register callback to populate manufacturer information data messages (Datapage 2)
     */
    void createMuscleOxygenManufacturerInformationMsg(void(*func)(ManufacturersInformationMsg&, uintptr_t), uintptr_t data = 0) { _createMuscleOxygenManufacturerInformationMsg.set(func, data); }
    /**
     * Register callback to populate product information data messages (Datapage 3)
     */
    void createMuscleOxygenProductInformationMsg(void(*func)(ProductInformationMsg&, uintptr_t), uintptr_t data = 0) { _createMuscleOxygenProductInformationMsg.set(func, data); }

protected:
    virtual void transmitNextDataPage();
    virtual bool isDataPageValid(uint8_t dataPage);

    void transmitMuscleOxygenManufacturerInformationMsg();
    void transmitMuscleOxygenProductInformationMsg();

private:
    void setChannelConfig();
    void transmitMuscleOxygenMainPageMsg();

    uint8_t _patternStep;
    uint8_t _toggle;

    Callback<MuscleOxygenBaseMainDataPageMsg&> _createMuscleOxygenMuscleOxygenDataMsg;
    Callback<ManufacturersInformationMsg&> _createMuscleOxygenManufacturerInformationMsg;
    Callback<ProductInformationMsg&> _createMuscleOxygenProductInformationMsg;
};

#endif // ANTPLUS_PROFILEMUSCLEOXYGENMONITOR_h
