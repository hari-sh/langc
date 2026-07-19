#include "bitwise.h"

uint32_t previousSameSetBits(uint32_t n) {
    uint32_t countOnes = 0;
    uint32_t countZeros = 0;
    uint32_t temp = n;
    uint32_t pos;
    uint32_t mask;

    if (n == 0) {
        return 0;
    }

    while ((temp & 1) == 1) {
        ++countOnes;
        temp >>= 1;
    }

    if (temp == 0) {
        return 0;
    }

    while ((temp & 1) == 0) {
        ++countZeros;
        temp >>= 1;
    }

    pos = countZeros + countOnes;

    if (pos == 31) {
        n = 0;
    } else {
        n &= ~(uint32_t)0 << (pos + 1);
    }

    mask = ((uint32_t)1 << (countOnes + 1)) - 1;

    return n | (mask << (countZeros - 1));
}

uint32_t bitwiseAndRange(uint32_t left, uint32_t right) {
    uint32_t shift = 0;

    while (left < right) {
        left >>= 1;
        right >>= 1;
        ++shift;
    }

    return left << shift;
}

uint64_t countSetBitsFromOneToN(uint32_t n) {
    uint64_t total = 0;
    uint64_t limit = (uint64_t)n + 1;
    uint64_t cycle;
    uint64_t rem;
    uint32_t i;

    for (i = 0; i < 32; ++i) {
        cycle = (uint64_t)1 << (i + 1);
        total += (limit / cycle) * (cycle >> 1);
        rem = limit % cycle;

        if (rem > (cycle >> 1)) {
            total += rem - (cycle >> 1);
        }
    }

    return total;
}

uint32_t reverseBitsInRange(uint32_t n, uint32_t start, uint32_t count) {
    uint32_t bits;
    uint32_t result = 0;
    uint32_t i;

    if (start >= 32 || count > 32 - start) {
        return n;
    }

    bits = extractBits(n, start, count);

    for (i = 0; i < count; ++i) {
        result = (result << 1) | (bits & 1);
        bits >>= 1;
    }

    return replaceBits(n, result, start, count);
}
