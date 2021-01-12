#include <CommonDataPages/TX/ANTPLUS_RequestDataPageMsg.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

RequestDataPageMsg::RequestDataPageMsg() : BaseDataPageMsg(), BaseRequestDataPage<AcknowledgedDataMsg>() {
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
