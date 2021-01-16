#ifndef ANTPLUS_FECTRAINERDATA_h
#define ANTPLUS_FECTRAINERDATA_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <Profiles/FEC/DataPages/Base/ANTPLUS_FECTrainerDataPage.h>

class FECTrainerData : public BaseDataPage<BroadcastData>, public FECTrainerDataPage<BroadcastData> {
public:
    explicit FECTrainerData(AntRxDataResponse& dp);
};

#endif // ANTPLUS_FECTRAINERDATA_h
