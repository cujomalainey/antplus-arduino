#include <Profiles/Lev/DataPages/ANTPLUS_LevCapabilities.h>
#include <Profiles/Lev/ANTPLUS_LevDefines.h>

#define TRAVELMODESSUPPORTED_BYTE                         2
#define TRAVELMODESSUPPORTED_NUMBERASSISTMODES_MASK       0x38
#define TRAVELMODESSUPPORTED_NUMBERASSISTMODES_SHIFT      3
#define TRAVELMODESSUPPORTED_NUMBERREGENERATIVEMODES_MASK 0x7
#define WHEELCIRCUMFERENCE_LSB_BYTE                       3
#define WHEELCIRCUMFERENCE_MSB_BYTE                       4
#define WHEELCIRCUMFERENCE_MASK                           0xF

template<class T>
LevBaseCapabilities<T>::LevBaseCapabilities() : CoreDataPage<T>() {}

template<class T>
uint8_t LevBaseCapabilities<T>::getNumberOfAssistModesSupported() {
    return this->get8BitValue(TRAVELMODESSUPPORTED_BYTE,
            TRAVELMODESSUPPORTED_NUMBERASSISTMODES_MASK,
            TRAVELMODESSUPPORTED_NUMBERASSISTMODES_SHIFT);
}

template<class T>
uint8_t LevBaseCapabilities<T>::getNumberOfRegenerativeModesSupported() {
    return this->get8BitValue(TRAVELMODESSUPPORTED_BYTE,
            TRAVELMODESSUPPORTED_NUMBERREGENERATIVEMODES_MASK);
}

template<class T>
uint16_t LevBaseCapabilities<T>::getWheelCircumference() {
    return this->get16BitValue(WHEELCIRCUMFERENCE_LSB_BYTE,
            WHEELCIRCUMFERENCE_MSB_BYTE, WHEELCIRCUMFERENCE_MASK);
}

template class LevBaseCapabilities<BroadcastData>;
template class LevBaseCapabilities<BroadcastDataMsg>;

LevCapabilities::LevCapabilities(AntRxDataResponse& dp) :
    LevBaseMainDataPage(dp), LevBaseCapabilities<BroadcastData>() {}

LevCapabilitiesMsg::LevCapabilitiesMsg() :
    LevBaseMainDataPageMsg<BroadcastDataMsg>(ANTPLUS_LEV_DATAPAGE_LEVCAPABILITIES_NUMBER),
    LevBaseCapabilities<BroadcastDataMsg>() {}

void LevCapabilitiesMsg::setNumberOfAssistModesSupported(uint8_t modes) {
    set8BitValue(modes, TRAVELMODESSUPPORTED_BYTE,
            TRAVELMODESSUPPORTED_NUMBERASSISTMODES_MASK,
            TRAVELMODESSUPPORTED_NUMBERASSISTMODES_SHIFT);
}

void LevCapabilitiesMsg::setNumberOfRegenerativeModesSupported(uint8_t modes) {
    set8BitValue(modes, TRAVELMODESSUPPORTED_BYTE,
            TRAVELMODESSUPPORTED_NUMBERREGENERATIVEMODES_MASK);
}

void LevCapabilitiesMsg::setWheelCircumference(uint16_t circumference) {
    set16BitValue(circumference, WHEELCIRCUMFERENCE_LSB_BYTE,
            WHEELCIRCUMFERENCE_MSB_BYTE, WHEELCIRCUMFERENCE_MASK);
}
