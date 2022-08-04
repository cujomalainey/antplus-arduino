#include "unity.h"
#include "Util/Testing.h"
#include "ANTPLUS.h"

#ifdef UNIT_TEST

static uint8_t mockedInput8bit[] = {0, 0, 0, 0, 0, 0, 0, 0xFE};
static uint8_t mockedInput16bit[] = {0xAB, 0xCD, 0, 0, 0, 0, 0, 0};
static uint8_t mockedInput24bit[] = {0, 0, 0, 0x9A, 0xBC, 0xDE, 0, 0};
static uint8_t mockedInput32bit[] = {0x12, 0x34, 0x56, 0x78, 0, 0, 0, 0};
static BaseDataPageMsg<BroadcastDataMsg> *dp;

static void test_8BitGet(void) {
    uint8_t temp;
    dp->setDataBuffer(mockedInput8bit);
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
    dp->setDataBuffer(mockedInput16bit);
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
    dp->setDataBuffer(mockedInput24bit);
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
    dp->setDataBuffer(mockedInput32bit);
    temp = dp->get32BitValue(0, 3);
    TEST_ASSERT_EQUAL_UINT32(0x78563412, temp);
    temp = dp->get32BitValue(3, 0, 0x0FFFFFFF);
    TEST_ASSERT_EQUAL_UINT32(0x02345678, temp);
    temp = dp->get32BitValue(3, 0, 0x0FFFFFF0, 4);
    TEST_ASSERT_EQUAL_UINT32(0x0234567, temp);
    temp = dp->get32BitValue(4, 7);
    TEST_ASSERT_EQUAL_UINT32(0, temp);
}

static void test_8BitSet(void) {
    dp->setDataBuffer(mockedInput8bit);
    memset(mockedInput8bit, 0, sizeof(mockedInput8bit));
    dp->set8BitValue(0xCD, 7);
    TEST_ASSERT_EQUAL_UINT8(0xCD, mockedInput8bit[7]);
    dp->set8BitValue(0x7, 6, 0x3);
    TEST_ASSERT_EQUAL_UINT8(0x3, mockedInput8bit[6]);
    dp->set8BitValue(8, 6, 0x80, 4);
    TEST_ASSERT_EQUAL_UINT8(0x83, mockedInput8bit[6]);
    dp->set8BitValue(0xF, 5, 0xF0, 4);
    TEST_ASSERT_EQUAL_UINT8(0xF0, mockedInput8bit[5]);
    dp->set8BitValue(0xC, 5, 0xC);
    TEST_ASSERT_EQUAL_UINT8(0xFC, mockedInput8bit[5]);
}

static void test_16BitSet(void) {
    dp->setDataBuffer(mockedInput16bit);
    memset(mockedInput16bit, 0, sizeof(mockedInput16bit));
    dp->set16BitValue(0xABCD, 7, 6);
    TEST_ASSERT_EQUAL_UINT8(0xCD, mockedInput16bit[7]);
    TEST_ASSERT_EQUAL_UINT8(0xAB, mockedInput16bit[6]);
    dp->set16BitValue(0x1, 6, 7, 0xFFF);
    TEST_ASSERT_EQUAL_UINT8(0xC0, mockedInput16bit[7]);
    TEST_ASSERT_EQUAL_UINT8(0x01, mockedInput16bit[6]);
    dp->set16BitValue(0xAB, 6, 7, 0x0FF0, 4);
    TEST_ASSERT_EQUAL_UINT8(0xCA, mockedInput16bit[7]);
    TEST_ASSERT_EQUAL_UINT8(0xB1, mockedInput16bit[6]);
}

static void test_24BitSet(void) {
    dp->setDataBuffer(mockedInput24bit);
    memset(mockedInput24bit, 0, sizeof(mockedInput24bit));
    dp->set24BitValue(0xABCDEF, 7, 5);
    TEST_ASSERT_EQUAL_UINT8(0xEF, mockedInput24bit[7]);
    TEST_ASSERT_EQUAL_UINT8(0xCD, mockedInput24bit[6]);
    TEST_ASSERT_EQUAL_UINT8(0xAB, mockedInput24bit[5]);
    dp->set24BitValue(0x7, 5, 7, 0x0FFFFF);
    TEST_ASSERT_EQUAL_UINT8(0xE0, mockedInput24bit[7]);
    TEST_ASSERT_EQUAL_UINT8(0x00, mockedInput24bit[6]);
    TEST_ASSERT_EQUAL_UINT8(0x07, mockedInput24bit[5]);
    dp->set24BitValue(0x1234, 5, 7, 0x0FFFF0, 4);
    TEST_ASSERT_EQUAL_UINT8(0xE1, mockedInput24bit[7]);
    TEST_ASSERT_EQUAL_UINT8(0x23, mockedInput24bit[6]);
    TEST_ASSERT_EQUAL_UINT8(0x47, mockedInput24bit[5]);
}

static void test_32BitSet(void) {
    dp->setDataBuffer(mockedInput32bit);
    memset(mockedInput32bit, 0, sizeof(mockedInput32bit));
    dp->set32BitValue(0x89ABCDEF, 7, 4);
    TEST_ASSERT_EQUAL_UINT8(0xEF, mockedInput32bit[7]);
    TEST_ASSERT_EQUAL_UINT8(0xCD, mockedInput32bit[6]);
    TEST_ASSERT_EQUAL_UINT8(0xAB, mockedInput32bit[5]);
    TEST_ASSERT_EQUAL_UINT8(0x89, mockedInput32bit[4]);
    dp->set32BitValue(0x7, 4, 7, 0x0FFFFFFF);
    TEST_ASSERT_EQUAL_UINT8(0xE0, mockedInput32bit[7]);
    TEST_ASSERT_EQUAL_UINT8(0x00, mockedInput32bit[6]);
    TEST_ASSERT_EQUAL_UINT8(0x00, mockedInput32bit[5]);
    TEST_ASSERT_EQUAL_UINT8(0x07, mockedInput32bit[4]);
    dp->set32BitValue(0xABCDEF, 4, 7, 0x0FFFFFF0, 4);
    TEST_ASSERT_EQUAL_UINT8(0xEA, mockedInput32bit[7]);
    TEST_ASSERT_EQUAL_UINT8(0xBC, mockedInput32bit[6]);
    TEST_ASSERT_EQUAL_UINT8(0xDE, mockedInput32bit[5]);
    TEST_ASSERT_EQUAL_UINT8(0xF7, mockedInput32bit[4]);
}

void runBaseDataPageMsgTests() {
    dp = new BaseDataPageMsg<BroadcastDataMsg>();
    RUN_TEST(test_8BitGet);
    RUN_TEST(test_16BitGet);
    RUN_TEST(test_24BitGet);
    RUN_TEST(test_32BitGet);
    RUN_TEST(test_8BitSet);
    RUN_TEST(test_16BitSet);
    RUN_TEST(test_24BitSet);
    RUN_TEST(test_32BitSet);
}

#endif // UNIT_TEST
