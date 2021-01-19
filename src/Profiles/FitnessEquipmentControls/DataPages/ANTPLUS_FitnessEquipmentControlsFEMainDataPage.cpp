#include <Profiles/FitnessEquipmentControls/DataPages/ANTPLUS_FitnessEquipmentControlsFEMainDataPage.h>
#include <Profiles/FitnessEquipmentControls/ANTPLUS_FitnessEquipmentControlsPrivateDefines.h>

// TODO update name
template<class T>
FECFEMainDataPage<T>::FECFEMainDataPage() :
    CoreDataPage<T>() {}

template class FECFEMainDataPage<BroadcastData>;
template class FECFEMainDataPage<BroadcastDataMsg>;
