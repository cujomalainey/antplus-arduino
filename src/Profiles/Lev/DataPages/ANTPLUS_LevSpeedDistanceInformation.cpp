#include <Profiles/Lev/DataPages/ANTPLUS_LevSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define REMAININGRANGE_LSB_BYTE  4
#define REMAININGRANGE_MSB_BYTE  5
#define REMAININGRANGE_MASK      0x0FFF

/* Speed and Distance */
template<class T>
LevInternalSpeedDistanceInformation<T>::LevInternalSpeedDistanceInformation() :
    CoreDataPage<T>() {}

template<class T>
uint16_t LevInternalSpeedDistanceInformation<T>::getRemainingRange() { // in km
    return this->get16BitValue(REMAININGRANGE_LSB_BYTE, REMAININGRANGE_MSB_BYTE,
            REMAININGRANGE_MASK);
}

template class LevInternalSpeedDistanceInformation<BroadcastData>;
template class LevInternalSpeedDistanceInformation<BroadcastDataMsg>;

LevSpeedDistanceInformation::LevSpeedDistanceInformation(AntRxDataResponse& dp) :
    LevBaseSpeedDistanceInformation(dp),
    LevInternalSpeedDistanceInformation<BroadcastData>() {}

LevSpeedDistanceInformationMsg::LevSpeedDistanceInformationMsg() :
    LevBaseSpeedDistanceInformationMsg(SPEEDDISTANCEINFORMATION_NUMBER),
    LevInternalSpeedDistanceInformation<BroadcastDataMsg>() {}

void LevSpeedDistanceInformationMsg::setRemainingRange(uint16_t remainingRange) { // in km
    set16BitValue(remainingRange, REMAININGRANGE_LSB_BYTE, REMAININGRANGE_MSB_BYTE,
            REMAININGRANGE_MASK);
}
