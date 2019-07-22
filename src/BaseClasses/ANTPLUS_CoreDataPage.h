#ifndef ANTPLUS_COREDATAPAGE_h
#define ANTPLUS_COREDATAPAGE_h

#include <inttypes.h>

template<class T>
class CoreDataPage : public T {
public:
    CoreDataPage();
    virtual uint8_t getDataPageNumber();
protected:
    /**
     * These values are assumed to contiguous in their bit fields, they will not work
     * for fields that are fragemented. Therefore inner bytes are assumed to have a mask
     * of 0xFF.
     */
    int8_t getByteStepDirection(uint8_t from, uint8_t to);
    virtual uint8_t get8BitValue(uint8_t byte, uint8_t mask, uint8_t shift) = 0;
    virtual uint16_t get16BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask, uint8_t shift) = 0;
    virtual uint32_t get24BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift) = 0;
    virtual uint32_t get32BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift) = 0;
};

#endif // ANTPLUS_COREDATAPAGE_h
