#include <CommonDataPages/TX/ANTPLUS_MultiComponentSystemProductInformationMsg.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

MultiComponentSystemProductInformationMsg::MultiComponentSystemProductInformationMsg() : BaseDataPageMsg<BroadcastDataMsg>(), BaseMultiComponentSystemProductInformation<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_NUMBER,
            ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

void MultiComponentSystemProductInformationMsg::setNumberOfComponents(uint8_t count) {
    set8BitValue(count,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_NUMBEROFCOMPONENTS_MASK);
}

void MultiComponentSystemProductInformationMsg::setComponentIdentifier(uint8_t identifier) {
    set8BitValue(identifier,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

void MultiComponentSystemProductInformationMsg::setSWRevisionSupplemental(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SWREVISIONSUPPLEMENTAL_BYTE);
}

void MultiComponentSystemProductInformationMsg::setSWRevisionMain(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SWREVISIONMAIN_BYTE);
}

void MultiComponentSystemProductInformationMsg::setSerialNumber(uint32_t serialNumber) {
    set32BitValue(serialNumber,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SERIALNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SERIALNUMBER_MSB_BYTE);
}
