#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevCapabilities.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

LevCapabilities::LevCapabilities(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
    return;
}

uint8_t LevCapabilities::getTravelModesSupported() {
    return getData(2);
}

uint16_t LevCapabilities::getWheelCircumference() {
    return (uint16_t)getData(3) + (((uint16_t)getData(4) & 0x0F) << 8);
}
