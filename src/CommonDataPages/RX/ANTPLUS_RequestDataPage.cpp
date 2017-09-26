#include <CommonDataPages/RX/ANTPLUS_RequestDataPage.h>

RequestDataPage::RequestDataPage(AcknowledgedData& dp) : BaseDataPage<AcknowledgedData>(dp) {
    // TODO
}

uint16_t RequestDataPage::getSlaveSerialNumber() {
    // TODO
}

uint8_t RequestDataPage::getDescriptorByte1() {
    // TODO
}

uint8_t RequestDataPage::getDescriptorByte2() {
    // TODO
}

uint8_t RequestDataPage::getRequestedTransmissionResponse() {
    // TODO
}

uint8_t RequestDataPage::getRequestedPageNumber() {
    // TODO
}

uint8_t RequestDataPage::getCommandType() {
    // TODO
}
