#ifndef ANTPLUS_LEVSPEEDDIST_h
#define ANTPLUS_LEVSPEEDDIST_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>

class LevSpeedDist1 : public LevBaseMainDataPage {
public:
    LevSpeedDist1(AntRxDataResponse& dp);
	uint32_t getTotalDist(); // in km
	uint16_t getRemainingRange(); // in km
    uint16_t getSpeed();     // in 1/10 km/h
};


class LevSpeedDist2 : public LevBaseMainDataPage {
public:
	LevSpeedDist2(AntRxDataResponse& dp);
	uint32_t getTotalDist(); // in km
	uint16_t getFuelConsumption(); // in Wh/km
	uint16_t getSpeed();     // in 1/10 km/h
};

#endif // ANTPLUS_LEVSPEEDSYSDIST_h
