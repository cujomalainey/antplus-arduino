#include <CommonDataPages/Base/ANTPLUS_BaseBatteryStatus.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

template<class T>
BaseBatteryStatus<T>::BaseBatteryStatus() : CoreDataPage<T>() {
}

template<class T>
uint8_t BaseBatteryStatus<T>::getNumberOfBatteries() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYIDENTIFIER_NUMBEROFBATTERIES_MASK);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getBatteryIdentifier() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYIDENTIFIER_IDENTIFIER_MASK,
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYIDENTIFIER_IDENTIFIER_SHIFT);
}

template<class T>
uint32_t BaseBatteryStatus<T>::getCumulativeOperatingTime() {
    return this->get24BitValue(
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_CUMULATIVEOPERATINGTIME_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_CUMULATIVEOPERATINGTIME_MSB_BYTE);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getFractionalBatteryVoltage() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_FRACTIONALBATTERYVOLTAGE_BYTE);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getCoarseBatteryVoltage() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_DESCRIPTIVEBITFIELD_BYTE,
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_DESCRIPTIVEBITFIELD_COARSEBATTERYVOLTAGE_MASK);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getBatteryStatus() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_DESCRIPTIVEBITFIELD_BYTE,
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_DESCRIPTIVEBITFIELD_BATTERYSTATUS_MASK,
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_DESCRIPTIVEBITFIELD_BATTERYSTATUS_SHIFT);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getCumulativeOperatingTimeResolution() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_DESCRIPTIVEBITFIELD_BYTE,
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_DESCRIPTIVEBITFIELD_CUMULATIVEOPERATINGTIMERESOLUTION_MASK,
            ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_DESCRIPTIVEBITFIELD_CUMULATIVEOPERATINGTIMERESOLUTION_SHIFT);
}

template class BaseBatteryStatus<BroadcastData>;
template class BaseBatteryStatus<BroadcastDataMsg>;
