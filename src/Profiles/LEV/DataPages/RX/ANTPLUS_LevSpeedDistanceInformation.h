#ifndef ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>

class LevSpeedDistanceInformation : public LevBaseMainDataPage {
public:
    LevSpeedDistanceInformation(AntRxDataResponse& dp);
	uint32_t getOdometer(); // in km
	uint16_t getRemainingRange(); // in km
    uint16_t getSpeed();     // in 1/10 km/h
};


class LevAltSpeedDistanceInformation : public LevBaseMainDataPage {
public:
    LevAltSpeedDistanceInformation(AntRxDataResponse& dp);
	uint32_t getOdometer(); // in km
	uint16_t getFuelConsumption(); // in Wh/km
	uint16_t getSpeed();     // in 1/10 km/h
};

#endif // ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
