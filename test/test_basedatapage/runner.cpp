#include "unity.h"
#include "Util/Testing.h"
#include "ANTPLUS.h"
#include "BaseDataPageTests.h"

#ifdef UNIT_TEST


int main(int argc, char **argv) {

    UNITY_BEGIN();
    runBaseDataPageTests();
    runBaseDataPageMsgTests();
    UNITY_END();

    return 0;
}

#endif // UNIT_TEST
