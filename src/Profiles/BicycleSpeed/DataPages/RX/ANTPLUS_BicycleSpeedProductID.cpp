#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedProductID.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

BicycleSpeedProductID::BicycleSpeedProductID(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp) {

}

uint8_t BicycleSpeedProductID::getHardwareVersion() {
    return getData(ANTPLUS_BICYCLESPEED_DATAPAGE_PRODUCTINFORMATION_HARDWAREVERSION_BYTE);
}

uint8_t BicycleSpeedProductID::getSoftwareVersion() {
    return getData(ANTPLUS_BICYCLESPEED_DATAPAGE_PRODUCTINFORMATION_SOFTWAREVERSION_BYTE);
}

uint8_t BicycleSpeedProductID::getModelNumber() {
    return getData(ANTPLUS_BICYCLESPEED_DATAPAGE_PRODUCTINFORMATION_MODELNUMBER_BYTE);
}
