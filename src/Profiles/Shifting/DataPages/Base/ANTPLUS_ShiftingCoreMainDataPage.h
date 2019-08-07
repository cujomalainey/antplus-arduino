#ifndef ANTPLUS_SHIFTINGCOREMAINDATAPAGEMSG_h
#define ANTPLUS_SHIFTINGCOREMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template <class T>
class ShiftingCoreMainDataPage : virtual public CoreDataPage<T> {
public:
    ShiftingCoreMainDataPage();
    uint8_t getDataPageNumber();
};

#endif // ANTPLUS_SHIFTINGCOREMAINDATAPAGEMSG_h
