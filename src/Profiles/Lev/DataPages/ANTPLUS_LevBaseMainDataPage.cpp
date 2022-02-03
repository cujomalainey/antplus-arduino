#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>
#include <ANTPLUS_PrivateDefines.h>

LevBaseMainDataPage::LevBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp) {}

template<class T>
LevBaseMainDataPageMsg<T>::LevBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<T>() {
    this->setDataBuffer(_buffer);
    this->set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

template class LevBaseMainDataPageMsg<BroadcastDataMsg>;
template class LevBaseMainDataPageMsg<AcknowledgedDataMsg>;
