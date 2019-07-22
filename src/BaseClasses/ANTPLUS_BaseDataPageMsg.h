#ifndef ANTPLUS_BASEDATAPAGEMSG_h
#define ANTPLUS_BASEDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

template<class T>
class BaseDataPageMsg : public CoreDataPage<T> {
public:
    BaseDataPageMsg();
protected:
    uint8_t get8BitValue(uint8_t byte, uint8_t mask, uint8_t shift);
    uint16_t get16BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask, uint8_t shift);
    uint32_t get24BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift);
    uint32_t get32BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift);
    void set8BitValue(uint8_t byte, uint8_t mask, uint8_t shift, uint8_t value);
    void set16BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask, uint8_t shift, uint16_t value);
    void set24BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift, uint32_t value);
    void set32BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift, uint32_t value);
};

#endif // ANTPLUS_BASEDATAPAGEMSG_h
