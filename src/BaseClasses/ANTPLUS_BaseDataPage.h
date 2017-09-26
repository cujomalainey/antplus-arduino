#ifndef ANTPLUS_BASEDATAPAGE_h
#define ANTPLUS_BASEDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BaseDataPage : public CoreDataPage<T> {
public:
    BaseDataPage<T>(AntRxDataResponse& msg);
};

#endif // ANTPLUS_BASEDATAPAGE_h