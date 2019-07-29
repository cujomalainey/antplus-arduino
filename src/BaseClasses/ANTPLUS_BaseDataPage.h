#ifndef ANTPLUS_BASEDATAPAGE_h
#define ANTPLUS_BASEDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BaseDataPage : public CoreDataPage<T> {
public:
    BaseDataPage<T>(AntRxDataResponse& msg);
#ifndef UNIT_TEST
protected:
#endif // UNIT_TEST
    uint8_t get8BitValue(uint8_t byte, uint8_t mask = 0xFF, uint8_t shift = 0);
    uint16_t get16BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask = 0xFFFF, uint8_t shift = 0);
    uint32_t get24BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask = 0xFFFFFF, uint8_t shift = 0);
    uint32_t get32BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask = 0xFFFFFFFF, uint8_t shift = 0);
};

#endif // ANTPLUS_BASEDATAPAGE_h
