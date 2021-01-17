#include <CommonDataPages/ANTPLUS_RequestDataPage.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

template<class T>
BaseRequestDataPage<T>::BaseRequestDataPage() :
    CoreDataPage<T>() {}

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

RequestDataPage::RequestDataPage(AntRxDataResponse& dp) :
    BaseDataPage<AcknowledgedData>(dp),
    BaseRequestDataPage<AcknowledgedData>() {}

RequestDataPageMsg::RequestDataPageMsg() :
    BaseDataPageMsg<AcknowledgedDataMsg>(),
    BaseRequestDataPage<AcknowledgedDataMsg>() {
    setDataBuffer(_buffer);
    setDescriptorByte1(ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_DESCRIPTORBYTE1_INVALID);
    setDescriptorByte2(ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_DESCRIPTORBYTE2_INVALID);
    set8BitValue(ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_NUMBER,
            ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

void RequestDataPageMsg::setSlaveSerialNumber(uint16_t serialNumber) {
    set16BitValue(serialNumber,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_SLAVESERIALNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_SLAVESERIALNUMBER_MSB_BYTE);
}

void RequestDataPageMsg::setDescriptorByte1(uint8_t descriptorByte) {
    set8BitValue(descriptorByte,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_DESCRIPTORBYTE1_BYTE);
}

void RequestDataPageMsg::setDescriptorByte2(uint8_t descriptorByte) {
    set8BitValue(descriptorByte,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_DESCRIPTORBYTE2_BYTE);
}

void RequestDataPageMsg::setRequestedTransmissionResponseCount(uint8_t count) {
     set8BitValue(count,
             ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_BYTE,
             ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_COUNT_MASK);
}

void RequestDataPageMsg::setRequestedTransmissionUseAcknowledged(uint8_t useAcknowledged) {
    set8BitValue(useAcknowledged ? 1 : 0,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_BYTE,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_MASK,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_SHIFT);
}

void RequestDataPageMsg::setRequestedPageNumber(uint8_t pageNumber) {
    set8BitValue(pageNumber,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_REQUESTEDPAGENUMBER_BYTE);
}

void RequestDataPageMsg::setCommandType(uint8_t commandType) {
    if (commandType != ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_COMMANDTYPE_REQUESTDATAPAGEFROMSLAVE) {
        setSlaveSerialNumber(ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_SLAVESERIALNUMBER_INVALID);
    }
    set8BitValue(commandType,
            ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_COMMANDTYPE_BYTE);
}
