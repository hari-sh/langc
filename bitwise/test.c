#include <assert.h>

#include "bitwise.h"

void testBitAccess(void) {
    assert(getBit(0x2A, 1) == 1);
    assert(getBit(0x2A, 3) == 1);
    assert(getBit(0x2A, 32) == 0);
    assert(setBit(0x2A, 0) == 0x2B);
    assert(clearBit(0x2A, 1) == 0x28);
    assert(toggleBit(0x2A, 1) == 0x28);
    assert(isBitSet(0x2A, 3));
    assert(!isBitSet(0x2A, 0));
    assert(extractBits(0xD6, 1, 3) == 0x3);
    assert(extractBits(0xD6, 31, 2) == 0);
    assert(replaceBits(0xFFFF0000, 0x2A, 4, 8) == 0xFFFF02A0);
    assert(replaceBits(0x2A, 0x5, 32, 1) == 0x2A);
    assert(reverseBitsInRange(0xD6, 1, 3) == 0xDC);
    assert(hasAlternatingBits(0x2A));
    assert(!hasAlternatingBits(0x3));
    assert(!hasAlternatingBits(0));
    assert(isSubset(0xA, 0xE));
    assert(!isSubset(0xA, 0x6));
}

void testBitCount(void) {
    assert(countSetBits(0) == 0);
    assert(countSetBits(0xFFFFFFFF) == 32);
    assert(countSetBitsWithoutLoop(0x2A) == 3);
    assert(countSetBitsWithoutLoop(0xFFFFFFFF) == 32);
    assert(countLeadingZeros(0) == 32);
    assert(countLeadingZeros(1) == 31);
    assert(countLeadingZeros(0x80000000) == 0);
    assert(countTrailingZeros(0) == 32);
    assert(countTrailingZeros(0x2A) == 1);
    assert(countTrailingZeros(0x20) == 5);
    assert(getHighestSetBit(0x2A) == 0x20);
    assert(getHighestSetBit(0) == 0);
    assert(!hasEvenParity(0x2A));
    assert(hasEvenParity(0x3));
    assert(hammingDistance(0x2A, 0x2B) == 1);
    assert(isPowerOfFour(0x40));
    assert(!isPowerOfFour(0x20));
    assert(bitwiseAndRange(0xC, 0xF) == 0xC);
    assert(countSetBitsFromOneToN(5) == 7);
}

void testBitTransform(void) {
    assert(swapOddEvenBits(0x2A) == 0x15);
    assert(reverseBits(0x2A) == 0x54000000);
    assert(reverseBitsWithoutLoop(0x2A) == 0x54000000);
    assert(reverseBytes(0x12345678) == 0x78563412);
    assert(swapNibbles(0x12345678) == 0x21436587);
    assert(clearRightmostSetBit(0x2A) == 0x28);
    assert(setRightmostUnsetBit(0x2A) == 0x2B);
    assert(setRightmostUnsetBit(0xFFFFFFFF) == 0xFFFFFFFF);
    assert(clearTrailingOnes(0x2B) == 0x28);
    assert(clearTrailingOnes(0xFFFFFFFF) == 0);
    assert(rotateLeft(0x2A, 3) == 0x150);
    assert(rotateRight(0x2A, 3) == 0x40000005);
    assert(rotateLeft(0x2A, 32) == 0x2A);
    assert(rotateRight(0x2A, 35) == 0x40000005);
}

void testBitMath(void) {
    assert(isEven(0x2A));
    assert(!isEven(0x2B));
    assert(isPowerOfTwo(1));
    assert(isPowerOfTwo(0x20));
    assert(!isPowerOfTwo(0));
    assert(addWithoutPlus(0x2A, 0x5) == 0x2F);
    assert(addWithoutPlus(0xFFFFFFFF, 1) == 0);
    assert(multiplyWithoutMultiply(0x2A, 0x5) == 0xD2);
    assert(multiplyWithoutMultiply(0xFFFFFFFF, 0x2) == 0xFFFFFFFE);
    assert(divideWithoutDivide(0xD2, 0x5) == 0x2A);
    assert(divideWithoutDivide(0xFFFFFFFF, 1) == 0xFFFFFFFF);
    assert(divideWithoutDivide(1, 0) == 0);
    assert(nextPowerOfTwo(0) == 1);
    assert(nextPowerOfTwo(0x2A) == 0x40);
    assert(nextPowerOfTwo(0x80000001) == 0);
    assert(nextSameSetBits(0x2A) == 0x2C);
    assert(nextSameSetBits(0) == 0);
    assert(nextSameSetBits(0x80000000) == 0);
    assert(previousSameSetBits(0x2C) == 0x2A);
    assert(previousSameSetBits(0x80000000) == 0x40000000);
}

void testBitXor(void) {
    const uint32_t nums[] = {0x4, 1, 0x2, 1, 0x2};
    const uint32_t twoNums[] = {1, 0x2, 1, 0x3, 0x2, 0x5};
    const uint32_t missingNums[] = {0, 1, 0x3, 0x4};
    const uint32_t duplicateNums[] = {1, 0x3, 0x4, 0x2, 0x2};
    const uint32_t triplicateNums[] = {0x6, 1, 0x6, 0x6, 1, 1, 0x2A};
    const uint32_t pairNums[] = {0x3, 0xA, 0x5, 0x19, 0x2};
    const uint32_t subarrayNums[] = {0x8, 1, 0x2, 0xC};
    const uint32_t twoMissingNums[] = {1, 0x2, 0x4, 0x6};
    uint32_t a;
    uint32_t b;

    assert(findUniqueNumber(nums, 5) == 0x4);
    assert(findMissingNumber(missingNums, 4) == 0x2);
    assert(findDuplicateNumber(duplicateNums, 5) == 0x2);
    assert(findUniqueAmongTriplicates(triplicateNums, 7) == 0x2A);
    assert(maxXorPair(pairNums, 5) == 0x1C);
    assert(maxXorSubarray(subarrayNums, 4) == 0xF);
    assert(getRightmostSetBit(0x2A) == 0x2);
    assert(getRightmostSetBit(0) == 0);
    assert(isSingleBitDifferent(0x2A, 0x2B));
    assert(!isSingleBitDifferent(0x2A, 0x2A));
    assert(xorFromOneToN(0) == 0);
    assert(xorFromOneToN(5) == 1);
    assert(binaryToGray(0x2A) == 0x3F);
    assert(grayToBinary(0x3F) == 0x2A);
    assert(isBitPalindrome(0x80000001));
    assert(!isBitPalindrome(0x2A));
    findTwoUniqueNumbers(twoNums, 6, &a, &b);
    assert((a == 0x3 && b == 0x5) || (a == 0x5 && b == 0x3));
    findTwoMissingNumbers(twoMissingNums, 4, &a, &b);
    assert((a == 0x3 && b == 0x5) || (a == 0x5 && b == 0x3));
}

int main(void) {
    testBitAccess();
    testBitCount();
    testBitTransform();
    testBitMath();
    testBitXor();

    return 0;
}
