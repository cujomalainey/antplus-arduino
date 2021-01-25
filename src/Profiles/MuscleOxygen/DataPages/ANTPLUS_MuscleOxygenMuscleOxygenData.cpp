#include <Profiles/MuscleOxygen/DataPages/ANTPLUS_MuscleOxygenMuscleOxygenData.h>
#include <Profiles/MuscleOxygen/ANTPLUS_MuscleOxygenPrivateDefines.h>

// TODO Magic numbers
template<class T>
MuscleOxygenBaseMuscleOxygenData<T>::MuscleOxygenBaseMuscleOxygenData() : CoreDataPage<T>() {}

template<class T>
uint8_t MuscleOxygenBaseMuscleOxygenData<T>::getEventCount() {
    return this->get8BitValue(1);
}

template<class T>
uint8_t MuscleOxygenBaseMuscleOxygenData<T>::getNotifications() {
    return this->get8BitValue(2);
}

template<class T>
uint8_t MuscleOxygenBaseMuscleOxygenData<T>::getCapabilities() {
    return this->get8BitValue(3);
}

template<class T>
uint16_t MuscleOxygenBaseMuscleOxygenData<T>::getTotalHemoglobinConcentration() {
    return this->get16BitValue(4, 5, 0x0FFF);
}

template<class T>
uint16_t MuscleOxygenBaseMuscleOxygenData<T>::getPreviousSaturatedHemoglobinPercentage() {
    return this->get16BitValue(5, 6, 0x3FF0, 4);
}

template<class T>
uint16_t MuscleOxygenBaseMuscleOxygenData<T>::getCurrentSaturatedHemoglobinPercentage() {
    return this->get16BitValue(6, 7, 0xFFC0, 6);
}

// TODO magic numbers
MuscleOxygenMuscleOxygenDataMsg::MuscleOxygenMuscleOxygenDataMsg() :
    MuscleOxygenBaseMainDataPageMsg(0),
    MuscleOxygenBaseMuscleOxygenData<BroadcastDataMsg>() {
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
