#ifndef ANTPLUS_COREDATAPAGE_h
#define ANTPLUS_COREDATAPAGE_h

#include <inttypes.h>

template<class T>
class CoreDataPage : public T {
public:
    CoreDataPage();
    virtual uint8_t getDataPageNumber();
};

#endif // ANTPLUS_COREDATAPAGE_h