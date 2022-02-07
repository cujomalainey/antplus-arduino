#include <Profiles/Fec/DataPages/ANTPLUS_FecFeCapabilities.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define MAXIMUM_RESISTANCE_LSB_BYTE 5
#define MAXIMUM_RESISTANCE_MSB_BYTE 6
#define BASICRESISTANCEMODESUPPORT_BYTE 7
#define BASICRESISTANCEMODESUPPORT_MASK 0x1
#define TARGETPOWERMODESUPPORT_BYTE 7
#define TARGETPOWERMODESUPPORT_MASK 0x2
#define TARGETPOWERMODESUPPORT_SHIFT 1
#define SIMULATIONMODESUPPORT_BYTE 7
#define SIMULATIONMODESUPPORT_MASK 0x4
#define SIMULATIONMODESUPPORT_SHIFT 2
#define RESERVED_LSB_BYTE 1
#define RESERVED_MSB_BYTE 4
#define RESERVED_VALUE 0xFFFFFFFF

template<class T>
FecBaseFeCapabilities<T>::FecBaseFeCapabilities() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseFeCapabilities<T>::getMaximumResistance() {
    return this->get16BitValue(MAXIMUM_RESISTANCE_LSB_BYTE, MAXIMUM_RESISTANCE_MSB_BYTE);
}

template<class T>
uint8_t FecBaseFeCapabilities<T>::getBasicResistanceModeSupport() {
    return this->get8BitValue(BASICRESISTANCEMODESUPPORT_BYTE, BASICRESISTANCEMODESUPPORT_MASK);
}

template<class T>
uint8_t FecBaseFeCapabilities<T>::getTargetPowerModeSupport() {
    return this->get8BitValue(TARGETPOWERMODESUPPORT_BYTE,
            TARGETPOWERMODESUPPORT_MASK,
            TARGETPOWERMODESUPPORT_SHIFT);
}

template<class T>
uint8_t FecBaseFeCapabilities<T>::getSimulationModeSupport() {
    return this->get8BitValue(SIMULATIONMODESUPPORT_BYTE,
            SIMULATIONMODESUPPORT_MASK,
            SIMULATIONMODESUPPORT_SHIFT);
}

template class FecBaseFeCapabilities<BroadcastData>;
template class FecBaseFeCapabilities<BroadcastDataMsg>;

FecFeCapabilities::FecFeCapabilities(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseFeCapabilities<BroadcastData>() {}

FecFeCapabilitiesMsg::FecFeCapabilitiesMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_DATAPAGE_FECAPABILITIES_NUMBER),
    FecBaseFeCapabilities<BroadcastDataMsg>() {
    this->set32BitValue(RESERVED_VALUE, RESERVED_LSB_BYTE, RESERVED_MSB_BYTE);
    setMaximumResistance(ANTPLUS_FEC_DATAPAGE_FECAPABILITIES_MAXIMUM_RESISTANCE_INVALID);
}

void FecFeCapabilitiesMsg::setMaximumResistance(uint16_t maximumResistance) {
    set16BitValue(maximumResistance, MAXIMUM_RESISTANCE_LSB_BYTE, MAXIMUM_RESISTANCE_MSB_BYTE);
}

void FecFeCapabilitiesMsg::setBasicResistanceModeSupport(uint8_t support) {
    set8BitValue(support, BASICRESISTANCEMODESUPPORT_BYTE, BASICRESISTANCEMODESUPPORT_MASK);
}

void FecFeCapabilitiesMsg::setTargetPowerModeSupport(uint8_t support) {
    set8BitValue(support,
            TARGETPOWERMODESUPPORT_BYTE,
            TARGETPOWERMODESUPPORT_MASK,
            TARGETPOWERMODESUPPORT_SHIFT);
}

void FecFeCapabilitiesMsg::setSimulationModeSupport(uint8_t support) {
    set8BitValue(support,
            SIMULATIONMODESUPPORT_BYTE,
            SIMULATIONMODESUPPORT_MASK,
            SIMULATIONMODESUPPORT_SHIFT);
}
