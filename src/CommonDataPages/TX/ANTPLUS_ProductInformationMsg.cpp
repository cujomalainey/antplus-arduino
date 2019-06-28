#include <CommonDataPages/TX/ANTPLUS_ProductInformationMsg.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

ProductInformationMsg::ProductInformationMsg() : BaseDataPageMsg() {
    // TODO set default values
    setDataBuffer(_buffer);
    _buffer[0] = 81;
    _buffer[1] = 0xFF;
}

// TODO remove magic numbers
uint8_t ProductInformationMsg::getSWRevisionSupplemental() {
    return _buffer[2];
}

uint8_t ProductInformationMsg::getSWRevisionMain() {
    return _buffer[3];
}

uint32_t ProductInformationMsg::getSerialNumber() {
    uint32_t temp = _buffer[7] << 24;
    temp |= _buffer[6] << 16;
    temp |= _buffer[5] << 8;
    temp |= _buffer[4];
    return temp;
}

void ProductInformationMsg::setSWRevisionSupplemental(uint8_t revision) {
    _buffer[2] = revision;
}

void ProductInformationMsg::setSWRevisionMain(uint8_t revision) {
    _buffer[3] = revision;
}

void ProductInformationMsg::setSerialNumber(uint32_t serialNumber) {
    _buffer[7] = (serialNumber >> 24) & 0xFF;
    _buffer[6] = (serialNumber >> 16) & 0xFF;
    _buffer[5] = (serialNumber >> 8) & 0xFF;
    _buffer[4] = serialNumber & 0xFF;
}
