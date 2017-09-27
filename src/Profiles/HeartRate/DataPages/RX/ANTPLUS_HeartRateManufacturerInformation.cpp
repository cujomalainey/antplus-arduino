#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateManufacturerInformation.h>

HeartRateManufacturerInformation::HeartRateManufacturerInformation(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRateManufacturerInformation::getManufacturerIdLsb() {
    // TODO
}

uint16_t HeartRateManufacturerInformation::getSerialNumber() {
    // TODO
}
