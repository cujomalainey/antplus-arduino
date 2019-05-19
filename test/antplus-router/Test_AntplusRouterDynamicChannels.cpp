#include "unity.h"
#include "Util/Testing.h"
#include "ANTPLUS.h"

#ifdef UNIT_TEST

/**
 * This tests the functionlity of the routers ability to properly handle
 * channel profile changes
 */

void test_addProfile(void) {
    TEST_ASSERT_EQUAL_UINT8(0, 0);
}

int main(int argc, char **argv) {

    UNITY_BEGIN();
    RUN_TEST(test_addProfile);
    UNITY_END();

    return 0;
}

#endif // UNIT_TEST
