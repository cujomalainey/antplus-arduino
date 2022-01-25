#ifndef ANTPLUS_FECFECAPABILITIES_h
#define ANTPLUS_FECFECAPABILITIES_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseFeCapabilities : virtual public CoreDataPage<T> {
public:
    FecBaseFeCapabilities();
    uint16_t getMaximumResistance();
    uint8_t getCapabilitiesBitField();
};

class FecFeCapabilities : public FecBaseMainDataPage, public FecBaseFeCapabilities<BroadcastData> {
public:
    explicit FecFeCapabilities(AntRxDataResponse& dp);
};

class FecFeCapabilitiesMsg : public FecBaseMainDataPageMsg, public FecBaseFeCapabilities<BroadcastDataMsg> {
public:
    FecFeCapabilitiesMsg();
    void setMaximumResistance(uint16_t UserWeight);
    void setCapabitiliesBitField(uint8_t BikeWeight);
};

#endif // ANTPLUS_FECFECAPABILITIES_h

