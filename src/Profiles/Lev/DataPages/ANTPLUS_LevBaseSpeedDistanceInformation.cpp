#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define ODOMETER_LSB_BYTE           1
#define ODOMETER_MSB_BYTE           3
#define LEVSPEED_LSB_BYTE           6
#define LEVSPEED_MSB_BYTE           7
#define LEVSPEED_MASK               0x0FFF

/* Speed and Distance */
template<class T>
LevCoreSpeedDistanceInformation<T>::LevCoreSpeedDistanceInformation() :
    CoreDataPage<T>() {}

template<class T>
uint32_t LevCoreSpeedDistanceInformation<T>::getOdometer() { // in km
    return this->get32BitValue(ODOMETER_LSB_BYTE, ODOMETER_MSB_BYTE);
}

template<class T>
uint16_t LevCoreSpeedDistanceInformation<T>::getLevSpeed() { // in 1/10 km/h
    return this->get16BitValue(LEVSPEED_LSB_BYTE, LEVSPEED_MSB_BYTE,
            LEVSPEED_MASK);
}

template class LevCoreSpeedDistanceInformation<BroadcastData>;
template class LevCoreSpeedDistanceInformation<BroadcastDataMsg>;

LevBaseSpeedDistanceInformation::LevBaseSpeedDistanceInformation(AntRxDataResponse& dp) :
    LevBaseMainDataPage(dp),
    LevCoreSpeedDistanceInformation<BroadcastData>() {}

LevBaseSpeedDistanceInformationMsg::LevBaseSpeedDistanceInformationMsg(uint8_t dataPageNumber) :
    LevBaseMainDataPageMsg<BroadcastDataMsg>(dataPageNumber),
    LevCoreSpeedDistanceInformation<BroadcastDataMsg>() {}

void LevBaseSpeedDistanceInformationMsg::setOdometer(uint32_t odometer) {
    set32BitValue(odometer, ODOMETER_LSB_BYTE, ODOMETER_MSB_BYTE);
}

void LevBaseSpeedDistanceInformationMsg::setLevSpeed(uint16_t speed) {
    set16BitValue(speed, LEVSPEED_LSB_BYTE, LEVSPEED_MSB_BYTE, LEVSPEED_MASK);
}
