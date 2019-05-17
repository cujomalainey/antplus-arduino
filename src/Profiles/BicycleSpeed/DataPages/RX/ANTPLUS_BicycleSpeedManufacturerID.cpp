#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedManufacturerID.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

BicycleSpeedManufacturerID::BicycleSpeedManufacturerID(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp) {

}

uint8_t BicycleSpeedManufacturerID::getManufacturerId() {
    return getData(ANTPLUS_BICYCLESPEED_DATAPAGE_MANUFACTURERINFORMATION_MANUFACTUREREID_BYTE);
}

uint16_t BicycleSpeedManufacturerID::getSerialNumber() {
    return getData(ANTPLUS_BICYCLESPEED_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERLSB_BYTE) | (getData(ANTPLUS_BICYCLESPEED_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_BYTE) << ANTPLUS_BICYCLESPEED_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_SHIFT);
}
