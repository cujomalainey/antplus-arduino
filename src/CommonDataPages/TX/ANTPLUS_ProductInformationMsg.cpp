#include <CommonDataPages/TX/ANTPLUS_ProductInformationMsg.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

ProductInformationMsg::ProductInformationMsg() : BaseDataPageMsg(), BaseProductInformation<BroadcastDataMsg>() {
    // TODO set default values
    setDataBuffer(_buffer);
    _buffer[0] = ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_NUMBER;
    _buffer[1] = 0xFF;
}

void ProductInformationMsg::setSWRevisionSupplemental(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SWREVISIONSUPPLEMENTAL_BYTE);
}

void ProductInformationMsg::setSWRevisionMain(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SWREVISIONMAIN_BYTE);
}

void ProductInformationMsg::setSerialNumber(uint32_t serialNumber) {
    set32BitValue(serialNumber,
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SERIALNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SERIALNUMBER_MSB_BYTE);
}
