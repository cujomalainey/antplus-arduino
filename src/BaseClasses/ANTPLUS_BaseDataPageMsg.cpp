#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

template<class T>
BaseDataPageMsg<T>::BaseDataPageMsg() : CoreDataPage<T>() {
}

template<class T>
uint8_t BaseDataPageMsg<T>::get8BitValue(uint8_t byte, uint8_t mask, uint8_t shift) {
    uint8_t temp = this->getDataBuffer()[byte];
    temp &= mask;
    return temp >> shift;
}

template<class T>
uint16_t BaseDataPageMsg<T>::get16BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask, uint8_t shift) {
    uint8_t* buf = this->getDataBuffer();
    uint16_t temp = buf[msb_byte];
    temp <<= BITS_IN_BYTE;
    temp |= buf[lsb_byte];
    temp &= mask;
    return temp >> shift;
}

template<class T>
uint32_t BaseDataPageMsg<T>::get24BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift) {
    uint8_t* buf = this->getDataBuffer();
    int8_t step = this->getByteStepDirection(msb_byte, lsb_byte);
    uint32_t temp = buf[msb_byte];
    temp <<= BITS_IN_BYTE;
    temp |= buf[msb_byte + step];
    temp <<= BITS_IN_BYTE;
    temp |= buf[lsb_byte];
    temp &= mask;
    return temp >> shift;
}

template<class T>
uint32_t BaseDataPageMsg<T>::get32BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift) {
    uint8_t* buf = this->getDataBuffer();
    int8_t step = this->getByteStepDirection(msb_byte, lsb_byte);
    uint32_t temp = buf[msb_byte];
    temp <<= BITS_IN_BYTE;
    temp |= buf[msb_byte + step];
    temp <<= BITS_IN_BYTE;
    temp |= buf[msb_byte + (step * 2)];
    temp <<= BITS_IN_BYTE;
    temp |= buf[lsb_byte];
    temp &= mask;
    return temp >> shift;
}

template<class T>
void BaseDataPageMsg<T>::set8BitValue(uint8_t value, uint8_t byte, uint8_t mask, uint8_t shift) {
    uint8_t* buf = this->getDataBuffer();
    buf[byte] &= ~mask;
    buf[byte] |= (value << shift) & mask;
}

template<class T>
void BaseDataPageMsg<T>::set16BitValue(uint16_t value, uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask, uint8_t shift) {
    uint8_t* buf = this->getDataBuffer();
    value <<= shift;
    buf[lsb_byte] &= ~((uint8_t)mask);
    buf[lsb_byte] |= (uint8_t)(value & mask);
    mask >>= BITS_IN_BYTE;
    value >>= BITS_IN_BYTE;
    buf[msb_byte] &= ~((uint8_t)mask);
    buf[msb_byte] |= (uint8_t)(value & mask);
}

template<class T>
void BaseDataPageMsg<T>::set24BitValue(uint32_t value, uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift) {
    int8_t step = this->getByteStepDirection(lsb_byte, msb_byte);
    uint8_t* buf = this->getDataBuffer();
    value <<= shift;
    buf[lsb_byte] &= ~((uint8_t)mask);
    buf[lsb_byte] |= (uint8_t)(value & mask);
    mask >>= BITS_IN_BYTE;
    value >>= BITS_IN_BYTE;
    buf[lsb_byte + step] &= ~((uint8_t)mask);
    buf[lsb_byte + step] |= (uint8_t)(value & mask);
    mask >>= BITS_IN_BYTE;
    value >>= BITS_IN_BYTE;
    buf[msb_byte] &= ~((uint8_t)mask);
    buf[msb_byte] |= (uint8_t)(value & mask);
}

template<class T>
void BaseDataPageMsg<T>::set32BitValue(uint32_t value, uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift) {
    int8_t step = this->getByteStepDirection(lsb_byte, msb_byte);
    uint8_t* buf = this->getDataBuffer();
    value <<= shift;
    buf[lsb_byte] &= ~((uint8_t)mask);
    buf[lsb_byte] |= (uint8_t)(value & mask);
    mask >>= BITS_IN_BYTE;
    value >>= BITS_IN_BYTE;
    buf[lsb_byte + step] &= ~((uint8_t)mask);
    buf[lsb_byte + step] |= (uint8_t)(value & mask);
    mask >>= BITS_IN_BYTE;
    value >>= BITS_IN_BYTE;
    buf[lsb_byte + (step * 2)] &= ~((uint8_t)mask);
    buf[lsb_byte + (step * 2)] |= (uint8_t)(value & mask);
    mask >>= BITS_IN_BYTE;
    value >>= BITS_IN_BYTE;
    buf[msb_byte] &= ~((uint8_t)mask);
    buf[msb_byte] |= (uint8_t)(value & mask);
}

template class BaseDataPageMsg<BroadcastDataMsg>;
template class BaseDataPageMsg<AcknowledgedDataMsg>;
