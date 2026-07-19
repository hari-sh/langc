#include "bitwise.h"

uint32_t swapOddEvenBits(uint32_t n) {
    const uint32_t evenMask = 0x55555555;
    const uint32_t oddMask = 0xAAAAAAAA;

    return ((n & evenMask) << 1) | ((n & oddMask) >> 1);
}

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    uint32_t i;

    for (i = 0; i < 32; ++i) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }

    return result;
}

uint32_t reverseBitsWithoutLoop(uint32_t n) {
    const uint32_t mask1 = 0x55555555;
    const uint32_t mask2 = 0x33333333;
    const uint32_t mask4 = 0x0F0F0F0F;
    const uint32_t mask8 = 0x00FF00FF;

    n = ((n >> 1) & mask1) | ((n & mask1) << 1);
    n = ((n >> 2) & mask2) | ((n & mask2) << 2);
    n = ((n >> 4) & mask4) | ((n & mask4) << 4);
    n = ((n >> 8) & mask8) | ((n & mask8) << 8);

    return (n >> 16) | (n << 16);
}

uint32_t clearRightmostSetBit(uint32_t n) {
    return n & (n - 1);
}

uint32_t setRightmostUnsetBit(uint32_t n) {
    if (n == 0xFFFFFFFF) {
        return n;
    }

    return n | (n + 1);
}

uint32_t clearTrailingOnes(uint32_t n) {
    return n & (n + 1);
}

uint32_t rotateLeft(uint32_t n, uint32_t pos) {
    pos %= 32;

    if (pos == 0) {
        return n;
    }

    return (n << pos) | (n >> (32 - pos));
}

uint32_t rotateRight(uint32_t n, uint32_t pos) {
    pos %= 32;

    if (pos == 0) {
        return n;
    }

    return (n >> pos) | (n << (32 - pos));
}
