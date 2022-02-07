#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBaseMainDataPage.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define DATAPAGE_BYTE 0
#define TOGGLE_BYTE   0
#define BIKESPEEDEVENTTIME_LSB_BYTE 4
#define BIKESPEEDEVENTTIME_MSB_BYTE 5
#define CUMULATIVESPEEDREVOLUTIONCOUNT_LSB_BYTE 6
#define CUMULATIVESPEEDREVOLUTIONCOUNT_MSB_BYTE 7
#define DATAPAGE_MASK 0x7F
#define TOGGLE_MASK   0x80
#define TOGGLE_SHIFT  7

template<class T>
BicycleSpeedCoreMainDataPage<T>::BicycleSpeedCoreMainDataPage() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicycleSpeedCoreMainDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(DATAPAGE_BYTE, DATAPAGE_MASK);
}

template<class T>
uint8_t BicycleSpeedCoreMainDataPage<T>::getPageChangeToggle() {
    return this->get8BitValue(TOGGLE_BYTE, TOGGLE_MASK, TOGGLE_SHIFT);
}

template<class T>
uint16_t BicycleSpeedCoreMainDataPage<T>::getBikeSpeedEventTime() {
    return this->get16BitValue(BIKESPEEDEVENTTIME_LSB_BYTE,
            BIKESPEEDEVENTTIME_MSB_BYTE);
}

template<class T>
uint16_t BicycleSpeedCoreMainDataPage<T>::getCumulativeSpeedRevolutionCount() {
    return this->get16BitValue(CUMULATIVESPEEDREVOLUTIONCOUNT_LSB_BYTE,
            CUMULATIVESPEEDREVOLUTIONCOUNT_MSB_BYTE);
}
template class BicycleSpeedCoreMainDataPage<BroadcastData>;
template class BicycleSpeedCoreMainDataPage<BroadcastDataMsg>;

BicycleSpeedBaseMainDataPage::BicycleSpeedBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    BicycleSpeedCoreMainDataPage<BroadcastData>() {}

BicycleSpeedBaseMainDataPageMsg::BicycleSpeedBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<BroadcastDataMsg>(),
    BicycleSpeedCoreMainDataPage<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

void BicycleSpeedBaseMainDataPageMsg::setPageChangeToggle(uint8_t toggle) {
    set8BitValue(toggle ? TOGGLE_MASK : 0, TOGGLE_BYTE, TOGGLE_MASK);
}

void BicycleSpeedBaseMainDataPageMsg::setBikeSpeedEventTime(uint16_t time) {
    set16BitValue(time, BIKESPEEDEVENTTIME_LSB_BYTE,
            BIKESPEEDEVENTTIME_MSB_BYTE);
}

void BicycleSpeedBaseMainDataPageMsg::setCumulativeSpeedRevolutionCount(uint16_t count) {
    set16BitValue(count, CUMULATIVESPEEDREVOLUTIONCOUNT_LSB_BYTE,
            CUMULATIVESPEEDREVOLUTIONCOUNT_MSB_BYTE);
}
