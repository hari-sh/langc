#include "bitwise.h"

uint32_t extractBits(uint32_t n, uint32_t start, uint32_t count) {
    uint32_t mask;

    if (start >= 32 || count > 32 - start) {
        return 0;
    }

    if (count == 0) {
        return 0;
    }

    if (count == 32) {
        return n;
    }

    mask = ((uint32_t)1 << count) - 1;

    return (n >> start) & mask;
}

uint32_t replaceBits(uint32_t n, uint32_t value, uint32_t start, uint32_t count) {
    uint32_t mask;

    if (start >= 32 || count > 32 - start || count == 0) {
        return n;
    }

    if (count == 32) {
        return value;
    }

    mask = ((uint32_t)1 << count) - 1;

    return (n & ~(mask << start)) | ((value & mask) << start);
}

uint32_t reverseBytes(uint32_t n) {
    const uint32_t mask = 0x00FF00FF;

    n = ((n >> 8) & mask) | ((n & mask) << 8);

    return (n >> 16) | (n << 16);
}

uint32_t swapNibbles(uint32_t n) {
    const uint32_t lowMask = 0x0F0F0F0F;
    const uint32_t highMask = 0xF0F0F0F0;

    return ((n & lowMask) << 4) | ((n & highMask) >> 4);
}
