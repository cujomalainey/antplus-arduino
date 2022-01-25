#include <Profiles/Fec/DataPages/ANTPLUS_FecTargetPowerDataPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define TARGET_POWER_LSB_BYTE 6
#define TARGET_POWER_MSB_BYTE 7

template<class T>
FecBaseTargetPowerDataPage<T>::FecBaseTargetPowerDataPage() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseTargetPowerDataPage<T>::getTargetPower() {
    return this->get16BitValue(TARGET_POWER_LSB_BYTE, TARGET_POWER_MSB_BYTE);
}

template class FecBaseTargetPowerDataPage<BroadcastData>;
template class FecBaseTargetPowerDataPage<BroadcastDataMsg>;

FecTargetPowerDataPage::FecTargetPowerDataPage(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseTargetPowerDataPage<BroadcastData>() {}

FecTargetPowerDataMsg::FecTargetPowerDataMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_TARGET_POWER_NUMBER),
    FecBaseTargetPowerDataPage<BroadcastDataMsg>() {}

void FecTargetPowerDataMsg::setTargetPower(uint16_t TargetPower) {
    set16BitValue(TargetPower, TARGET_POWER_LSB_BYTE, TARGET_POWER_MSB_BYTE);
}
