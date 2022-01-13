#include <Profiles/MuscleOxygen/DataPages/ANTPLUS_MuscleOxygenMuscleOxygenData.h>
#include <Profiles/MuscleOxygen/ANTPLUS_MuscleOxygenPrivateDefines.h>

#define EVENTCOUNT_BYTE 1
#define NOTIFICATIONS_BYTE 2
#define CAPABILITIES_BYTE 3
#define TOTALHEMOGLOBINCONCENTRATION_LSB_BYTE 4
#define TOTALHEMOGLOBINCONCENTRATION_MSB_BYTE 5
#define TOTALHEMOGLOBINCONCENTRATION_MASK     0x0FFF
#define PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_LSB_BYTE 5
#define PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_MSB_BYTE 6
#define PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_MASK 0x3FF0
#define PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_SHIFT 4
#define CURRENTSATURATEDHEMOGLOBINPERCENTAGE_LSB_BYTE 6
#define CURRENTSATURATEDHEMOGLOBINPERCENTAGE_MSB_BYTE 7
#define CURRENTSATURATEDHEMOGLOBINPERCENTAGE_MASK 0xFFC0
#define CURRENTSATURATEDHEMOGLOBINPERCENTAGE_SHIFT 6

template<class T>
MuscleOxygenBaseMuscleOxygenData<T>::MuscleOxygenBaseMuscleOxygenData() : CoreDataPage<T>() {}

template<class T>
uint8_t MuscleOxygenBaseMuscleOxygenData<T>::getEventCount() {
    return this->get8BitValue(EVENTCOUNT_BYTE);
}

template<class T>
uint8_t MuscleOxygenBaseMuscleOxygenData<T>::getNotifications() {
    return this->get8BitValue(NOTIFICATIONS_BYTE);
}

template<class T>
uint8_t MuscleOxygenBaseMuscleOxygenData<T>::getCapabilities() {
    return this->get8BitValue(CAPABILITIES_BYTE);
}

template<class T>
uint16_t MuscleOxygenBaseMuscleOxygenData<T>::getTotalHemoglobinConcentration() {
    return this->get16BitValue(TOTALHEMOGLOBINCONCENTRATION_LSB_BYTE,
            TOTALHEMOGLOBINCONCENTRATION_MSB_BYTE,
            TOTALHEMOGLOBINCONCENTRATION_MASK);
}

template<class T>
uint16_t MuscleOxygenBaseMuscleOxygenData<T>::getPreviousSaturatedHemoglobinPercentage() {
    return this->get16BitValue(PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_LSB_BYTE,
            PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_MSB_BYTE,
            PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_MASK,
            PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_MASK);
}

template<class T>
uint16_t MuscleOxygenBaseMuscleOxygenData<T>::getCurrentSaturatedHemoglobinPercentage() {
    return this->get16BitValue(CURRENTSATURATEDHEMOGLOBINPERCENTAGE_LSB_BYTE,
            CURRENTSATURATEDHEMOGLOBINPERCENTAGE_MSB_BYTE,
            CURRENTSATURATEDHEMOGLOBINPERCENTAGE_MASK,
            CURRENTSATURATEDHEMOGLOBINPERCENTAGE_SHIFT);
}

MuscleOxygenMuscleOxygenDataMsg::MuscleOxygenMuscleOxygenDataMsg() :
    MuscleOxygenBaseMainDataPageMsg(MUSCLEOXYGEN_MUSCLEOXYGENDATA_NUMBER),
    MuscleOxygenBaseMuscleOxygenData<BroadcastDataMsg>() {
    setTotalHemoglobinConcentration(
            ANTPLUS_MUSCLEOXYGEN_DATAPAGE_MUSCLEOXYGENDATA_TOTALHEMOGLOBINCONCENTRATION_INVALID);
    setPreviousSaturatedHemoglobinPercentage(
            ANTPLUS_MUSCLEOXYGEN_DATAPAGE_MUSCLEOXYGENDATA_PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_INVALID);
    setCurrentSaturatedHemoglobinPercentage(
            ANTPLUS_MUSCLEOXYGEN_DATAPAGE_MUSCLEOXYGENDATA_CURRENTSATURATEDHEMOGLOBINPERCENTAGE_INVALID);
}

void MuscleOxygenMuscleOxygenDataMsg::setEventCount(uint8_t n) {
    set8BitValue(n, EVENTCOUNT_BYTE);
}

void MuscleOxygenMuscleOxygenDataMsg::setNotifications(uint8_t notifications) {
    set8BitValue(notifications, NOTIFICATIONS_BYTE);
}

void MuscleOxygenMuscleOxygenDataMsg::setCapabilities(uint8_t capabilities) {
    set8BitValue(capabilities, CAPABILITIES_BYTE);
}

void MuscleOxygenMuscleOxygenDataMsg::setTotalHemoglobinConcentration(uint16_t concentration) {
    set16BitValue(concentration, TOTALHEMOGLOBINCONCENTRATION_LSB_BYTE,
            TOTALHEMOGLOBINCONCENTRATION_MSB_BYTE,
            TOTALHEMOGLOBINCONCENTRATION_MASK);
}

void MuscleOxygenMuscleOxygenDataMsg::setPreviousSaturatedHemoglobinPercentage(uint16_t percent) {
    set16BitValue(percent, PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_LSB_BYTE,
            PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_MSB_BYTE,
            PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_MASK,
            PREVIOUSSATURATEDHEMOGLOBINPERCENTAGE_SHIFT);
}

void MuscleOxygenMuscleOxygenDataMsg::setCurrentSaturatedHemoglobinPercentage(uint16_t percent) {
    set16BitValue(percent, CURRENTSATURATEDHEMOGLOBINPERCENTAGE_LSB_BYTE,
            CURRENTSATURATEDHEMOGLOBINPERCENTAGE_MSB_BYTE,
            CURRENTSATURATEDHEMOGLOBINPERCENTAGE_MASK,
            CURRENTSATURATEDHEMOGLOBINPERCENTAGE_SHIFT);
}
