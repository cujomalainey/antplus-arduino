#ifndef ANTPLUS_HEARTRATEMANUFACTURERINFORMATION_h
#define ANTPLUS_HEARTRATEMANUFACTURERINFORMATION_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

class HeartRateManufacturerInformation : public HeartRateBaseMainDataPage {
public:
    HeartRateManufacturerInformation();
    uint8_t getManufacturerIdLsb();
    uint16_t getSerialNumber();
};

#endif // ANTPLUS_HEARTRATEMANUFACTURERINFORMATION_h