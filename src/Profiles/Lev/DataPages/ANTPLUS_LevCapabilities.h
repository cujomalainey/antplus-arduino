#ifndef ANTPLUS_LEVCAPABILITIES_h
#define ANTPLUS_LEVCAPABILITIES_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>

template<class T>
class LevBaseCapabilities : virtual public CoreDataPage<T> {
public:
    LevBaseCapabilities();
    uint8_t getNumberOfAssistModesSupported();
    uint8_t getNumberOfRegenerativeModesSupported();
    uint16_t getWheelCircumference();
};

class LevCapabilities : public LevBaseMainDataPage, public LevBaseCapabilities<BroadcastData> {
public:
    explicit LevCapabilities(AntRxDataResponse& dp);
};

class LevCapabilitiesMsg : public LevBaseMainDataPageMsg<BroadcastDataMsg>, public LevBaseCapabilities<BroadcastDataMsg> {
public:
    LevCapabilitiesMsg();
    void setNumberOfAssistModesSupported(uint8_t modes);
    void setNumberOfRegenerativeModesSupported(uint8_t modes);
    void setWheelCircumference(uint16_t circumference);
};

#endif // ANTPLUS_LEVCAPABILITIES_h
