#include "bitwise.h"

uint32_t getBit(uint32_t n, uint32_t pos) {
    if (pos >= 32) {
        return 0;
    }

    return (n >> pos) & 1;
}

uint32_t setBit(uint32_t n, uint32_t pos) {
    if (pos >= 32) {
        return n;
    }

    return n | ((uint32_t)1 << pos);
}

uint32_t clearBit(uint32_t n, uint32_t pos) {
    if (pos >= 32) {
        return n;
    }

    return n & ~((uint32_t)1 << pos);
}

uint32_t toggleBit(uint32_t n, uint32_t pos) {
    if (pos >= 32) {
        return n;
    }

    return n ^ ((uint32_t)1 << pos);
}

int isBitSet(uint32_t n, uint32_t pos) {
    return getBit(n, pos) != 0;
}

int hasAlternatingBits(uint32_t n) {
    uint32_t x;

    if (n == 0) {
        return 0;
    }

    x = n ^ (n >> 1);

    return (x & (x + 1)) == 0;
}

int isSubset(uint32_t a, uint32_t b) {
    return (a & b) == a;
}
