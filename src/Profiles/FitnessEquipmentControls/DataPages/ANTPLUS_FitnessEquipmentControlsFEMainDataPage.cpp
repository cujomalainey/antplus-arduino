#include <Profiles/FitnessEquipmentControls/DataPages/ANTPLUS_FitnessEquipmentControlsFEMainDataPage.h>
#include <Profiles/FitnessEquipmentControls/ANTPLUS_FitnessEquipmentControlsPrivateDefines.h>

#define CADENCE_BYTE 4
#define NEGTIVE_VERTICAL_DISTANCE_BYTE 5

// TODO update name
template<class T>
FECFEMainDataPage<T>::FECFEMainDataPage() :
    CoreDataPage<T>() {}

template class FECFEMainDataPage<BroadcastData>;
template class FECFEMainDataPage<BroadcastDataMsg>;
