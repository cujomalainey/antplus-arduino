#include <Profiles/Lev/DataPages/ANTPLUS_LevSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

/* Speed and Distance */
LevSpeedDistanceInformation::LevSpeedDistanceInformation(AntRxDataResponse& dp) :
    LevBaseSpeedDistanceInformation(dp) {}

uint16_t LevSpeedDistanceInformation::getRemainingRange() { // in km
    return (uint16_t)getData(ANTPLUS_LEV_DATAPAGE_SPEEDDISTANCEINFORMATION_REMAININGRANGE_LSB_BYTE) + (((uint16_t)getData(ANTPLUS_LEV_DATAPAGE_SPEEDDISTANCEINFORMATION_REMAININGRANGE_MSB_BYTE) & ANTPLUS_LEV_DATAPAGE_SPEEDDISTANCEINFORMATION_REMAININGRANGE_MSB_MASK) << ANTPLUS_LEV_DATAPAGE_SPEEDDISTANCEINFORMATION_REMAININGRANGE_MSB_SHIFT);
}
