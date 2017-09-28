#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateManufacturerInformationMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

HeartRateManufacturerInformationMsg::HeartRateManufacturerInformationMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER) {

}

uint8_t HeartRateManufacturerInformationMsg::getManufacturerIdLsb() {
    return _buffer[ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_MANUFACTUREREIDLSB_BYTE];
}

uint16_t HeartRateManufacturerInformationMsg::getSerialNumber() {
    return _buffer[ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERLSB_BYTE] | (_buffer[ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_BYTE] << ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_SHIFT);
}

void HeartRateManufacturerInformationMsg::setManufacturerIdLsb(uint8_t id) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_MANUFACTUREREIDLSB_BYTE] = id;
}

void HeartRateManufacturerInformationMsg::setSerialNumber(uint16_t serialNumber) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERLSB_BYTE] = serialNumber & ANTPLUS_DEFAULT_BYTE_MASK;
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_BYTE] = serialNumber >> ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_SHIFT;
}
