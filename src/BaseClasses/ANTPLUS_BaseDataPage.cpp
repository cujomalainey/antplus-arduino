#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

template<class T>
BaseDataPage<T>::BaseDataPage(AntRxDataResponse& msg) : CoreDataPage<T>() {
    this->setFrameData(msg.getFrameData());
    this->setMsgId(msg.getMsgId());
    this->setAvailable(msg.isAvailable());
    this->setChecksum(msg.getChecksum());
    this->setErrorCode(msg.getErrorCode());
    this->setLength(msg.getLength());
}

template<class T>
uint8_t BaseDataPage<T>::get8BitValue(uint8_t byte, uint8_t mask, uint8_t shift) {
    uint8_t temp = this->getData(byte);
    temp &= mask;
    return temp >> shift;
}

template<class T>
uint16_t BaseDataPage<T>::get16BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask, uint8_t shift) {
    uint16_t temp = this->getData(msb_byte);
    temp <<= BITS_IN_BYTE;
    temp |= this->getData(lsb_byte);
    temp &= mask;
    return temp >> shift;
}

template<class T>
uint32_t BaseDataPage<T>::get24BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift) {
    int8_t step = this->getByteStepDirection(msb_byte, lsb_byte);
    uint32_t temp = this->getData(msb_byte);
    temp <<= BITS_IN_BYTE;
    temp |= this->getData(msb_byte + step);
    temp <<= BITS_IN_BYTE;
    temp |= this->getData(lsb_byte);
    temp &= mask;
    return temp >> shift;
}

template<class T>
uint32_t BaseDataPage<T>::get32BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask, uint8_t shift) {
    int8_t step = this->getByteStepDirection(msb_byte, lsb_byte);
    uint32_t temp = this->getData(msb_byte);
    temp <<= BITS_IN_BYTE;
    temp |= this->getData(msb_byte + step);
    temp <<= BITS_IN_BYTE;
    temp |= this->getData(msb_byte + (step * 2));
    temp <<= BITS_IN_BYTE;
    temp |= this->getData(lsb_byte);
    temp &= mask;
    return temp >> shift;
}

template class BaseDataPage<BroadcastData>;
template class BaseDataPage<AcknowledgedData>;
