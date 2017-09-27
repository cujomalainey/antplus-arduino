#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateManufacturerInformation.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateManufacturerInformation::HeartRateManufacturerInformation(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRateManufacturerInformation::getManufacturerIdLsb() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_MANUFACTUREREIDLSB_BYTE);
}

uint16_t HeartRateManufacturerInformation::getSerialNumber() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERLSB_BYTE) | (getData(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_BYTE) << ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_SHIFT);
}
