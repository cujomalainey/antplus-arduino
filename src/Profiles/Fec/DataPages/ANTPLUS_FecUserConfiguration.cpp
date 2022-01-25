#include <Profiles/Fec/DataPages/ANTPLUS_FecUserConfiguration.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define USER_WEIGHT_LSB_BYTE 1
#define USER_WEIGHT_MSB_BYTE 2
#define BICYCLE_WEIGHT_LSB_BYTE 4
#define BICYCLE_WEIGHT_MSB_BYTE 5

template<class T>
FecBaseUserConfiguration<T>::FecBaseUserConfiguration() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseUserConfiguration<T>::getUserWeight() {
    return this->get16BitValue(USER_WEIGHT_LSB_BYTE, USER_WEIGHT_MSB_BYTE);
}

template<class T>
uint16_t FecBaseUserConfiguration<T>::getBikeWeight() {
    return this->get16BitValue(BICYCLE_WEIGHT_LSB_BYTE, BICYCLE_WEIGHT_MSB_BYTE);
}

template class FecBaseUserConfiguration<BroadcastData>;
template class FecBaseUserConfiguration<BroadcastDataMsg>;

FecUserConfiguration::FecUserConfiguration(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseUserConfiguration<BroadcastData>() {}

FecUserConfigurationMsg::FecUserConfigurationMsg() :
    FecBaseMainDataPageMsg(USER_CONFIGURATION_NUMBER),
    FecBaseUserConfiguration<BroadcastDataMsg>() {}

void FecUserConfigurationMsg::setUserWeight(uint16_t UserWeight) {
    set16BitValue(UserWeight, USER_WEIGHT_LSB_BYTE, USER_WEIGHT_MSB_BYTE);
}

void FecUserConfigurationMsg::setBikeWeight(uint16_t BikeWeight) {
    set16BitValue(BikeWeight, BICYCLE_WEIGHT_LSB_BYTE, BICYCLE_WEIGHT_MSB_BYTE);
}

