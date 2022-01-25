#ifndef ANTPLUS_FECFEEMAINDATAPAGE_h
#define ANTPLUS_FECFEEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class FECFEMainDataPage : virtual public CoreDataPage<T> {
public:
    FECFEMainDataPage();
};

#endif // ANTPLUS_FECFEEMAINDATAPAGE_h
