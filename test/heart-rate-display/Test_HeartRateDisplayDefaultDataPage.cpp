#include "unity.h"
#include "Util/Testing.h"
#include "ANTPLUS.h"

#ifdef UNIT_TEST

uint8_t mockedInput[] = {0, 0x80, 0xFF, 0xFF, 0xFF, 0xAB, 0xCD, 0x12, 0x45};
HeartRateDefault *dp;

void test_datapage(void) {
    TEST_ASSERT_EQUAL_UINT8(0, dp->getDataPageNumber());
}

void test_pageChangeToggle(void) {
    TEST_ASSERT_EQUAL_UINT8(1, dp->getPageChangeToggle());
}

int main(int argc, char **argv) {
    BroadcastData bd;
    bd.setFrameData(mockedInput);
    dp = new HeartRateDefault(bd);
    // force data into buffer for testing purposes

    UNITY_BEGIN();
    RUN_TEST(test_datapage);
    RUN_TEST(test_pageChangeToggle);
    UNITY_END();

    return 0;
}

#endif // UNIT_TEST
