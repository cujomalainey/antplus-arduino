#include <Profiles/Lev/DataPages/ANTPLUS_LevAltSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevDefines.h>

#define FUELCONSUMPTION_LSB_BYTE  4
#define FUELCONSUMPTION_MSB_BYTE  5
#define FUELCONSUMPTION_MASK      0x0FFF

/* Alt Speed and Distance */
template<class T>
LevBaseAltSpeedDistanceInformation<T>::LevBaseAltSpeedDistanceInformation() :
    CoreDataPage<T>() {}

template<class T>
uint16_t LevBaseAltSpeedDistanceInformation<T>::getFuelConsumption() // in Wh/km
{
    return this->get16BitValue(FUELCONSUMPTION_LSB_BYTE,
            FUELCONSUMPTION_MSB_BYTE, FUELCONSUMPTION_MASK);
}

template class LevBaseAltSpeedDistanceInformation<BroadcastData>;
template class LevBaseAltSpeedDistanceInformation<BroadcastDataMsg>;

LevAltSpeedDistanceInformation::LevAltSpeedDistanceInformation(AntRxDataResponse& dp) :
    LevBaseSpeedDistanceInformation(dp),
    LevBaseAltSpeedDistanceInformation<BroadcastData>() {}

LevAltSpeedDistanceInformationMsg::LevAltSpeedDistanceInformationMsg() :
    LevBaseSpeedDistanceInformationMsg(ANTPLUS_LEV_DATAPAGE_ALTSPEEDDISTANCEINFORMATION_NUMBER),
    LevBaseAltSpeedDistanceInformation<BroadcastDataMsg>() {}

void LevAltSpeedDistanceInformationMsg::setFuelConsumption(uint16_t consumption) // in Wh/km
{
    set16BitValue(consumption, FUELCONSUMPTION_LSB_BYTE,
            FUELCONSUMPTION_MSB_BYTE, FUELCONSUMPTION_MASK);
}
