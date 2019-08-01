#include <CommonDataPages/RX/ANTPLUS_ManufacturersInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

ManufacturersInformation::ManufacturersInformation(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp), BaseManufacturersInformation<BroadcastData>() {
}
