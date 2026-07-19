#include "bitwise.h"

uint32_t countSetBits(uint32_t n) {
    uint32_t count = 0;

    while (n != 0) {
        n &= n - 1;
        ++count;
    }

    return count;
}

uint32_t countLeadingZeros(uint32_t n) {
    uint32_t count = 0;
    uint32_t i;

    for (i = 0; i < 32; ++i) {
        if (isBitSet(n, 31 - i)) {
            return count;
        }

        ++count;
    }

    return count;
}

uint32_t countTrailingZeros(uint32_t n) {
    uint32_t count = 0;

    if (n == 0) {
        return 32;
    }

    while (!isBitSet(n, count)) {
        ++count;
    }

    return count;
}

uint32_t getHighestSetBit(uint32_t n) {
    uint32_t pos;

    if (n == 0) {
        return 0;
    }

    pos = 31 - countLeadingZeros(n);

    return (uint32_t)1 << pos;
}

int hasEvenParity(uint32_t n) {
    return isEven(countSetBits(n));
}
