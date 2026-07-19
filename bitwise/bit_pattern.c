#include "bitwise.h"

uint32_t countSetBitsWithoutLoop(uint32_t n) {
    const uint32_t mask1 = 0x55555555;
    const uint32_t mask2 = 0x33333333;
    const uint32_t mask4 = 0x0F0F0F0F;

    n -= (n >> 1) & mask1;
    n = (n & mask2) + ((n >> 2) & mask2);
    n = (n + (n >> 4)) & mask4;
    n += n >> 8;
    n += n >> 16;

    return n & 0x3F;
}

uint32_t hammingDistance(uint32_t a, uint32_t b) {
    return countSetBits(a ^ b);
}

int isPowerOfFour(uint32_t n) {
    return isPowerOfTwo(n) && (n & 0x55555555) != 0;
}

uint32_t binaryToGray(uint32_t n) {
    return n ^ (n >> 1);
}

uint32_t grayToBinary(uint32_t n) {
    uint32_t result = n;

    while (n >>= 1) {
        result ^= n;
    }

    return result;
}

uint32_t nextSameSetBits(uint32_t n) {
    uint32_t right;
    uint32_t next;
    uint32_t ones;

    if (n == 0) {
        return 0;
    }

    right = getRightmostSetBit(n);
    next = n + right;

    if (next == 0) {
        return 0;
    }

    ones = n ^ next;
    ones = divideWithoutDivide(ones >> 2, right);

    return next | ones;
}

int isBitPalindrome(uint32_t n) {
    return reverseBitsWithoutLoop(n) == n;
}
