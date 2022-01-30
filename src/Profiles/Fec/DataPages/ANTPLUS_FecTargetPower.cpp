#include <Profiles/Fec/DataPages/ANTPLUS_FecTargetPower.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define TARGET_POWER_LSB_BYTE 6
#define TARGET_POWER_MSB_BYTE 7
#define RESERVED0_LSB_BYTE 1
#define RESERVED0_MSB_BYTE 4
#define RESERVED0_VALUE 0xFFFFFFFF
#define RESERVED1_BYTE 5
#define RESERVED1_VALUE 0xFF

template<class T>
FecBaseTargetPower<T>::FecBaseTargetPower() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseTargetPower<T>::getTargetPower() {
    return this->get16BitValue(TARGET_POWER_LSB_BYTE, TARGET_POWER_MSB_BYTE);
}

template class FecBaseTargetPower<BroadcastData>;
template class FecBaseTargetPower<BroadcastDataMsg>;

FecTargetPower::FecTargetPower(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseTargetPower<BroadcastData>() {}

FecTargetPowerMsg::FecTargetPowerMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_DATAPAGE_TARGETPOWER_NUMBER),
    FecBaseTargetPower<BroadcastDataMsg>() {
    set32BitValue(RESERVED0_VALUE, RESERVED0_LSB_BYTE, RESERVED0_MSB_BYTE);
    set8BitValue(RESERVED1_VALUE, RESERVED1_BYTE);
}

void FecTargetPowerMsg::setTargetPower(uint16_t targetPower) {
    set16BitValue(targetPower, TARGET_POWER_LSB_BYTE, TARGET_POWER_MSB_BYTE);
}
