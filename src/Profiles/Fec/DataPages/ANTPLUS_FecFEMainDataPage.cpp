#include <Profiles/Fec/DataPages/ANTPLUS_FecFEMainDataPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define CADENCE_BYTE 4
#define NEGTIVE_VERTICAL_DISTANCE_BYTE 5

// TODO update name
template<class T>
FECFEMainDataPage<T>::FECFEMainDataPage() :
    CoreDataPage<T>() {}

template class FECFEMainDataPage<BroadcastData>;
template class FECFEMainDataPage<BroadcastDataMsg>;
