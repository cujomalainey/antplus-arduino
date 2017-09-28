#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateProductInformation.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateProductInformation::HeartRateProductInformation(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRateProductInformation::getHardwareVersion() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_HARDWAREVERSION_BYTE);
}

uint8_t HeartRateProductInformation::getSoftwareVersion() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_SOFTWAREVERSION_BYTE);
}

uint8_t HeartRateProductInformation::getModelNumber() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_MODELNUMBER_BYTE);
}
