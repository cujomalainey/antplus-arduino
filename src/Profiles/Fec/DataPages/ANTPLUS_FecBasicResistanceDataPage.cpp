#include <Profiles/Fec/DataPages/ANTPLUS_FecBasicResistanceDataPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define POWER_BYTE 7

template<class T>
FecBaseBasicResistanceDataPage<T>::FecBaseBasicResistanceDataPage() :
    CoreDataPage<T>() {}

template<class T>
uint8_t FecBaseBasicResistanceDataPage<T>::getPower() {
    return this->get8BitValue(POWER_BYTE);
}

template class FecBaseBasicResistanceDataPage<BroadcastData>;
template class FecBaseBasicResistanceDataPage<BroadcastDataMsg>;

FecBasicResistanceDataPage::FecBasicResistanceDataPage(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseBasicResistanceDataPage<BroadcastData>() {}

FecBasicResistanceDataMsg::FecBasicResistanceDataMsg() :
    FecBaseMainDataPageMsg(BASIC_RESISTANCE_NUMBER),
    FecBaseBasicResistanceDataPage<BroadcastDataMsg>() {}

void FecBasicResistanceDataMsg::setPower(uint8_t Power) {
    set8BitValue(Power, POWER_BYTE);
}
