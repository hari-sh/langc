#include <stdio.h>

#include "bitwise.h"

int main(void) {
    const uint32_t nums[] = {0x4, 1, 0x2, 1, 0x2};
    const uint32_t twoNums[] = {1, 0x2, 1, 0x3, 0x2, 0x5};
    const uint32_t missingNums[] = {0, 1, 0x3, 0x4};
    const uint32_t duplicateNums[] = {1, 0x3, 0x4, 0x2, 0x2};
    const uint32_t triplicateNums[] = {0x6, 1, 0x6, 0x6, 1, 1, 0x2A};
    const uint32_t pairNums[] = {0x3, 0xA, 0x5, 0x19, 0x2};
    const uint32_t subarrayNums[] = {0x8, 1, 0x2, 0xC};
    const uint32_t twoMissingNums[] = {1, 0x2, 0x4, 0x6};
    const uint32_t n = 0x35A5C33C;
    uint32_t a;
    uint32_t b;

    printf("0x%08X is even: %s\n", (unsigned int)n, isEven(n) ? "yes" : "no");
    printf("Bit 3 of 0x%08X: %u\n", (unsigned int)n, (unsigned int)getBit(n, 3));
    printf("0x%08X with bit 0 set: 0x%08X\n", (unsigned int)n, (unsigned int)setBit(n, 0));
    printf("0x%08X with bit 1 cleared: 0x%08X\n", (unsigned int)n, (unsigned int)clearBit(n, 1));
    printf("0x%08X with bit 1 toggled: 0x%08X\n", (unsigned int)n, (unsigned int)toggleBit(n, 1));
    printf("Bit 3 of 0x%08X is set: %s\n", (unsigned int)n, isBitSet(n, 3) ? "yes" : "no");
    printf("Bits 1 to 3 of 0x000000D6: 0x%08X\n", (unsigned int)extractBits(0xD6, 1, 3));
    printf("0xFFFF0000 replaced with 0x0000002A at bit 4 for 8 bits: 0x%08X\n", (unsigned int)replaceBits(0xFFFF0000, 0x2A, 4, 8));
    printf("0x%08X is a power of two: %s\n", (unsigned int)n, isPowerOfTwo(n) ? "yes" : "no");
    printf("0x%08X has %u set bits\n", (unsigned int)n, (unsigned int)countSetBits(n));
    printf("0x%08X has %u set bits without loop\n", (unsigned int)n, (unsigned int)countSetBitsWithoutLoop(n));
    printf("0x%08X has %u trailing zeros\n", (unsigned int)n, (unsigned int)countTrailingZeros(n));
    printf("Highest set bit in 0x%08X: 0x%08X\n", (unsigned int)n, (unsigned int)getHighestSetBit(n));
    printf("0x%08X has even parity: %s\n", (unsigned int)n, hasEvenParity(n) ? "yes" : "no");
    printf("0x%08X has alternating bits: %s\n", (unsigned int)n, hasAlternatingBits(n) ? "yes" : "no");
    printf("0x0000000A is a subset of 0x0000000E: %s\n", isSubset(0xA, 0xE) ? "yes" : "no");
    printf("Hamming distance between 0x0000002A and 0x0000002B: %u\n", (unsigned int)hammingDistance(0x2A, 0x2B));
    printf("0x00000040 is a power of four: %s\n", isPowerOfFour(0x40) ? "yes" : "no");
    printf("Unique in {0x4, 0x1, 0x2, 0x1, 0x2}: 0x%08X\n", (unsigned int)findUniqueNumber(nums, 5));
    printf("Missing from {0x0, 0x1, 0x3, 0x4}: 0x%08X\n", (unsigned int)findMissingNumber(missingNums, 4));
    printf("Duplicate in {0x1, 0x3, 0x4, 0x2, 0x2}: 0x%08X\n", (unsigned int)findDuplicateNumber(duplicateNums, 5));
    printf("Unique in {0x6, 0x1, 0x6, 0x6, 0x1, 0x1, 0x2A}: 0x%08X\n", (unsigned int)findUniqueAmongTriplicates(triplicateNums, 7));
    printf("Maximum XOR in {0x3, 0xA, 0x5, 0x19, 0x2}: 0x%08X\n", (unsigned int)maxXorPair(pairNums, 5));
    printf("Maximum subarray XOR in {0x8, 0x1, 0x2, 0xC}: 0x%08X\n", (unsigned int)maxXorSubarray(subarrayNums, 4));
    printf("Rightmost set bit in 0x%08X: 0x%08X\n", (unsigned int)n, (unsigned int)getRightmostSetBit(n));
    printf("0x0000002A and 0x0000002B differ by one bit: %s\n", isSingleBitDifferent(0x2A, 0x2B) ? "yes" : "no");
    findTwoUniqueNumbers(twoNums, 6, &a, &b);
    printf("Unique values in {0x1, 0x2, 0x1, 0x3, 0x2, 0x5}: 0x%08X, 0x%08X\n", (unsigned int)a, (unsigned int)b);
    findTwoMissingNumbers(twoMissingNums, 4, &a, &b);
    printf("Missing values from {0x1, 0x2, 0x4, 0x6}: 0x%08X, 0x%08X\n", (unsigned int)a, (unsigned int)b);
    printf("0x%08X with odd/even bits swapped: 0x%08X\n", (unsigned int)n, (unsigned int)swapOddEvenBits(n));
    printf("0x%08X with rightmost set bit cleared: 0x%08X\n", (unsigned int)n, (unsigned int)clearRightmostSetBit(n));
    printf("0x%08X with rightmost unset bit set: 0x%08X\n", (unsigned int)n, (unsigned int)setRightmostUnsetBit(n));
    printf("0x0000002B with trailing ones cleared: 0x%08X\n", (unsigned int)clearTrailingOnes(0x2B));
    printf("0x%08X is bit reversed to 0x%08X\n", (unsigned int)n, (unsigned int)reverseBits(n));
    printf("0x%08X is bit reversed without loop to 0x%08X\n", (unsigned int)n, (unsigned int)reverseBitsWithoutLoop(n));
    printf("0x12345678 is byte reversed to 0x%08X\n", (unsigned int)reverseBytes(0x12345678));
    printf("0x12345678 with nibbles swapped: 0x%08X\n", (unsigned int)swapNibbles(0x12345678));
    printf("0x0000002A plus 0x00000005: 0x%08X\n", (unsigned int)addWithoutPlus(0x2A, 0x5));
    printf("0x0000002A multiplied by 0x00000005: 0x%08X\n", (unsigned int)multiplyWithoutMultiply(0x2A, 0x5));
    printf("0x000000D2 divided by 0x00000005: 0x%08X\n", (unsigned int)divideWithoutDivide(0xD2, 0x5));
    printf("0x%08X rotated left by 3: 0x%08X\n", (unsigned int)n, (unsigned int)rotateLeft(n, 3));
    printf("0x%08X rotated right by 3: 0x%08X\n", (unsigned int)n, (unsigned int)rotateRight(n, 3));
    printf("Next power of two after 0x%08X: 0x%08X\n", (unsigned int)n, (unsigned int)nextPowerOfTwo(n));
    printf("Next value after 0x%08X with same set bits: 0x%08X\n", (unsigned int)n, (unsigned int)nextSameSetBits(n));
    printf("Previous value before 0x0000002C with same set bits: 0x%08X\n", (unsigned int)previousSameSetBits(0x2C));
    printf("XOR from 1 to 5: 0x%08X\n", (unsigned int)xorFromOneToN(5));
    printf("0x%08X converted to Gray code: 0x%08X\n", (unsigned int)n, (unsigned int)binaryToGray(n));
    printf("Gray code 0x0000003F converted to binary: 0x%08X\n", (unsigned int)grayToBinary(0x3F));
    printf("0x80000001 is a bit palindrome: %s\n", isBitPalindrome(0x80000001) ? "yes" : "no");
    printf("0x%08X has %u leading zeros\n", (unsigned int)n, (unsigned int)countLeadingZeros(n));
    printf("AND from 0x0000000C to 0x0000000F: 0x%08X\n", (unsigned int)bitwiseAndRange(0xC, 0xF));
    printf("Bits 1 to 3 reversed in 0x000000D6: 0x%08X\n", (unsigned int)reverseBitsInRange(0xD6, 1, 3));
    printf("Set bits from 1 to 5: %llu\n", (unsigned long long)countSetBitsFromOneToN(5));

    return 0;
}
