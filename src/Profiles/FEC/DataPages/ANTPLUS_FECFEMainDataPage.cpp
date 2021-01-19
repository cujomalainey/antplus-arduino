#include <Profiles/FEC/DataPages/ANTPLUS_FECFEMainDataPage.h>
#include <Profiles/FEC/ANTPLUS_FECPrivateDefines.h>

template<class T>
FECFEMainDataPage<T>::FECFEMainDataPage() :
    CoreDataPage<T>() {}

template class FECFEMainDataPage<BroadcastData>;
template class FECFEMainDataPage<BroadcastDataMsg>;
