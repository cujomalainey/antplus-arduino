#include <Profiles/MuscleOxygen/DataPages/Base/ANTPLUS_MuscleOxygenBaseMuscleOxygenData.h>

// TODO Magic numbers
template<class T>
MuscleOxygenBaseMuscleOxygenData<T>::MuscleOxygenBaseMuscleOxygenData() {
}

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
