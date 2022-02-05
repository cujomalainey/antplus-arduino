#ifndef ANTPLUS_LEVALTSPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVALTSPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedDistanceInformation.h>

template<class T>
class LevBaseAltSpeedDistanceInformation : virtual public CoreDataPage<T> {
public:
    LevBaseAltSpeedDistanceInformation();
    uint16_t getFuelConsumption(); // in Wh/km
};

class LevAltSpeedDistanceInformation : public LevBaseSpeedDistanceInformation, public LevBaseAltSpeedDistanceInformation<BroadcastData> {
public:
    explicit LevAltSpeedDistanceInformation(AntRxDataResponse& dp);
};

class LevAltSpeedDistanceInformationMsg : public LevBaseSpeedDistanceInformationMsg, public LevBaseAltSpeedDistanceInformation<BroadcastDataMsg> {
public:
    LevAltSpeedDistanceInformationMsg();
    void setFuelConsumption(uint16_t consumption); // in Wh/km
};

#endif // ANTPLUS_LEVALTSPEEDDISTANCEINFORMATION_h
