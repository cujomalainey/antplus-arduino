#include "unity.h"
#include "Util/Testing.h"

#ifdef UNIT_TEST

#error "yo"
const uint8_t mockedInput[] = {};
BroadcastData bd;
HeartRateDefaultDataPage dp;

void test_datapage(void) {
    TEST_ASSERT_EQUAL_UINT8(0, dp.getDataPage());
}

int main(int argc, char **argv) {
    bd = BroadcastData();
    // force data into buffer for testing purposes
    memcpy(bd.getData(), mockedInput, sizeof(mockedInput));
    dp = HeartRateDefaultDataPage(bd);

    UNITY_BEGIN();
    RUN_TEST(test_datapage);
    UNITY_END();
}

#endif // UNIT_TEST
