#include <CommonDataPages/TX/ANTPLUS_ManufacturersInformationMsg.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO Magic numbers
ManufacturersInformationMsg::ManufacturersInformationMsg() : BaseDataPageMsg() {
    setDataBuffer(_buffer);
    _buffer[0] = 80;
    _buffer[1] = 0xFF;
    _buffer[2] = 0xFF;
}

uint8_t ManufacturersInformationMsg::getHWRevision() {
    return _buffer[3];
}

uint16_t ManufacturersInformationMsg::getManufacturerId() {
    uint16_t temp = _buffer[4];
    temp |= _buffer[5] << 8;
    return temp;
}

uint16_t ManufacturersInformationMsg::getModelNumber() {
    uint16_t temp = _buffer[6];
    temp |= _buffer[7] << 8;
    return temp;
}

void ManufacturersInformationMsg::setHWRevision(uint8_t revision) {
    _buffer[3] = revision;
}

void ManufacturersInformationMsg::setManufacturerId(uint16_t id) {
    _buffer[4] = id & 0xFF;
    _buffer[5] = (id >> 8) & 0xFF;
}

void ManufacturersInformationMsg::setModelNumber(uint16_t modelNumber) {
    _buffer[6] = modelNumber & 0xFF;
    _buffer[7] = (modelNumber >> 8) & 0xFF;
}
