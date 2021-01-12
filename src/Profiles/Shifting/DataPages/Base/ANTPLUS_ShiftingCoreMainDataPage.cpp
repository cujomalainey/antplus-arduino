#include <Profiles/Shifting/DataPages/Base/ANTPLUS_ShiftingCoreMainDataPage.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>

template<class T>
ShiftingCoreMainDataPage<T>::ShiftingCoreMainDataPage() : CoreDataPage<T>() {
}

template<class T>
uint8_t ShiftingCoreMainDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(ANTPLUS_SHIFTING_DATAPAGEBASE_DATAPAGE_BYTE);
}

template class ShiftingCoreMainDataPage<BroadcastData>;
template class ShiftingCoreMainDataPage<BroadcastDataMsg>;
