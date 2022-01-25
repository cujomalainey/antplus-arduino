#include <Profiles/Fec/DataPages/ANTPLUS_FecBasicResistance.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define TOTAL_RESISTANCE_BYTE 7

template<class T>
FecBaseBasicResistance<T>::FecBaseBasicResistance() :
    CoreDataPage<T>() {}

template<class T>
uint8_t FecBaseBasicResistance<T>::getTotalResistance() {
    return this->get8BitValue(TOTAL_RESISTANCE_BYTE);
}

template class FecBaseBasicResistance<BroadcastData>;
template class FecBaseBasicResistance<BroadcastDataMsg>;

FecBasicResistance::FecBasicResistance(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseBasicResistance<BroadcastData>() {}

FecBasicResistanceMsg::FecBasicResistanceMsg() :
    FecBaseMainDataPageMsg(BASIC_RESISTANCE_NUMBER),
    FecBaseBasicResistance<BroadcastDataMsg>() {}
    // TODO reserved fields

void FecBasicResistanceMsg::setTotalResistance(uint8_t total_resistance) {
    set8BitValue(total_resistance, TOTAL_RESISTANCE_BYTE);
}
