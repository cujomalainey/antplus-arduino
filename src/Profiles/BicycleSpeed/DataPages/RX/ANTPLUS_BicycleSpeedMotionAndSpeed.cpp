#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedMotionAndSpeed.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

BicycleSpeedMotionAndSpeed::BicycleSpeedMotionAndSpeed(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp) {

}

uint8_t BicycleSpeedMotionAndSpeed::getFlags() {
    return getData(ANTPLUS_BICYCLESPEED_DATAPAGE_MOTIONANDSPEED_FLAGS_BYTE);
}

