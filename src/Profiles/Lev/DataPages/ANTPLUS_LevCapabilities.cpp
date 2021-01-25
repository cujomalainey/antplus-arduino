#include <Profiles/Lev/DataPages/ANTPLUS_LevCapabilities.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define TRAVELMODESSUPPORTED_BYTE                         2
#define TRAVELMODESSUPPORTED_NUMBERASSISTMODES_MASK       0x38
#define TRAVELMODESSUPPORTED_NUMBERASSISTMODES_SHIFT      3
#define TRAVELMODESSUPPORTED_NUMBERREGENERATIVEMODES_MASK 0x7
#define WHEELCIRCUMFERENCE_LSB_BYTE                       3
#define WHEELCIRCUMFERENCE_MSB_BYTE                       4
#define WHEELCIRCUMFERENCE_MASK                           0xF

LevCapabilities::LevCapabilities(AntRxDataResponse& dp) :
    LevBaseMainDataPage(dp) {}

uint8_t LevCapabilities::getNumberOfAssistModesSupported() {
    return this->get8BitValue(TRAVELMODESSUPPORTED_BYTE,
            TRAVELMODESSUPPORTED_NUMBERASSISTMODES_MASK,
            TRAVELMODESSUPPORTED_NUMBERASSISTMODES_SHIFT);
}

uint8_t LevCapabilities::getNumberOfRegenerativeModesSupported() {
    return this->get8BitValue(TRAVELMODESSUPPORTED_BYTE,
            TRAVELMODESSUPPORTED_NUMBERREGENERATIVEMODES_MASK);
}

uint16_t LevCapabilities::getWheelCircumference() {
    return this->get16BitValue(WHEELCIRCUMFERENCE_LSB_BYTE,
            WHEELCIRCUMFERENCE_MSB_BYTE, WHEELCIRCUMFERENCE_MASK);
}
