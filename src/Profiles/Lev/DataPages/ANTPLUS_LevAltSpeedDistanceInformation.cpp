#include <Profiles/Lev/DataPages/ANTPLUS_LevAltSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

/* Alt Speed and Distance */
LevAltSpeedDistanceInformation::LevAltSpeedDistanceInformation(AntRxDataResponse& dp) :
    LevBaseSpeedDistanceInformation(dp) {}

uint16_t LevAltSpeedDistanceInformation::getFuelConsumption() // in Wh/km
{
    return (uint16_t)getData(ANTPLUS_LEV_DATAPAGE_SPEEDDISTANCEINFORMATION_FUELCONSUMPTION_LSB_BYTE) + (((uint16_t)getData(ANTPLUS_LEV_DATAPAGE_SPEEDDISTANCEINFORMATION_FUELCONSUMPTION_MSB_BYTE) & ANTPLUS_LEV_DATAPAGE_SPEEDDISTANCEINFORMATION_FUELCONSUMPTION_MSB_MASK) << ANTPLUS_LEV_DATAPAGE_SPEEDDISTANCEINFORMATION_FUELCONSUMPTION_MSB_SHIFT);
}

