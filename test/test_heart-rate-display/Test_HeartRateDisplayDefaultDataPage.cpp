#include "unity.h"
#include "Util/Testing.h"
#include "ANTPLUS.h"

#ifdef UNIT_TEST

/**
 * This tests the functionlity of the base page since
 * it has no specific implementation details
 */

uint8_t mockedInput[] = {0, 0x80, 0xFF, 0xFF, 0xFF, 0xAB, 0xCD, 0x12, 0x45};
HeartRateDefault *dp;

void test_datapage(void) {
    TEST_ASSERT_EQUAL_UINT8(0, dp->getDataPageNumber());
}

void test_pageChangeToggle(void) {
    TEST_ASSERT_EQUAL_UINT8(1, dp->getPageChangeToggle());
}

void test_heartBeatEventTime(void) {
    TEST_ASSERT_EQUAL_UINT16(0xCDAB, dp->getHeartBeatEventTime());
}

void test_heartBeatCount(void) {
    TEST_ASSERT_EQUAL_UINT8(0x12, dp->getHeartBeatCount());
}

void test_computerHeartRate(void) {
    TEST_ASSERT_EQUAL_UINT8(0x45, dp->getComputedHeartRate());
}

int main(int argc, char **argv) {
    BroadcastData bd;
    bd.setFrameData(mockedInput);
    dp = new HeartRateDefault(bd);
    // force data into buffer for testing purposes

    UNITY_BEGIN();
    RUN_TEST(test_datapage);
    RUN_TEST(test_pageChangeToggle);
    RUN_TEST(test_heartBeatEventTime);
    RUN_TEST(test_heartBeatCount);
    RUN_TEST(test_computerHeartRate);
    UNITY_END();

    return 0;
}

#endif // UNIT_TEST
