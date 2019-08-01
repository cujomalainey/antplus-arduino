#include <CommonDataPages/Base/ANTPLUS_BaseRequestDataPage.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

template<class T>
BaseRequestDataPage<T>::BaseRequestDataPage() : CoreDataPage<T>() {
}

template<class T>
uint16_t BaseRequestDataPage<T>::getSlaveSerialNumber() {
    return this->get16BitValue(
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_SLAVESERIALNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_SLAVESERIALNUMBER_MSB_BYTE);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getDescriptorByte1() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_DESCRIPTORBYTE1_BYTE);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getDescriptorByte2() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_DESCRIPTORBYTE2_BYTE);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getRequestedPageCount() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_BYTE,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_COUNT_MASK);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getUseAcknowledgedMsgs() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_BYTE,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_MASK,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_SHIFT);
}

template<class T>
uint8_t BaseRequestDataPage<T>::transmitTillAcknowledged() {
    return this->get8BitValue(ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_BYTE)
        == ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_TRANSMITTILLACKNOWLEDGED_VALUE;
}

template<class T>
uint8_t BaseRequestDataPage<T>::getRequestedPageNumber() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDPAGENUMBER_BYTE);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getCommandType() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_COMMANDTYPE_BYTE);
}

template class BaseRequestDataPage<AcknowledgedData>;
template class BaseRequestDataPage<AcknowledgedDataMsg>;
