#include <Profiles/Fec/DataPages/ANTPLUS_FecGeneralMainDataPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO this is a mixture of datapages
#define EQUIPMENTTYPEBITS_BYTE 1
#define ELAPSEDTIME_BYTE 2
#define DISTANCETRAVELED_BYTE 3
#define SPEED_LSB_BYTE 4
#define SPEED_MSB_BYTE 5
#define HEARTRATE_BYTE 6
#define CAPABILITIESBITFIELD_BYTE 7
#define CAPABILITIESBITFIELD_MASK 0x0F
#define FESTATEBITFIELD_BYTE  7
#define FESTATEBITFIELD_MASK  0xF0
#define FESTATEBITFIELD_SHIFT 4

template<class T>
FecBaseGeneralMainDataPage<T>::FecBaseGeneralMainDataPage() :
    CoreDataPage<T>() {}

template<class T>
uint8_t FecBaseGeneralMainDataPage<T>::getEquipmentTypeBits() {
    return this->get8BitValue(EQUIPMENTTYPEBITS_BYTE);
}

template<class T>
uint8_t FecBaseGeneralMainDataPage<T>::getElapsedTime() {
    return this->get8BitValue(ELAPSEDTIME_BYTE);
}

template<class T>
uint8_t FecBaseGeneralMainDataPage<T>::getDistanceTraveled() {
    return this->get8BitValue(DISTANCETRAVELED_BYTE);
}

template<class T>
uint8_t FecBaseGeneralMainDataPage<T>::getHeartRate() {
    return this->get8BitValue(HEARTRATE_BYTE);
}

template<class T>
uint8_t FecBaseGeneralMainDataPage<T>::getCapabilitiesBits() {
    return this->get8BitValue(CAPABILITIESBITFIELD_BYTE,
            CAPABILITIESBITFIELD_MASK);
}

template<class T>
uint8_t FecBaseGeneralMainDataPage<T>::getFEStateBits() {
    return this->get8BitValue(FESTATEBITFIELD_BYTE, FESTATEBITFIELD_MASK,
            FESTATEBITFIELD_SHIFT);
}

template<class T>
/*

in meter / s

*/
uint16_t FecBaseGeneralMainDataPage<T>::getSpeed(bool km) {
    if ( km == true ){
        return 3.6 * (this->get16BitValue(SPEED_LSB_BYTE, SPEED_MSB_BYTE)) /1000;
    }
    return this->get16BitValue(SPEED_LSB_BYTE, SPEED_MSB_BYTE);
}

template class FecBaseGeneralMainDataPage<BroadcastData>;
template class FecBaseGeneralMainDataPage<BroadcastDataMsg>;

FecGeneralMainDataPage::FecGeneralMainDataPage(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseGeneralMainDataPage<BroadcastData>() {}

FecGeneralMainDataMsg::FecGeneralMainDataMsg() :
    FecBaseMainDataPageMsg(GENERAL_FE_DATA_NUMBER),
    FecBaseGeneralMainDataPage<BroadcastDataMsg>() {}
