#include "bitwise.h"

int isEven(uint32_t n) {
    return (n & 1) == 0;
}

int isPowerOfTwo(uint32_t n) {
    return n != 0 && (n & (n - 1)) == 0;
}

uint32_t addWithoutPlus(uint32_t a, uint32_t b) {
    uint32_t carry;

    while (b != 0) {
        carry = (a & b) << 1;
        a ^= b;
        b = carry;
    }

    return a;
}

uint32_t multiplyWithoutMultiply(uint32_t a, uint32_t b) {
    uint32_t result = 0;

    while (b != 0) {
        if ((b & 1) != 0) {
            result = addWithoutPlus(result, a);
        }

        a <<= 1;
        b >>= 1;
    }

    return result;
}

uint32_t divideWithoutDivide(uint32_t a, uint32_t b) {
    uint32_t i;
    uint32_t pos;
    uint32_t result = 0;

    if (b == 0) {
        return 0;
    }

    for (i = 32; i > 0; --i) {
        pos = i - 1;

        if ((a >> pos) >= b) {
            a -= b << pos;
            result |= (uint32_t)1 << pos;
        }
    }

    return result;
}

uint32_t nextPowerOfTwo(uint32_t n) {
    if (n == 0 || isPowerOfTwo(n)) {
        return n == 0 ? 1 : n;
    }

    if (n > 0x80000000) {
        return 0;
    }

    --n;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return n + 1;
}
