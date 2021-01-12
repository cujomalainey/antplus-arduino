#include <CommonDataPages/RX/ANTPLUS_MultiComponentSystemManufacturersInformation.h>

MultiComponentSystemManufacturersInformation::MultiComponentSystemManufacturersInformation(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp), BaseMultiComponentSystemManufacturersInformation<BroadcastData>() {
}
