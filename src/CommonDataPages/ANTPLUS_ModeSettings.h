#ifndef ANTPLUS_MODESETTINGS_h
#define ANTPLUS_MODESETTINGS_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

// Common page 76

template<class T>
class BaseModeSettings : virtual public CoreDataPage<T> {
public:
    BaseModeSettings();
    uint8_t getSportMode();
};

class ModeSettings : public BaseDataPage<BroadcastData>, public BaseModeSettings<BroadcastData> {
public:
    explicit ModeSettings(AntRxDataResponse& dp);
};

class ModeSettingsMsg : public BaseDataPageMsg<BroadcastDataMsg>, public BaseModeSettings<BroadcastDataMsg> {
// TODO
};

#endif // ANTPLUS_MODESETTINGS_h
