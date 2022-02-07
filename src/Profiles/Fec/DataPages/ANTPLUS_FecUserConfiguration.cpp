#include <Profiles/Fec/DataPages/ANTPLUS_FecUserConfiguration.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define USERWEIGHT_LSB_BYTE 1
#define USERWEIGHT_MSB_BYTE 2
#define RESERVED_BYTE 3
#define RESERVED_VALUE 0xFF
#define BICYCLEWHEELDIAMETEROFFSET_BYTE 4
#define BICYCLEWHEELDIAMETEROFFSET_MASK 0x0F
#define BICYCLEWEIGHT_LSB_BYTE 4
#define BICYCLEWEIGHT_MSB_BYTE 5
#define BICYCLEWEIGHT_MASK 0xFFF0
#define BICYCLEWEIGHT_SHIFT 4
#define BICYCLEWHEELDIAMETER_BYTE 6
#define GEARRATIO_BYTE 7

template<class T>
FecBaseUserConfiguration<T>::FecBaseUserConfiguration() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseUserConfiguration<T>::getUserWeight() {
    return this->get16BitValue(USERWEIGHT_LSB_BYTE, USERWEIGHT_MSB_BYTE);
}

template<class T>
uint8_t FecBaseUserConfiguration<T>::getBicycleWheelDiameterOffset() {
    return this->get8BitValue(BICYCLEWHEELDIAMETEROFFSET_BYTE, BICYCLEWHEELDIAMETEROFFSET_MASK);
}

template<class T>
uint16_t FecBaseUserConfiguration<T>::getBicycleWeight() {
    return this->get16BitValue(BICYCLEWEIGHT_LSB_BYTE,
            BICYCLEWEIGHT_MSB_BYTE,
            BICYCLEWEIGHT_MASK,
            BICYCLEWEIGHT_SHIFT);
}

template<class T>
uint8_t FecBaseUserConfiguration<T>::getBicycleWheelDiameter() {
    return this->get8BitValue(BICYCLEWHEELDIAMETER_BYTE);
}

template<class T>
uint8_t FecBaseUserConfiguration<T>::getGearRatio() {
    return this->get8BitValue(GEARRATIO_BYTE);
}

template class FecBaseUserConfiguration<BroadcastData>;
template class FecBaseUserConfiguration<BroadcastDataMsg>;

FecUserConfiguration::FecUserConfiguration(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseUserConfiguration<BroadcastData>() {}

FecUserConfigurationMsg::FecUserConfigurationMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_DATAPAGE_USERCONFIGURATION_NUMBER),
    FecBaseUserConfiguration<BroadcastDataMsg>() {
    setUserWeight(ANTPLUS_FEC_DATAPAGE_USERCONFIGURATION_USERWEIGHT_INVALID);
    set8BitValue(RESERVED_VALUE, RESERVED_BYTE);
    setBicycleWheelDiameterOffset(ANTPLUS_FEC_DATAPAGE_USERCONFIGURATION_BICYCLEWHEELDIAMETEROFFSET_INVALID);
    setBicycleWeight(ANTPLUS_FEC_DATAPAGE_USERCONFIGURATION_BICYCLEWEIGHT_INVALID);
    setBicycleWheelDiameter(ANTPLUS_FEC_DATAPAGE_USERCONFIGURATION_BICYCLEWHEELDIAMETER_INVALID);
    setGearRatio(ANTPLUS_FEC_DATAPAGE_USERCONFIGURATION_GEARRATIO_INVALID);
}

void FecUserConfigurationMsg::setBicycleWheelDiameterOffset(uint8_t offset) {
     set8BitValue(offset, BICYCLEWHEELDIAMETEROFFSET_BYTE, BICYCLEWHEELDIAMETEROFFSET_MASK);
}

void FecUserConfigurationMsg::setUserWeight(uint16_t userWeight) {
    set16BitValue(userWeight, USERWEIGHT_LSB_BYTE, USERWEIGHT_MSB_BYTE);
}

void FecUserConfigurationMsg::setBicycleWeight(uint16_t bicycleWeight) {
    set16BitValue(bicycleWeight,
            BICYCLEWEIGHT_LSB_BYTE,
            BICYCLEWEIGHT_MSB_BYTE,
            BICYCLEWEIGHT_MASK,
            BICYCLEWEIGHT_SHIFT);
}

void FecUserConfigurationMsg::setBicycleWheelDiameter(uint8_t diameter) {
    set8BitValue(diameter, BICYCLEWHEELDIAMETER_BYTE);
}

void FecUserConfigurationMsg::setGearRatio(uint8_t gearRatio) {
    set8BitValue(gearRatio, GEARRATIO_BYTE);
}
