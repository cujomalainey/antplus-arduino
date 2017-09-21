#ifndef ANTPLUS_BASEDATAPAGE_h
#define ANTPLUS_BASEDATAPAGE_h

#include <inttypes.h>

class BaseDataPage {
public:
    virtual uint8_t getDataPageNumber() = 0;
};

#endif // ANTPLUS_BASEDATAPAGE_h