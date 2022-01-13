#include <Profiles/Fec/DataPages/ANTPLUS_FecUserInformationDataPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define USER_WEIGHT_LSB_BYTE 1
#define USER_WEIGHT_MSB_BYTE 2
#define BICYCLE_WHEEL_BYTE 4
#define BICYCLE_WEIGHT_LSB_BYTE 4
#define BICYCLE_WEIGHT_MSB_BYTE 5

template<class T>
FecBaseUserInformationDatapage<T>::FecBaseUserInformationDatapage() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseUserInformationDatapage<T>::getUserWeight() {
    return this->get16BitValue(USER_WEIGHT_LSB_BYTE, USER_WEIGHT_MSB_BYTE);
}

template<class T>
uint16_t FecBaseUserInformationDatapage<T>::getBikeWeight() {
    return this->get16BitValue(BICYCLE_WEIGHT_LSB_BYTE, BICYCLE_WEIGHT_MSB_BYTE);
}

template class FecBaseUserInformationDatapage<BroadcastData>;
template class FecBaseUserInformationDatapage<BroadcastDataMsg>;

FecUserInformationDatapage::FecUserInformationDatapage(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseUserInformationDatapage<BroadcastData>() {}

FecUserInformationMsg::FecUserInformationMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_USER_INFORMATION_NUMBER),
    FecBaseUserInformationDatapage<BroadcastDataMsg>() {}

void FecUserInformationMsg::setUserWeight(uint16_t UserWeight) {
    set16BitValue(UserWeight, USER_WEIGHT_LSB_BYTE, USER_WEIGHT_MSB_BYTE);
}

void FecUserInformationMsg::setBikeWeight(uint16_t BikeWeight) {
    set16BitValue(BikeWeight, BICYCLE_WEIGHT_LSB_BYTE, BICYCLE_WEIGHT_MSB_BYTE);
}

