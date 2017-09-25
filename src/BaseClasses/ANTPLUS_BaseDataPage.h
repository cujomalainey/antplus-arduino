#ifndef ANTPLUS_BASEDATAPAGE_h
#define ANTPLUS_BASEDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

template<class T>
class BaseDataPage : public CoreDataPage<T> {
public:
    BaseDataPage<T>(T& msg);
};

#endif // ANTPLUS_BASEDATAPAGE_h