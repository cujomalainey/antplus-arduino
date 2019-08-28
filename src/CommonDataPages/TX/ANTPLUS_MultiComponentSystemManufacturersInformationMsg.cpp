#include <CommonDataPages/TX/ANTPLUS_MultiComponentSystemManufacturersInformationMsg.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

MultiComponentSystemManufacturersInformationMsg::MultiComponentSystemManufacturersInformationMsg() : BaseDataPageMsg<BroadcastDataMsg>(), BaseMultiComponentSystemManufacturersInformation<BroadcastDataMsg>() {
}

void MultiComponentSystemManufacturersInformationMsg::setNumberOfComponents(uint8_t count) {
    set8BitValue(count,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_NUMBERCOMPONENTS_MASK);
}

void MultiComponentSystemManufacturersInformationMsg::setComponentIdentifier(uint8_t identifier) {
    set8BitValue(identifier,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

void MultiComponentSystemManufacturersInformationMsg::setHWRevision(uint8_t rev) {
    set8BitValue(rev,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_HWREVISION_BYTE);
}

void MultiComponentSystemManufacturersInformationMsg::setManufacturerId(uint16_t id) {
    set16BitValue(id,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MANUFACTURERID_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MANUFACTURERID_MSB_BYTE);
}

void MultiComponentSystemManufacturersInformationMsg::setModelNumber(uint16_t model) {
    set16BitValue(model,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MODELNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MODELNUMBER_MSB_BYTE);
}
