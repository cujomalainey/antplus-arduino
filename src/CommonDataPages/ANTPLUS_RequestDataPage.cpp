#include <CommonDataPages/ANTPLUS_RequestDataPage.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define SLAVESERIALNUMBER_LSB_BYTE                                      1
#define SLAVESERIALNUMBER_MSB_BYTE                                      2
#define DESCRIPTORBYTE1_BYTE                                            3
#define DESCRIPTORBYTE2_BYTE                                            4
#define REQUESTEDTRANSMISSIONRESPONSE_BYTE                              5
#define REQUESTEDTRANSMISSIONRESPONSE_COUNT_MASK                        0x7F
#define REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_MASK              0x80
#define REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_SHIFT             7
#define REQUESTEDTRANSMISSIONRESPONSE_TRANSMITTILLACKNOWLEDGED_VALUE    0x80
#define REQUESTEDPAGENUMBER_BYTE                                        6
#define COMMANDTYPE_BYTE                                                7

template<class T>
BaseRequestDataPage<T>::BaseRequestDataPage() :
    CoreDataPage<T>() {}

template<class T>
uint16_t BaseRequestDataPage<T>::getSlaveSerialNumber() {
    return this->get16BitValue(
            SLAVESERIALNUMBER_LSB_BYTE, SLAVESERIALNUMBER_MSB_BYTE);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getDescriptorByte1() {
    return this->get8BitValue(DESCRIPTORBYTE1_BYTE);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getDescriptorByte2() {
    return this->get8BitValue(DESCRIPTORBYTE2_BYTE);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getRequestedTransmissionResponseCount() {
    return this->get8BitValue(
            REQUESTEDTRANSMISSIONRESPONSE_BYTE,
            REQUESTEDTRANSMISSIONRESPONSE_COUNT_MASK);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getRequestedTransmissionUseAcknowledged() {
    return this->get8BitValue(
            REQUESTEDTRANSMISSIONRESPONSE_BYTE,
            REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_MASK,
            REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_SHIFT);
}

template<class T>
uint8_t BaseRequestDataPage<T>::transmitTillAcknowledged() {
    return this->get8BitValue(REQUESTEDTRANSMISSIONRESPONSE_BYTE)
        == REQUESTEDTRANSMISSIONRESPONSE_TRANSMITTILLACKNOWLEDGED_VALUE;
}

template<class T>
uint8_t BaseRequestDataPage<T>::getRequestedPageNumber() {
    return this->get8BitValue(REQUESTEDPAGENUMBER_BYTE);
}

template<class T>
uint8_t BaseRequestDataPage<T>::getCommandType() {
    return this->get8BitValue(COMMANDTYPE_BYTE);
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
    set8BitValue(COMMON_REQUESTDATAPAGE_NUMBER, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

void RequestDataPageMsg::setSlaveSerialNumber(uint16_t serialNumber) {
    set16BitValue(serialNumber,
            SLAVESERIALNUMBER_LSB_BYTE, SLAVESERIALNUMBER_MSB_BYTE);
}

void RequestDataPageMsg::setDescriptorByte1(uint8_t descriptorByte) {
    set8BitValue(descriptorByte, DESCRIPTORBYTE1_BYTE);
}

void RequestDataPageMsg::setDescriptorByte2(uint8_t descriptorByte) {
    set8BitValue(descriptorByte, DESCRIPTORBYTE2_BYTE);
}

void RequestDataPageMsg::setRequestedTransmissionResponseCount(uint8_t count) {
     set8BitValue(count,
             REQUESTEDTRANSMISSIONRESPONSE_BYTE,
             REQUESTEDTRANSMISSIONRESPONSE_COUNT_MASK);
}

void RequestDataPageMsg::setRequestedTransmissionUseAcknowledged(uint8_t useAcknowledged) {
    set8BitValue(useAcknowledged ? 1 : 0, REQUESTEDTRANSMISSIONRESPONSE_BYTE,
            REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_MASK,
            REQUESTEDTRANSMISSIONRESPONSE_USEACKNOWLEDGED_SHIFT);
}

void RequestDataPageMsg::setRequestedPageNumber(uint8_t pageNumber) {
    set8BitValue(pageNumber, REQUESTEDPAGENUMBER_BYTE);
}

void RequestDataPageMsg::setCommandType(uint8_t commandType) {
    if (commandType != ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_COMMANDTYPE_REQUESTDATAPAGEFROMSLAVE) {
        setSlaveSerialNumber(ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_SLAVESERIALNUMBER_INVALID);
    }
    set8BitValue(commandType, COMMANDTYPE_BYTE);
}
