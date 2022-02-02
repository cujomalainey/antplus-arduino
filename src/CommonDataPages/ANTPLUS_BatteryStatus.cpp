#include <CommonDataPages/ANTPLUS_BatteryStatus.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define RESERVED_BYTE 1
#define RESERVED_VALUE 0xFF
#define BATTERYIDENTIFIER_BYTE 2
#define BATTERYIDENTIFIER_NUMBEROFBATTERIES_MASK 0x0F
#define BATTERYIDENTIFIER_IDENTIFIER_MASK 0xF0
#define BATTERYIDENTIFIER_IDENTIFIER_SHIFT 4
#define CUMULATIVEOPERATINGTIME_LSB_BYTE 3
#define CUMULATIVEOPERATINGTIME_MSB_BYTE 5
#define FRACTIONALBATTERYVOLTAGE_BYTE 6
#define DESCRIPTIVEBITFIELD_BYTE 7
#define DESCRIPTIVEBITFIELD_COARSEBATTERYVOLTAGE_MASK 0x0F
#define DESCRIPTIVEBITFIELD_BATTERYSTATUS_MASK 0x70
#define DESCRIPTIVEBITFIELD_BATTERYSTATUS_SHIFT 4
#define DESCRIPTIVEBITFIELD_CUMULATIVEOPERATINGTIMERESOLUTION_MASK 0x80
#define DESCRIPTIVEBITFIELD_CUMULATIVEOPERATINGTIMERESOLUTION_SHIFT 7


template<class T>
BaseBatteryStatus<T>::BaseBatteryStatus() : CoreDataPage<T>() {}

template<class T>
uint8_t BaseBatteryStatus<T>::getNumberOfBatteries() {
    return this->get8BitValue(BATTERYIDENTIFIER_BYTE,
            BATTERYIDENTIFIER_NUMBEROFBATTERIES_MASK);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getBatteryIdentifier() {
    return this->get8BitValue(BATTERYIDENTIFIER_BYTE,
            BATTERYIDENTIFIER_IDENTIFIER_MASK,
            BATTERYIDENTIFIER_IDENTIFIER_SHIFT);
}

template<class T>
uint32_t BaseBatteryStatus<T>::getCumulativeOperatingTime() {
    return this->get24BitValue(CUMULATIVEOPERATINGTIME_LSB_BYTE,
            CUMULATIVEOPERATINGTIME_MSB_BYTE);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getFractionalBatteryVoltage() {
    return this->get8BitValue(FRACTIONALBATTERYVOLTAGE_BYTE);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getCoarseBatteryVoltage() {
    return this->get8BitValue(DESCRIPTIVEBITFIELD_BYTE,
            DESCRIPTIVEBITFIELD_COARSEBATTERYVOLTAGE_MASK);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getBatteryStatus() {
    return this->get8BitValue(DESCRIPTIVEBITFIELD_BYTE,
            DESCRIPTIVEBITFIELD_BATTERYSTATUS_MASK,
            DESCRIPTIVEBITFIELD_BATTERYSTATUS_SHIFT);
}

template<class T>
uint8_t BaseBatteryStatus<T>::getCumulativeOperatingTimeResolution() {
    return this->get8BitValue(DESCRIPTIVEBITFIELD_BYTE,
            DESCRIPTIVEBITFIELD_CUMULATIVEOPERATINGTIMERESOLUTION_MASK,
            DESCRIPTIVEBITFIELD_CUMULATIVEOPERATINGTIMERESOLUTION_SHIFT);
}

template class BaseBatteryStatus<BroadcastData>;
template class BaseBatteryStatus<BroadcastDataMsg>;

BatteryStatus::BatteryStatus(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    BaseBatteryStatus<BroadcastData>() {}

BatteryStatusMsg::BatteryStatusMsg() :
    BaseDataPageMsg<BroadcastDataMsg>(),
    BaseBatteryStatus<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_NUMBER, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
    set8BitValue(RESERVED_VALUE, RESERVED_BYTE);
}

void BatteryStatusMsg::setNumberOfBatteries(uint8_t num) {
    set8BitValue(num, BATTERYIDENTIFIER_BYTE,
            BATTERYIDENTIFIER_NUMBEROFBATTERIES_MASK);
}

void BatteryStatusMsg::setBatteryIdentifier(uint8_t id) {
    set8BitValue(id, BATTERYIDENTIFIER_BYTE, BATTERYIDENTIFIER_IDENTIFIER_MASK,
            BATTERYIDENTIFIER_IDENTIFIER_SHIFT);
}

void BatteryStatusMsg::setCumulativeOperatingTime(uint32_t time) {
    set24BitValue(time, CUMULATIVEOPERATINGTIME_LSB_BYTE,
            CUMULATIVEOPERATINGTIME_MSB_BYTE);
}

void BatteryStatusMsg::setFractionalBatteryVoltage(uint8_t voltage) {
    set8BitValue(voltage, FRACTIONALBATTERYVOLTAGE_BYTE);
}

void BatteryStatusMsg::setCoarseBatteryVoltage(uint8_t voltage) {
    set8BitValue(voltage, DESCRIPTIVEBITFIELD_BYTE,
            DESCRIPTIVEBITFIELD_COARSEBATTERYVOLTAGE_MASK);
}

void BatteryStatusMsg::setBatteryStatus(uint8_t status) {
    set8BitValue(status, DESCRIPTIVEBITFIELD_BYTE,
            DESCRIPTIVEBITFIELD_BATTERYSTATUS_MASK,
            DESCRIPTIVEBITFIELD_BATTERYSTATUS_SHIFT);
}

void BatteryStatusMsg::setCumulativeOperatingTimeResolution(uint8_t resolution) {
    set8BitValue(resolution, DESCRIPTIVEBITFIELD_BYTE,
            DESCRIPTIVEBITFIELD_CUMULATIVEOPERATINGTIMERESOLUTION_MASK,
            DESCRIPTIVEBITFIELD_CUMULATIVEOPERATINGTIMERESOLUTION_SHIFT);
}
