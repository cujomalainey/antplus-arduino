#include <Profiles/MuscleOxygen/DataPages/TX/ANTPLUS_MuscleOxygenMuscleOxygenDataMsg.h>
#include <Profiles/MuscleOxygen/ANTPLUS_MuscleOxygenPrivateDefines.h>


MuscleOxygenMuscleOxygenDataMsg::MuscleOxygenMuscleOxygenDataMsg() : MuscleOxygenBaseMainDataPageMsg(0) {
    setTotalHemoglobinConcentration(0xFFF);
    setPreviousSaturatedHemoglobinPercentage(0x3FF);
    setCurrentSaturatedHemoglobinPercentage(0x3FF);
}

void MuscleOxygenMuscleOxygenDataMsg::setEventCount(uint8_t n) {
    set8BitValue(n, 1);
}

void MuscleOxygenMuscleOxygenDataMsg::setNotifications(uint8_t notifications) {
    set8BitValue(notifications, 2);
}

void MuscleOxygenMuscleOxygenDataMsg::setCapabilities(uint8_t capabilities) {
    set8BitValue(capabilities, 3);
}

void MuscleOxygenMuscleOxygenDataMsg::setTotalHemoglobinConcentration(uint16_t concentration) {
    set16BitValue(concentration, 4, 5, 0x0FFF);
}

void MuscleOxygenMuscleOxygenDataMsg::setPreviousSaturatedHemoglobinPercentage(uint16_t percent) {
    set16BitValue(percent, 5, 6, 0x3FF0, 4);
}

void MuscleOxygenMuscleOxygenDataMsg::setCurrentSaturatedHemoglobinPercentage(uint16_t percent) {
    set16BitValue(percent, 6, 7, 0xFFC0, 6);
}
