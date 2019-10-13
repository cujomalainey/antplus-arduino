#include <CommonDataPages/TX/ANTPLUS_ManufacturersInformationMsg.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO Magic numbers
ManufacturersInformationMsg::ManufacturersInformationMsg() : BaseDataPageMsg(), BaseManufacturersInformation<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_NUMBER;
    _buffer[1] = 0xFF;
    _buffer[2] = 0xFF;
}

void ManufacturersInformationMsg::setHWRevision(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_HWREVISION_BYTE);
}

void ManufacturersInformationMsg::setManufacturerId(uint16_t id) {
    set16BitValue(id,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MANUFACTURERID_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MANUFACTURERID_MSB_BYTE);
}

void ManufacturersInformationMsg::setModelNumber(uint16_t modelNumber) {
    set16BitValue(modelNumber,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MODELNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MODELNUMBER_MSB_BYTE);
}
