#include "unity.h"
#include "Util/Testing.h"
#include "ANTPLUS.h"
#include "BaseDataPageTests.h"

#ifdef UNIT_TEST

static uint8_t mockedInput8bit[] = {0, 0, 0, 0, 0, 0, 0, 0, 0xFE};
static uint8_t mockedInput16bit[] = {0, 0xAB, 0xCD, 0, 0, 0, 0, 0, 0};
static uint8_t mockedInput24bit[] = {0, 0, 0, 0, 0x9A, 0xBC, 0xDE, 0, 0};
static uint8_t mockedInput32bit[] = {0, 0x12, 0x34, 0x56, 0x78, 0, 0, 0, 0};
static BroadcastData bd;
static BaseDataPage<BroadcastData> *dp;

static void test_8BitGet(void) {
    uint8_t temp;
    dp->setFrameData(mockedInput8bit);
    temp = dp->get8BitValue(7);
    TEST_ASSERT_EQUAL_UINT8(0xFE, temp);
    temp = dp->get8BitValue(7, 0xA0);
    TEST_ASSERT_EQUAL_UINT8(0xA0, temp);
    temp = dp->get8BitValue(7, 0xA0, 4);
    TEST_ASSERT_EQUAL_UINT8(0xA, temp);
    temp = dp->get8BitValue(6);
    TEST_ASSERT_EQUAL_UINT8(0, temp);
}

static void test_16BitGet(void) {
    uint16_t temp;
    dp->setFrameData(mockedInput16bit);
    temp = dp->get16BitValue(0, 1);
    TEST_ASSERT_EQUAL_UINT16(0xCDAB, temp);
    temp = dp->get16BitValue(1, 0, 0xA0C0);
    TEST_ASSERT_EQUAL_UINT16(0xA0C0, temp);
    temp = dp->get16BitValue(1, 0, 0x0FF0, 4);
    TEST_ASSERT_EQUAL_UINT16(0xBC, temp);
    temp = dp->get16BitValue(6, 7);
    TEST_ASSERT_EQUAL_UINT16(0, temp);
}

static void test_24BitGet(void) {
    uint32_t temp;
    dp->setFrameData(mockedInput24bit);
    temp = dp->get24BitValue(3, 5);
    TEST_ASSERT_EQUAL_UINT32(0xDEBC9A, temp);
    temp = dp->get24BitValue(5, 3, 0x0FFFFF);
    TEST_ASSERT_EQUAL_UINT32(0xABCDE, temp);
    temp = dp->get24BitValue(5, 3, 0x0FFFF0, 4);
    TEST_ASSERT_EQUAL_UINT32(0xABCD, temp);
    temp = dp->get24BitValue(0, 2);
    TEST_ASSERT_EQUAL_UINT32(0, temp);
}

static void test_32BitGet(void) {
    uint32_t temp;
    dp->setFrameData(mockedInput32bit);
    temp = dp->get32BitValue(0, 3);
    TEST_ASSERT_EQUAL_UINT32(0x78563412, temp);
    temp = dp->get32BitValue(3, 0, 0x0FFFFFFF);
    TEST_ASSERT_EQUAL_UINT32(0x02345678, temp);
    temp = dp->get32BitValue(3, 0, 0x0FFFFFF0, 4);
    TEST_ASSERT_EQUAL_UINT32(0x0234567, temp);
    temp = dp->get32BitValue(4, 7);
    TEST_ASSERT_EQUAL_UINT32(0, temp);
}

void runBaseDataPageTests() {
    dp = new BaseDataPage<BroadcastData>(bd);
    RUN_TEST(test_8BitGet);
    RUN_TEST(test_16BitGet);
    RUN_TEST(test_24BitGet);
    RUN_TEST(test_32BitGet);
}

#endif // UNIT_TEST
