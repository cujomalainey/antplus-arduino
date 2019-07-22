#ifndef ANTPLUS_BASEDATAPAGE_h
#define ANTPLUS_BASEDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BaseDataPage : public CoreDataPage<T> {
public:
    BaseDataPage<T>(AntRxDataResponse& msg);
protected:
    uint8_t get8BitValue(uint8_t byte, uint8_t mask, uint8_t shift);
    uint16_t get16BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask, uint8_t shift);
    uint32_t get24BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift);
    uint32_t get32BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift);
};

#endif // ANTPLUS_BASEDATAPAGE_h
