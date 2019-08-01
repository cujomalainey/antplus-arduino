#ifndef ANTPLUS_BASEMODESETTINGS_h
#define ANTPLUS_BASEMODESETTINGS_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

// Common page 76

template<class T>
class BaseModeSettings : virtual public CoreDataPage<T> {
public:
    BaseModeSettings();
    uint8_t getSportMode();
};

#endif // ANTPLUS_BASEMODESETTINGS_h
