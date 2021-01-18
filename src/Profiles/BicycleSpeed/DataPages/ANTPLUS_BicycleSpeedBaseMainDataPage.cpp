#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBaseMainDataPage.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

template<class T>
BicycleSpeedCoreMainDataPage<T>::BicycleSpeedCoreMainDataPage() : CoreDataPage<T>() {}

template<class T>
uint8_t BicycleSpeedCoreMainDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_DATAPAGE_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_DATAPAGE_MASK);
}

template<class T>
uint8_t BicycleSpeedCoreMainDataPage<T>::getPageChangeToggle() {
    return this->get8BitValue(ANTPLUS_BICYCLESPEED_DATAPAGEBASE_TOGGLE_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_TOGGLE_MASK,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_TOGGLE_SHIFT);
}

template<class T>
uint16_t BicycleSpeedCoreMainDataPage<T>::getBikeSpeedEventTime() {
    return this->get16BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_BIKESPEEDEVENTTIME_LSB_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_BIKESPEEDEVENTTIME_MSB_BYTE);
}

template<class T>
uint16_t BicycleSpeedCoreMainDataPage<T>::getCumulativeSpeedRevolutionCount() {
    return this->get16BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_CUMULATIVESPEEDREVOLUTIONCOUNT_LSB_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_CUMULATIVESPEEDREVOLUTIONCOUNT_MSB_BYTE);
}

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
    set8BitValue(toggle ? ANTPLUS_BICYCLESPEED_DATAPAGEBASE_TOGGLE_MASK : 0,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_TOGGLE_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_TOGGLE_MASK);
}

void BicycleSpeedBaseMainDataPageMsg::setBikeSpeedEventTime(uint16_t time) {
    set16BitValue(time,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_BIKESPEEDEVENTTIME_LSB_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_BIKESPEEDEVENTTIME_MSB_BYTE);
}

void BicycleSpeedBaseMainDataPageMsg::setCumulativeSpeedRevolutionCount(uint16_t count) {
    set16BitValue(count,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_CUMULATIVESPEEDREVOLUTIONCOUNT_LSB_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGEBASE_CUMULATIVESPEEDREVOLUTIONCOUNT_MSB_BYTE);
}
