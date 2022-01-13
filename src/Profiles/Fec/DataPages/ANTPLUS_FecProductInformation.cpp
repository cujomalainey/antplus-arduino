#include <Profiles/Fec/DataPages/ANTPLUS_FecProductInformation.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define RESERVED_BYTE 1
#define SW_SUPLEMENTAL_REVISION_BYTE 2
#define SW_MAIN_REVISION_BYTE 3

template<class T>
FecBaseProductInformation<T>::FecBaseProductInformation() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseProductInformation<T>::getSoftwareRevision() {
    return this->get16BitValue(SW_MAIN_REVISION_BYTE, SW_SUPLEMENTAL_REVISION_BYTE);
}

template class FecBaseProductInformation<BroadcastData>;
template class FecBaseProductInformation<BroadcastDataMsg>;

FecProductInformation::FecProductInformation(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseProductInformation<BroadcastData>() {}

FecProductInformationMsg::FecProductInformationMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_PRODUCT_INFORMATION_NUMBER),
    FecBaseProductInformation<BroadcastDataMsg>() {}

void FecProductInformationMsg::setSoftwareRevision(uint16_t SoftwareRevision) {
    set16BitValue(SoftwareRevision, SW_MAIN_REVISION_BYTE, SW_SUPLEMENTAL_REVISION_BYTE);
}

