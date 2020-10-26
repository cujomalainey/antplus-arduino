#include <Profiles/FEC/DataPages/RX/ANTPLUS_FECTrainerData.h>

FECTrainerData::FECTrainerData(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp), FECTrainerDataPage<BroadcastData>() {

}
