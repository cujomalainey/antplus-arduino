#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateManufacturerInformationMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

HeartRateManufacturerInformationMsg::HeartRateManufacturerInformationMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER), HeartRateBaseManufacturerInformation<BroadcastDataMsg>() {
}

void HeartRateManufacturerInformationMsg::setManufacturerIdLsb(uint8_t id) {
    set8BitValue(id,
            ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_MANUFACTUREREIDLSB_BYTE);
}

void HeartRateManufacturerInformationMsg::setSerialNumber(uint16_t serialNumber) {
    set16BitValue(serialNumber,
            ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERLSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_BYTE);
}
